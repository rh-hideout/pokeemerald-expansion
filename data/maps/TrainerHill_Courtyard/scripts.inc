TrainerHill_Courtyard_MapScripts::
map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Courtyard_OnTransition
	.byte 0

TrainerHill_Courtyard_OnTransition::
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	end

TrainerHill_Courtyard_EventScript_BattleTowerSign::
	lock
	msgbox BattleTowerOutsideSignText, MSGBOX_SIGN	
	closemessage	
	release
	end

TrainerHill_Courtyard_EventScript_Tent_Factory::
	lock
	msgbox BattleTower_Battle_Tent_Text_Factory, MSGBOX_SIGN	
	closemessage	
	release
	end

TrainerHill_Courtyard_EventScript_Tent_Palace::
	lock
	msgbox BattleTower_Battle_Tent_Text_Palace, MSGBOX_SIGN	
	closemessage	
	release
	end

TrainerHill_Courtyard_EventScript_Tent_Arena::
	lock
	msgbox BattleTower_Battle_Tent_Text_Arena, MSGBOX_SIGN	
	closemessage	
	release
	end
	
TrainerHill_Courtyard_EventScript_Engineer::
	lock
	faceplayer
	msgbox BattleTowerOutsideText_Closed, MSGBOX_DEFAULT
	closemessage
	release
	end

TrainerHill_Courtyard_EventScript_Youngster::
	lock
	faceplayer
	msgbox BattleTowerOutsideYoungsterText, MSGBOX_DEFAULT
	closemessage
	release
	end

TrainerHill_Courtyard_EventScript_Beauty::
	lock
	faceplayer
	msgbox BattleTowerOutsideBeautyText, MSGBOX_DEFAULT
	closemessage
	release
	end

TrainerHill_Courtyard_EventScript_Sailor::
	lock
	faceplayer
	msgbox BattleTowerOutsideSailorText, MSGBOX_DEFAULT
	closemessage
	release
	end

BattleTowerOutsideYoungsterText:
	.string "Wow, the TRAINER HILL is huge!\p"
	.string "There must be many kinds of\n"
	.string "POKéMON in there!$"

BattleTowerOutsideBeautyText:
	.string "In the BATTLE TENTS, you can\n"
	.string "use only three POKéMON.\p"
	.string "It's so hard to decide which\n"
	.string "three should go into battle…$"

BattleTowerOutsideSailorText:
	.string "Hehehe, I snuck out from work.\p"
	.string "I can't bail out until I've won!\p"
	.string "I have to win it all. That I must!$"

BattleTowerOutsideSignText:
	.string "{UP_ARROW} TRAINER HILL ENTRANCE\p"
	.string "“Scale the heights, you hot-blooded\n"
	.string "TRAINERS!”\p"
	.string "{RIGHT_ARROW} BATTLE TENTS.$"

BattleTower_Battle_Tent_Text_Factory:
	.string "BATTLE TENT: FACTORY\n"
	.string "“Find it! The ultimate POKéMON!”$"

BattleTower_Battle_Tent_Text_Palace:
	.string "BATTLE TENT: PALACE\n"
	.string "“Feast Your Eyes on Battles!”$"

BattleTower_Battle_Tent_Text_Arena:
	.string "BATTLE TENT: ARENA\n"
	.string "“May the Greatest Teams Gather!”$"

BattleTowerOutsideText_Closed:
	.string "The TRAINER HILL is currently\n"
	.string "closed for repairs.$"


TrainerHill_Courtyard_EventScript_LeftMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, TrainerHill_Courtyard_EventScript_AlreadyMetLeftTutor
	msgbox TrainerHill_Courtyard_Text_LeftTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto TrainerHill_Courtyard_EventScript_ChooseLeftTutorMove
	end

TrainerHill_Courtyard_EventScript_AlreadyMetLeftTutor::
	msgbox TrainerHill_Courtyard_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
	goto TrainerHill_Courtyard_EventScript_ChooseLeftTutorMove
	end

TrainerHill_Courtyard_EventScript_ChooseLeftTutorMove::
	message TrainerHill_Courtyard_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_EventScript_Softboiled
	case 1, TrainerHill_Courtyard_EventScript_SeismicToss
	case 2, TrainerHill_Courtyard_EventScript_DreamEater
	case 3, TrainerHill_Courtyard_EventScript_MegaPunch
	case 4, TrainerHill_Courtyard_EventScript_MegaKick
	case 5, TrainerHill_Courtyard_EventScript_BodySlam
	case 6, TrainerHill_Courtyard_EventScript_RockSlide
	case 7, TrainerHill_Courtyard_EventScript_Counter
	case 8, TrainerHill_Courtyard_EventScript_ThunderWave
	case 9, TrainerHill_Courtyard_EventScript_SwordsDance
	case 10, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	end

TrainerHill_Courtyard_EventScript_ChooseNewLeftTutorMove::
	message TrainerHill_Courtyard_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_EventScript_Softboiled
	case 1, TrainerHill_Courtyard_EventScript_SeismicToss
	case 2, TrainerHill_Courtyard_EventScript_DreamEater
	case 3, TrainerHill_Courtyard_EventScript_MegaPunch
	case 4, TrainerHill_Courtyard_EventScript_MegaKick
	case 5, TrainerHill_Courtyard_EventScript_BodySlam
	case 6, TrainerHill_Courtyard_EventScript_RockSlide
	case 7, TrainerHill_Courtyard_EventScript_Counter
	case 8, TrainerHill_Courtyard_EventScript_ThunderWave
	case 9, TrainerHill_Courtyard_EventScript_SwordsDance
	case 10, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	end

TrainerHill_Courtyard_EventScript_Softboiled::
	setvar VAR_0x8008, 16
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_SeismicToss::
	setvar VAR_0x8008, 24
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_DreamEater::
	setvar VAR_0x8008, 24
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_MegaPunch::
	setvar VAR_0x8008, 24
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_MegaKick::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_BodySlam::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_RockSlide::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_Counter::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_ThunderWave::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_SwordsDance::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_RightMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, TrainerHill_Courtyard_EventScript_AlreadyMetRightTutor
	msgbox TrainerHill_Courtyard_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto TrainerHill_Courtyard_EventScript_ChooseRightTutorMove
	end

TrainerHill_Courtyard_EventScript_AlreadyMetRightTutor::
	msgbox TrainerHill_Courtyard_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto TrainerHill_Courtyard_EventScript_ChooseRightTutorMove
	end

TrainerHill_Courtyard_EventScript_ChooseRightTutorMove::
	message TrainerHill_Courtyard_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_EventScript_DefenseCurl
	case 1, TrainerHill_Courtyard_EventScript_Snore
	case 2, TrainerHill_Courtyard_EventScript_MudSlap
	case 3, TrainerHill_Courtyard_EventScript_Swift
	case 4, TrainerHill_Courtyard_EventScript_IcyWind
	case 5, TrainerHill_Courtyard_EventScript_Endure
	case 6, TrainerHill_Courtyard_EventScript_PsychUp
	case 7, TrainerHill_Courtyard_EventScript_IcePunch
	case 8, TrainerHill_Courtyard_EventScript_ThunderPunch
	case 9, TrainerHill_Courtyard_EventScript_FirePunch
	case 10, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	end

TrainerHill_Courtyard_EventScript_ChooseNewRightTutorMove::
	message TrainerHill_Courtyard_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_EventScript_DefenseCurl
	case 1, TrainerHill_Courtyard_EventScript_Snore
	case 2, TrainerHill_Courtyard_EventScript_MudSlap
	case 3, TrainerHill_Courtyard_EventScript_Swift
	case 4, TrainerHill_Courtyard_EventScript_IcyWind
	case 5, TrainerHill_Courtyard_EventScript_Endure
	case 6, TrainerHill_Courtyard_EventScript_PsychUp
	case 7, TrainerHill_Courtyard_EventScript_IcePunch
	case 8, TrainerHill_Courtyard_EventScript_ThunderPunch
	case 9, TrainerHill_Courtyard_EventScript_FirePunch
	case 10, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	end

TrainerHill_Courtyard_EventScript_DefenseCurl::
	setvar VAR_0x8008, 16
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_Snore::
	setvar VAR_0x8008, 24
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_MudSlap::
	setvar VAR_0x8008, 24
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_Swift::
	setvar VAR_0x8008, 24
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_IcyWind::
	setvar VAR_0x8008, 24
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_Endure::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_PsychUp::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_IcePunch::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_ThunderPunch::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_FirePunch::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_ElementalMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_3
	goto_if_set FLAG_MET_FRONTIER_ELEMENTAL_MOVE_TUTOR, TrainerHill_Courtyard_EventScript_AlreadyMetElementalTutor
	msgbox TrainerHill_Courtyard_Text_ElementalTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_ELEMENTAL_MOVE_TUTOR
	goto TrainerHill_Courtyard_EventScript_ChooseElementalTutorMove
	end

TrainerHill_Courtyard_EventScript_AlreadyMetElementalTutor::
	msgbox TrainerHill_Courtyard_Text_ElementalTutorWelcomeBack, MSGBOX_DEFAULT
	goto TrainerHill_Courtyard_EventScript_ChooseElementalTutorMove
	end

TrainerHill_Courtyard_EventScript_ChooseElementalTutorMove::
	message TrainerHill_Courtyard_Text_TeachWhichMoveElemental
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 2
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_3
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_EventScript_FrenzyPlant
	case 1, TrainerHill_Courtyard_EventScript_BlastBurn
	case 2, TrainerHill_Courtyard_EventScript_HydroCannon
	case 3, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	end

TrainerHill_Courtyard_EventScript_ChooseNewElementalTutorMove::
	message TrainerHill_Courtyard_Text_TeachWhichMoveElemental
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 2
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_3
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_EventScript_FrenzyPlant
	case 1, TrainerHill_Courtyard_EventScript_BlastBurn
	case 2, TrainerHill_Courtyard_EventScript_HydroCannon
	case 3, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	end

TrainerHill_Courtyard_EventScript_FrenzyPlant::
	setvar VAR_0x8008, 64
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_BlastBurn::
	setvar VAR_0x8008, 64
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_HydroCannon::
	setvar VAR_0x8008, 64
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox TrainerHill_Courtyard_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

TrainerHill_Courtyard_EventScript_CancelChooseMon::
	msgbox TrainerHill_Courtyard_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_FRONTIER_TUTOR_SELECTION is the move selection
@ VAR_TEMP_FRONTIER_TUTOR_ID is which move tutor was spoken to
TrainerHill_Courtyard_EventScript_ConfirmMoveSelection::
	copyvar VAR_0x8004, VAR_TEMP_FRONTIER_TUTOR_SELECTION
	copyvar VAR_0x8005, VAR_TEMP_FRONTIER_TUTOR_ID
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	copyvar VAR_0x8004, VAR_TEMP_C
	msgbox TrainerHill_Courtyard_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_EventScript_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, TrainerHill_Courtyard_EventScript_TeachTutorMove
	msgbox TrainerHill_Courtyard_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto TrainerHill_Courtyard_EventScript_ChooseNewMove
	end

TrainerHill_Courtyard_EventScript_TeachTutorMove::
	msgbox TrainerHill_Courtyard_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	special GetBattleFrontierTutorMoveIndex
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Courtyard_EventScript_CancelChooseMon
	msgbox TrainerHill_Courtyard_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

TrainerHill_Courtyard_EventScript_ChooseNewMove::
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 0, TrainerHill_Courtyard_EventScript_ChooseNewLeftTutorMove
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 2, TrainerHill_Courtyard_EventScript_ChooseNewElementalTutorMove
	goto TrainerHill_Courtyard_EventScript_ChooseNewRightTutorMove
	end

TrainerHill_Courtyard_Text_LeftTutorIntro:
	.string "Buhahaha!\p"
	.string "You couldn't tell it from looking now,\n"
	.string "but I used to be one tough TRAINER.\p"
	.string "I had a reputation as the toughest\n"
	.string "BEAUTY around, I tell you!\p"
	.string "… … … … … …\p"
	.string "What is it now?\n"
	.string "You don't believe me.\p"
	.string "I'm not like that blowhard woman over\n"
	.string "there. I'm actually talented!\p"
	.string "Let me prove it to you.\n"
	.string "I can teach your POKéMON special and\l"
	.string "yet cute moves.\p"
	.string "But my lessons don't come free.\n"
	.string "How about paying for the moves I teach\l"
	.string "with a wee bit of Battle Points?$"

TrainerHill_Courtyard_Text_LeftTutorWelcomeBack:
	.string "Buhahaha!\p"
	.string "Are you back to learn special and\n"
	.string "yet cute POKéMON moves?$"

TrainerHill_Courtyard_Text_TeachWhichMove:
	.string "Fine, fine, look here!\n"
	.string "Which move should I teach?$"

TrainerHill_Courtyard_Text_MoveWillBeXBattlePoints:
	.string "The move {STR_VAR_1}, is it?\n"
	.string "That will be {STR_VAR_2} Battle Points, okay?$"

TrainerHill_Courtyard_Text_TeachMoveToWhichMon:
	.string "Fine, fine, now pick the POKéMON\n"
	.string "I should teach the move to.$"

TrainerHill_Courtyard_Text_HaventGotEnoughPoints:
	.string "What the…\n"
	.string "You haven't got enough Battle Points!$"

TrainerHill_Courtyard_Text_IllTakeBattlePoints:
	.string "Do you see how skilled I am now?\n"
	.string "I'll take your Battle Points, thanks!$"

TrainerHill_Courtyard_Text_YouDontWantTo:
	.string "What's that?\n"
	.string "You don't want to…\p"
	.string "If you want to see how skilled I am,\n"
	.string "you come see me anytime!$"

TrainerHill_Courtyard_Text_RightTutorIntro:
	.string "Ihihihi!\p"
	.string "I know it's hard to see now, but I used\n"
	.string "to be one fantastic TRAINER.\p"
	.string "I had a reputation as the most\n"
	.string "invincible SWIMMER around, I tell you!\p"
	.string "… … … … … …\p"
	.string "What's wrong?\n"
	.string "You don't believe me.\p"
	.string "I'm not like that buffoonish woman over\n"
	.string "there. I'm actually experienced!\p"
	.string "I can prove it to you.\n"
	.string "I can teach your POKéMON hard and\l"
	.string "yet pretty moves.\p"
	.string "But my lessons don't come free.\n"
	.string "How about paying for the moves I teach\l"
	.string "with a wee bit of Battle Points?$"

TrainerHill_Courtyard_Text_RightTutorWelcomeBack:
	.string "Ihihihi!\p"
	.string "Have you come to learn hard and\n"
	.string "yet pretty POKéMON moves?$"

TrainerHill_Courtyard_Text_ThinkLadiesDontGetAlong:
	.string "Those ladies, the way they bad-mouth\n"
	.string "each other, you probably think that\l"
	.string "they don't get along.\p"
	.string "But if that were true, they wouldn't\n"
	.string "stay out here together, would they?$"

TrainerHill_Courtyard_Text_LadiesWereStrongAndBeautiful:
	.string "When I was just a wee YOUNGSTER,\n"
	.string "those ladies were strong and beautiful.\p"
	.string "They were idols among us TRAINERS.\p"
	.string "Even now, age hasn't dulled their\n"
	.string "abilities.\p"
	.string "In fact, their POKéMON moves have\n"
	.string "grown even more polished.\p"
	.string "But… For some reason, I can't help\n"
	.string "but feel this…\p"
	.string "Time is so cruel…$"

TrainerHill_Courtyard_Text_SoftboiledDesc::
	.string "Recovers up to\n"
	.string "half the user's\n"
	.string "maximum HP.$"

TrainerHill_Courtyard_Text_SeismicTossDesc::
	.string "Inflicts damage\n"
	.string "identical to the\n"
	.string "user's level.$"

TrainerHill_Courtyard_Text_DreamEaterDesc::
	.string "Recovers half the\n"
	.string "damage inflicted\n"
	.string "on a sleeping foe.$"

TrainerHill_Courtyard_Text_MegaPunchDesc::
	.string "A strong punch\n"
	.string "thrown with\n"
	.string "incredible power.$"

TrainerHill_Courtyard_Text_MegaKickDesc::
	.string "An extremely\n"
	.string "powerful kick with\n"
	.string "intense force.$"

TrainerHill_Courtyard_Text_BodySlamDesc::
	.string "A full-body slam\n"
	.string "that may cause\n"
	.string "paralysis.$"

TrainerHill_Courtyard_Text_RockSlideDesc::
	.string "Large boulders\n"
	.string "are hurled. May\n"
	.string "cause flinching.$"

TrainerHill_Courtyard_Text_CounterDesc::
	.string "Retaliates any\n"
	.string "physical hit with\n"
	.string "double the power.$"

TrainerHill_Courtyard_Text_ThunderWaveDesc::
	.string "A weak jolt of\n"
	.string "electricity that\n"
	.string "paralyzes the foe.$"

TrainerHill_Courtyard_Text_SwordsDanceDesc::
	.string "A fighting dance\n"
	.string "that sharply\n"
	.string "raises ATTACK.$"

TrainerHill_Courtyard_Text_DefenseCurlDesc::
	.string "Curls up to con-\n"
	.string "ceal weak spots\n"
	.string "and raise DEFENSE.$"

TrainerHill_Courtyard_Text_SnoreDesc::
	.string "A loud attack\n"
	.string "that can be used\n"
	.string "only while asleep.$"

TrainerHill_Courtyard_Text_MudSlapDesc::
	.string "Hurls mud in the\n"
	.string "foe's face to re-\n"
	.string "duce its accuracy.$"

TrainerHill_Courtyard_Text_SwiftDesc::
	.string "Sprays star-\n"
	.string "shaped rays\n"
	.string "that never miss.$"

TrainerHill_Courtyard_Text_IcyWindDesc::
	.string "A chilling attack\n"
	.string "that lowers the\n"
	.string "foe's SPEED.$"

TrainerHill_Courtyard_Text_EndureDesc::
	.string "Endures any at-\n"
	.string "tack for 1 turn,\n"
	.string "leaving 1HP.$"

TrainerHill_Courtyard_Text_PsychUpDesc::
	.string "Copies the foe's\n"
	.string "effect(s) and\n"
	.string "gives to the user.$"

TrainerHill_Courtyard_Text_IcePunchDesc::
	.string "An icy punch\n"
	.string "that may\n"
	.string "freeze the foe.$"

TrainerHill_Courtyard_Text_ThunderPunchDesc::
	.string "An electrified\n"
	.string "punch that may\n"
	.string "paralyze the foe.$"

TrainerHill_Courtyard_Text_FirePunchDesc::
	.string "A fiery punch\n"
	.string "that may burn\n"
	.string "the foe.$"

TrainerHill_Courtyard_Text_ElementalTutorIntro::
	.string "Zzzzzz…\p"
	.string "What, how, what?\p"
	.string "Oh, sorry, I was snoozing a bit.\p"
	.string "I'm the ELEMENTAL TUTOR.\p"
	.string "I have the power to teach the most\n"
	.string "powerful moves to GRASS, FIRE and\l"
	.string "WATER TYPE POKéMON.\p"
	.string "Did you come to learn such a strong\n"
	.string "power?$"

TrainerHill_Courtyard_Text_ElementalTutorWelcomeBack:
	.string "Zzzzzz…\p"
	.string "What, how, what, who?\p"
	.string "Oh, did you come to learn the\n"
	.string "power of my strongest moves?$"

TrainerHill_Courtyard_Text_TeachWhichMoveElemental::
	.string "Which move do you think is suitable\n"
	.string "for your POKéMON?$"

TrainerHill_Courtyard_Text_StrongElementalMoveDesc::
	.string "Powerful, but\n"
	.string "leaves the user\n"
	.string "immobile one turn.$"

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkWelcome::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special ShowBattlePointsWindow
	return

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGivePrize
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGivePrize::
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGiveItem
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGiveDecor::
	checkdecorspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_NoRoomForDecor
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	adddecoration VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WellSendItToPC, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_NoRoomForDecor::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_PCIsFull, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGiveItem::
	checkitemspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_BagFull
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	additem VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_HereIsYourPrize, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_BagFull::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DecorClerk1::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK
	call TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_1
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KissPoster
	case 1, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KissCushion
	case 2, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_SmoochumDoll
	case 3, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TogepiDoll
	case 4, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_MeowthDoll
	case 5, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClefairyDoll
	case 6, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DittoDoll
	case 7, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_CyndaquilDoll
	case 8, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChikoritaDoll
	case 9, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TotodileDoll
	case 10, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KissPoster::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKissPoster, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 16
	setvar VAR_0x8009, DECOR_KISS_POSTER
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KissCushion::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKissCushion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, DECOR_KISS_CUSHION
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_SmoochumDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmSmoochumDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, DECOR_SMOOCHUM_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TogepiDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmTogepiDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_TOGEPI_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_MeowthDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmMeowthDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_MEOWTH_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClefairyDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmClefairyDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_CLEFAIRY_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DittoDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmDittoDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_DITTO_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_CyndaquilDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_CYNDAQUIL_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChikoritaDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmChikoritaDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_CHIKORITA_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TotodileDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmTotodileDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_TOTODILE_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DecorClerk2::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK
	call TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_2
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_LaprasDoll
	case 1, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_SnorlaxDoll
	case 2, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_VenusaurDoll
	case 3, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_CharizardDoll
	case 4, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_BlastoiseDoll
	case 5, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_LaprasDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmLaprasDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, DECOR_LAPRAS_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_SnorlaxDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, DECOR_SNORLAX_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_VenusaurDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmVenusaurDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_VENUSAUR_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_CharizardDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCharizardDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_CHARIZARD_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_BlastoiseDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_BLASTOISE_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_VitaminClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK
	call TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_VITAMIN_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Protein
	case 1, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Calcium
	case 2, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Iron
	case 3, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Zinc
	case 4, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Carbos
	case 5, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_HpUp
	case 6, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_YouAlreadyHaveThis::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_YouAlreadyHaveThis, MSGBOX_DEFAULT
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Protein::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmProtein, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_PROTEIN
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Calcium::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCalcium, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_CALCIUM
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Iron::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmIron, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_IRON
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Zinc::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmZinc, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_ZINC
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Carbos::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCarbos, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_CARBOS
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_HpUp::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmHpUp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_HP_UP
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_HoldItemClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK
	call TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Leftovers
	case 1, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_WhiteHerb
	case 2, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_QuickClaw
	case 3, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_MentalHerb
	case 4, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Brightpowder
	case 5, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChoiceBand
	case 6, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KingsRock
	case 7, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_FocusBand
	case 8, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ScopeLens
	case 9, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Leftovers::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmLeftovers, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_LEFTOVERS
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_WhiteHerb::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmWhiteHerb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_WHITE_HERB
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_QuickClaw::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmQuickClaw, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_QUICK_CLAW
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_MentalHerb::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmMentalHerb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_MENTAL_HERB
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Brightpowder::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmBrightpowder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_BRIGHT_POWDER
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChoiceBand::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmChoiceBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_CHOICE_BAND
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KingsRock::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKingsRock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_KINGS_ROCK
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_FocusBand::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmFocusBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_FOCUS_BAND
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ScopeLens::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmScopeLens, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_SCOPE_LENS
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Man::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_GoGetYourOwnDoll, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Sailor::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_PokefanF::
	lock
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_GetYouAnythingYouWant, MSGBOX_DEFAULT
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_RichBoy::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WishIHadAllDolls, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Girl::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan_Text, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_Text_YouAlreadyHaveThis:
	.string "You already have this item.$"

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan_Text:
	.string "Hi! If you are looking for the\n"
	.string "WONDERTRADE, they're now located in\l"
	.string "every POKéMON CENTER. Have fun!$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
	.string "Hello, this is the EXCHANGE SERVICE\n"
	.string "CORNER.\p"
	.string "We exchange the Battle Points you\n"
	.string "have collected for lovely prizes.\p"
	.string "Please choose a prize from this list.$"

@ Unused
TrainerHill_Courtyard_ExchangeServiceCorner_Text_PleaseChoosePrize:
	.string "Please choose a prize from this list.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKissPoster:
	.string "You've chosen the KISS POSTER.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKissCushion:
	.string "You've chosen the KISS CUSHION.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmSmoochumDoll:
	.string "You've chosen the SMOOCHUM DOLL.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmTogepiDoll:
	.string "You've chosen the TOGEPI DOLL.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmMeowthDoll:
	.string "You've chosen the MEOWTH DOLL.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmClefairyDoll:
	.string "You've chosen the CLEFAIRY DOLL.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmDittoDoll:
	.string "You've chosen the DITTO DOLL.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll:
	.string "You've chosen the CYNDAQUIL DOLL.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmChikoritaDoll:
	.string "You've chosen the CHIKORITA DOLL.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmTotodileDoll:
	.string "You've chosen the TOTODILE DOLL.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmLaprasDoll:
	.string "You've chosen the LAPRAS DOLL.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll:
	.string "You've chosen the SNORLAX DOLL.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmVenusaurDoll:
	.string "You've chosen the VENUSAUR DOLL.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCharizardDoll:
	.string "You've chosen the CHARIZARD DOLL.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll:
	.string "You've chosen the BLASTOISE DOLL.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmProtein:
	.string "You've chosen the PROTEIN.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCalcium:
	.string "You've chosen the CALCIUM.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmIron:
	.string "You've chosen the IRON.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmZinc:
	.string "You've chosen the ZINC.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCarbos:
	.string "You've chosen the CARBOS.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmHpUp:
	.string "You've chosen the HP UP.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmBrightpowder:
	.string "You've chosen the BRIGHTPOWDER.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmWhiteHerb:
	.string "You've chosen the WHITE HERB.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmQuickClaw:
	.string "You've chosen the QUICK CLAW.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmMentalHerb:
	.string "You've chosen the MENTAL HERB.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmChoiceBand:
	.string "You've chosen the CHOICE BAND.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKingsRock:
	.string "You've chosen the KING'S ROCK.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmFocusBand:
	.string "You've chosen the FOCUS BAND.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmScopeLens:
	.string "You've chosen the SCOPE LENS.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmLeftovers:
	.string "You've chosen the LEFTOVERS.\n"
	.string "Is that correct?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_WellSendItToPC:
	.string "Thank you!\n"
	.string "We'll send it to your PC at home.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_HereIsYourPrize:
	.string "Here is your prize!$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_DontHaveEnoughPoints:
	.string "I'm so sorry…\n"
	.string "You don't have enough Battle Points…$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_PCIsFull:
	.string "I'm so sorry…\n"
	.string "Your PC appears to be full…$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt:
	.string "I'm so sorry…\n"
	.string "You don't have space to hold it…$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ThankYouVisitWithPoints:
	.string "Thank you very much.\p"
	.string "Please visit us when you have\n"
	.string "saved up Battle Points.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_WishIHadAllDolls:
	.string "Oh, they're so nice!\n"
	.string "I wish I had them!\l"
	.string "Cute cushions!\l"
	.string "Big plush DOLLS!\l"
	.string "Little plush DOLLS!\l"
	.string "I wish I had them all!$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_GetYouAnythingYouWant:
	.string "Leave it to your mommy!\p"
	.string "If it's anything you want, I'll go\n"
	.string "through anything to get it, honey!$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ItemsWillGetMonTougher:
	.string "If I can get hold of the items here,\n"
	.string "my POKéMON will get tougher.\p"
	.string "You bet they will!\n"
	.string "No question about it!$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_GoGetYourOwnDoll:
	.string "Hah?\n"
	.string "What are you gawking at?\p"
	.string "I don't like you staring at my plush\n"
	.string "doll like that.\p"
	.string "If you want it, go get one yourself!\n"
	.string "Isn't that right, SMOOCHUM?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_MoreBattlePointsForRecord:
	.string "Did you know?\p"
	.string "If you stretch your record at any of\n"
	.string "the BATTLE facilities, they start\l"
	.string "giving you more and more Battle Points.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_KissPosterDesc::
	.string "A large poster with a SMOOCHUM print.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_KissCushionDesc::
	.string "A SMOOCHUM cushion.\n"
	.string "Place it on a mat or a desk.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_SmoochumDollDesc::
	.string "A SMOOCHUM DOLL.\n"
	.string "Place it on a mat or a desk.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_TogepiDollDesc::
	.string "A TOGEPI DOLL.\n"
	.string "Place it on a mat or a desk.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_MeowthDollDesc::
	.string "A MEOWTH DOLL.\n"
	.string "Place it on a mat or a desk.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ClefairyDollDesc::
	.string "A CLEFAIRY DOLL.\n"
	.string "Place it on a mat or a desk.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_DittoDollDesc::
	.string "A DITTO DOLL.\n"
	.string "Place it on a mat or a desk.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_CyndaquilDollDesc::
	.string "A CYNDAQUIL DOLL.\n"
	.string "Place it on a mat or a desk.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ChikoritaDollDesc::
	.string "A CHIKORITA DOLL.\n"
	.string "Place it on a mat or a desk.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_TotodileDollDesc::
	.string "A TOTODILE DOLL.\n"
	.string "Place it on a mat or a desk.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_LargeDollDesc::
	.string "A large DOLL.\n"
	.string "Place it on a mat or a desk.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ProteinDesc::
	.string "A strange ticket that will get\n"
	.string "you to an abandoned island.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_CalciumDesc::
	.string "A strange ticket that will get\n"
	.string "you to an abandoned island.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_IronDesc::
	.string "A strange ticket that will get\n"
	.string "you to an abandoned island.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ZincDesc::
	.string "An… old map? Maybe\n"
	.string "it will get you somewhere.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_CarbosDesc::
	.string "x10 EV gain, but halves speed.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_HPUpDesc::
	.string "A peculiar box made\n"
	.string "by SILPH CO.$"  

TrainerHill_Courtyard_ExchangeServiceCorner_Text_LeftoversDesc::
	.string "A hold item that gradually restores\n"
	.string "HP in battle.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_WhiteHerbDesc::
	.string "A hold item that restores any\n"
	.string "lowered stat.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_QuickClawDesc::
	.string "A hold item that occasionally allows\n"
	.string "the first strike.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_MentalHerbDesc::
	.string "A hold item that snaps POKéMON out\n"
	.string "of infatuation.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_BrightpowderDesc::
	.string "A hold item that casts a glare to\n"
	.string "reduce accuracy.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ChoiceBandDesc::
	.string "Raises a move's power, but permits\n"
	.string "only that move.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_KingsRockDesc::
	.string "A hold item that may cause flinching\n"
	.string "when the foe is hit.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_FocusBandDesc::
	.string "A hold item that occasionally\n"
	.string "prevents fainting.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ScopeLensDesc::
	.string "A hold item that raises the\n"
	.string "critical-hit rate.$"
