GoldenrodCity_UndergroundStorage_MapScripts::
	.byte 0

GoldenrodCity_UndergroundStorage_EventScript_Director::
    lock
    faceplayer
    checkitem ITEM_CARD_KEY
    goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_UndergroundStorage_EventScript_Director2
    msgbox RadioTowerBasement_Text_DirectorIntro, MSGBOX_DEFAULT
    closemessage
    giveitem ITEM_CARD_KEY
    msgbox RadioTowerBasement_Text_DirectorCardKey, MSGBOX_DEFAULT
    closemessage
    release
    end

GoldenrodCity_UndergroundStorage_EventScript_Director2::
    msgbox RadioTowerBasement_Text_DirectorAfter, MSGBOX_DEFAULT
    closemessage
    release
    end

GoldenrodCity_UndergroundStorage_EventScript_Grunt19::
    trainerbattle_single TRAINER_GRUNT_19, RadioTowerBasement_Text_GruntM24Seen, RadioTowerBasement_Text_GruntM24Beaten
	msgbox RadioTowerBasement_Text_GruntM24After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Grunt12::
    trainerbattle_single TRAINER_GRUNT_12, RadioTowerBasement_Text_GruntM14Seen, RadioTowerBasement_Text_GruntM14Beaten
	msgbox RadioTowerBasement_Text_GruntM14After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Eto::
    trainerbattle_single TRAINER_ETO_3, RadioTowerBasement_Text_GruntM15Seen, RadioTowerBasement_Text_GruntM15Beaten
	msgbox RadioTowerBasement_Text_GruntM15After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Item_TM_CALM_MIND::
    finditem ITEM_TM_CALM_MIND
    end

GoldenrodCity_UndergroundStorage_EventScript_Item_UltraBall::
    finditem ITEM_ULTRA_BALL
    end

GoldenrodCity_UndergroundStorage_EventScript_Item_MaxEther::
    finditem ITEM_MAX_ETHER
    end

RadioTowerBasement_Text_GruntM24Seen:
    .string "How did you get this far?\p"
    .string "I guess it can't be helped. I'll\n"
    .string "dispose of you.$"

RadioTowerBasement_Text_GruntM24Beaten:
    .string "I got disposed of…$"

RadioTowerBasement_Text_GruntM24After:
    .string "TEAM ROCKET will keep going, waiting\n"
    .string "for the return of GIOVANNI.\p"
    .string "We'll do whatever it takes.$"

RadioTowerBasement_Text_GruntM14Seen:
    .string "You're not going any farther!\p"
    .string "I don't show mercy to my enemies,\n"
    .string "not even brats!$"

RadioTowerBasement_Text_GruntM14Beaten:
    .string "Blast it!$"

RadioTowerBasement_Text_GruntM14After:
    .string "I lost…\p"
    .string "Please forgive me, GIOVANNI!$"

RadioTowerBasement_Text_GruntM15Seen:
    .string "Hyuck-hyuck-hyuck! Look who it is!\p"
    .string "Ready? I'm really tough now!$"

RadioTowerBasement_Text_GruntM15Beaten:
    .string "Hyuck-hyuck-hyuck! You're so good!\p"
    .string "This TEAM ROCKET thing is just\n"
    .string "a job, but I can see it hurts others.\p"
    .string "That's it, I'm leaving.\p"
    .string "Thank you so much. Sorry GIOVANNI!$"

RadioTowerBasement_Text_GruntM15After:
    .string "Hyuck-hyuck-hyuck! That was a blast!\n"
    .string "I'll remember you!$"

RadioTowerBasement_Text_DirectorIntro:
    .string "DIRECTOR: Who? What? You came to\n"
    .string "rescue me?\p"
    .string "Thank you!\p"
    .string "The RADIO TOWER!\p"
    .string "What's happening there?\p"
    .string "Taken over by TEAM ROCKET?\p"
    .string "Here. Take this CARD KEY.$"

RadioTowerBasement_Text_DirectorCardKey:
    .string "DIRECTOR: Use that to open the\n"
    .string "shutters on 3F.$"

RadioTowerBasement_Text_DirectorAfter:
    .string "I'm begging you to help.\p"
    .string "There's no telling what they'll do if\n"
    .string "they control the transmitter.\p"
    .string "They may even be able to control\n"
    .string "POKéMON using a special signal!\p"
    .string "You're the only one I can call on.\p"
    .string "Please save the RADIO TOWER…\p"
    .string "And all the POKéMON nationwide!$"
