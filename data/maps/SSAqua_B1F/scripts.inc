.set LOCALID_SSAQUA_B1F_SAILORLOOKING, 10

SSAqua_B1F_MapScripts::
	.byte 0

SSAqua_B1F_EventScript_Trigger::
	lock
	turnobject LOCALID_SSAQUA_B1F_SAILORLOOKING, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox SSAqua_B1F_Text_FastShipOnDutySailor, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0 
	turnobject LOCALID_SSAQUA_B1F_SAILORLOOKING, DIR_SOUTH
	release
	end

SSAqua_B1F_EventScript_SailorLookingForBuddy::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SSAQUA_SAILOR, SSAqua_B1F_EventScript_SailorLookingFoundBuddy
	msgbox SSAqua_B1F_Text_FastShipOnDutySailor, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_B1F_EventScript_SailorLookingFoundBuddy::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorThanks, MSGBOX_DEFAULT
	goto_if_lt VAR_SSAQUA_STATE, 5, SSAqua_B1F_EventScript_SailorGirl
	closemessage
	release
	end
SSAqua_B1F_EventScript_SailorGirl::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorSawGirl, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_B1F_EventScript_SleepySailor::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorDirections, MSGBOX_NPC
	end

SSAqua_B1F_EventScript_Barfcan::
	msgbox SSAqua_B1F_Text_BarfCan, MSGBOX_SIGN
	end

SSAqua_B1F_Text_BarfCan:
    .string "Yuck!\n"
    .string "Shouldn't have looked!$"

SSAqua_B1F_Text_FastShipOnDutySailor:
	.string "Hey, kid. Could I get you to\n"
	.string "look for my buddy?\p"
	.string "He's goofing off somewhere,\n"
	.string "that lazy bum!\p"
	.string "I want to go find him, but I'm\n"
	.string "on duty right now.$"

SSAqua_B1F_Text_FastShipOnDutySailorRefused:
	.string "Oh, gee…\p"
	.string "The CAPTAIN will be furious…$"

SSAqua_B1F_Text_FastShipOnDutySailorThanks:
	.string "Thanks, kid! I chewed him out\n"
	.string "good so he'll quit slacking off!$"

SSAqua_B1F_Text_FastShipOnDutySailorSawGirl:
	.string "A little girl?\p"
	.string "I may have seen her go by here.$"

SSAqua_B1F_Text_FastShipOnDutySailorDirections:
	.string "The dining room is up ahead.\p"
	.string "The stairs at the end lead to\n"
	.string "the CAPTAIN's cabin.$"

SSAqua_B1F_EventScript_Jeff::
	trainerbattle_single TRAINER_JEFF SSAqua_B1F_Text_SailorJeffSeen, SSAqua_B1F_Text_SailorJeffBeaten
	msgbox SSAqua_B1F_Text_SailorJeffAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorJeffSeen:
	.string "Nothing beats a battle when\n"
	.string "I'm on my break.$"

SSAqua_B1F_Text_SailorJeffBeaten:
	.string "Win or lose, my break's over!$"

SSAqua_B1F_Text_SailorJeffAfter:
	.string "I guess I can't win if I don't\n"
	.string "get serious.$"

SSAqua_B1F_EventScript_Debra::
	trainerbattle_single TRAINER_DEBRA SSAqua_B1F_Text_PicnickerDebraSeen, SSAqua_B1F_Text_PicnickerDebraBeaten
	msgbox SSAqua_B1F_Text_PicnickerDebraAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_PicnickerDebraSeen:
	.string "I'm so bored. Want to battle?$"

SSAqua_B1F_Text_PicnickerDebraBeaten:
	.string "Yow! You're too strong!$"

SSAqua_B1F_Text_PicnickerDebraAfter:
	.string "SAFFRON, CELADON… I hear there\n"
	.string "are many big cities in KANTO.$"

SSAqua_B1F_EventScript_Fritz::
	trainerbattle_single TRAINER_FRITZ SSAqua_B1F_Text_JugglerFritzSeen, SSAqua_B1F_Text_JugglerFritzBeaten
	msgbox SSAqua_B1F_Text_JugglerFritzAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_JugglerFritzSeen:
	.string "Urrf… I'm seasick!$"

SSAqua_B1F_Text_JugglerFritzBeaten:
	.string "I can't move anymore…$"

SSAqua_B1F_Text_JugglerFritzAfter:
	.string "No more ships for me.\n"
	.string "Next time,\p"
	.string "I'm taking the MAGNET TRAIN.$"

SSAqua_B1F_EventScript_Garrett::
	trainerbattle_single TRAINER_GARRETT SSAqua_B1F_Text_SailorGarrettSeen, SSAqua_B1F_Text_SailorGarrettBeaten
	msgbox SSAqua_B1F_Text_SailorGarrettAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorGarrettSeen:
	.string "This is where we sailors work!$"

SSAqua_B1F_Text_SailorGarrettBeaten:
	.string "I lost on my home field…$"

SSAqua_B1F_Text_SailorGarrettAfter:
	.string "We get different passengers\n"
	.string "from VERMILION CITY to\p"
	.string "OLIVINE CITY.$"

SSAqua_B1F_EventScript_Jonah::
	trainerbattle_single TRAINER_JONAH SSAqua_B1F_Text_FisherJonahSeen, SSAqua_B1F_Text_FisherJonahBeaten
	msgbox SSAqua_B1F_Text_FisherJonahAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_FisherJonahSeen:
	.string "Even though we're out on the\n"
	.string "sea, I can't fish!\p"
	.string "This is boring! Let's battle!$"

SSAqua_B1F_Text_FisherJonahBeaten:
	.string "I… I'm not bored anymore…$"

SSAqua_B1F_Text_FisherJonahAfter:
	.string "I plan to fish off\n"
	.string "VERMILION's pier.$"

SSAqua_B1F_EventScript_Wai::
	trainerbattle_single TRAINER_WAI SSAqua_B1F_Text_BlackbeltWaiSeen, SSAqua_B1F_Text_BlackbeltWaiBeaten
	msgbox SSAqua_B1F_Text_BlackbeltWaiAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_BlackbeltWaiSeen:
	.string "I'm building up my legs by\n"
	.string "bracing\p"
	.string "against the ship's rocking!$"

SSAqua_B1F_Text_BlackbeltWaiBeaten:
	.string "Rocked and rolled over!$"

SSAqua_B1F_Text_BlackbeltWaiAfter:
	.string "I couldn't find the KARATE KING\n"
	.string "in JOHTO.\p"
	.string "He's supposed to be training in\n"
	.string "a cave somewhere.$"

SSAqua_B1F_EventScript_Kenneth::
	trainerbattle_single TRAINER_KENNETH SSAqua_B1F_Text_SailorKennethSeen, SSAqua_B1F_Text_SailorKennethBeaten
	msgbox SSAqua_B1F_Text_SailorKennethAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorKennethSeen:
	.string "I'm a sailor man!\p"
	.string "But I'm training POKéMON, so I\n"
	.string "can become the CHAMP!$"

SSAqua_B1F_Text_SailorKennethBeaten:
	.string "My lack of training is obvious…$"

SSAqua_B1F_Text_SailorKennethAfter:
	.string "Eight BADGES! They must prove\n"
	.string "that you've beaten\p"
	.string "GYM LEADERS.\p"
	.string "No wonder you're so good!$"

SSAqua_B1F_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY SSAqua_B1F_Text_TeacherShirleySeen, SSAqua_B1F_Text_TeacherShirleyBeaten
	msgbox SSAqua_B1F_Text_TeacherShirleyAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_TeacherShirleySeen:
	.string "Don't lay a finger on my\n"
	.string "students!$"

SSAqua_B1F_Text_TeacherShirleyBeaten:
	.string "Aaack!$"

SSAqua_B1F_Text_TeacherShirleyAfter:
	.string "We're on a field trip to the\n"
	.string "RUINS outside VIOLET.$"

SSAqua_B1F_EventScript_Nate::
	trainerbattle_single TRAINER_NATE SSAqua_B1F_Text_SchoolboyNateSeen, SSAqua_B1F_Text_SchoolboyNateBeaten
	msgbox SSAqua_B1F_Text_SchoolboyNateAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SchoolboyNateSeen:
	.string "Do you know the RUINS OF ALPH?$"

SSAqua_B1F_Text_SchoolboyNateBeaten:
	.string "Yaargh!$"

SSAqua_B1F_Text_SchoolboyNateAfter:
	.string "Radios pick up strange signals\n"
	.string "inside the RUINS.$"

SSAqua_B1F_EventScript_Ricky::
	trainerbattle_single TRAINER_RICKY SSAqua_B1F_Text_SchoolboyRickySeen, SSAqua_B1F_Text_SchoolboyRickyBeaten
	msgbox SSAqua_B1F_Text_SchoolboyRickyAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SchoolboyRickySeen:
	.string "There are some odd stone panels\n"
	.string "in the RUINS OF ALPH.$"

SSAqua_B1F_Text_SchoolboyRickyBeaten:
	.string "I was done in!$"

SSAqua_B1F_Text_SchoolboyRickyAfter:
	.string "I read that there are four of\n"
	.string "those stone panels.$"

