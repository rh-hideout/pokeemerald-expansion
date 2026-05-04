BattleFrontier_Lounge9_MapScripts::
	.byte 0

BattleFrontier_Lounge9_Heal::
	specialvar VAR_RESULT, IsPokecenterChallengeActivated
	goto_if_eq VAR_RESULT, TRUE, SSTidalRooms_EventScript_Bed_PokecenterChallenge
	msgbox BattleFrontier_Lounge9_Heal_TEXT, MSGBOX_NPC
	waitmessage
	fadescreen 0x1
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen 0x0
	msgbox BattleFrontier_Lounge9_Heal_TEXT2, MSGBOX_NPC
	waitmessage
	release
	end

BattleFrontier_Lounge9_Heal_TEXT:
	.string "Hi! Welcome to the TRAINING DOJO!\n"
	.string "I will heal your POKéMON.$"

BattleFrontier_Lounge9_Heal_TEXT2:
	.string "We hope to see you again!$"

BattleFrontier_Lounge9_EV_No:
	msgbox BattleFrontier_Lounge9_EV_No_TEXT, MSGBOX_DEFAULT
	waitmessage
	release
	end

@EV Gym

BattleFrontier_Lounge9_EV_HP::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge9_EV_HP_TEXT, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_EV_HP_Yes
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_EV_No
	end

BattleFrontier_Lounge9_EV_HP_Yes::
	msgbox BattleFrontier_Lounge9_EV_HP_TEXT2, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_WAILORD, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_NO_SHINY
	release
	end
	
BattleFrontier_Lounge9_EV_ATK::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge9_EV_ATK_TEXT, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_EV_ATK_Yes
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_EV_No
	end

BattleFrontier_Lounge9_EV_ATK_Yes::
	msgbox BattleFrontier_Lounge9_EV_ATK_TEXT2, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_GALLADE, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_NO_SHINY
	release
	end

BattleFrontier_Lounge9_EV_SATK::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge9_EV_SATK_TEXT, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_EV_SATK_Yes
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_EV_No
	end

BattleFrontier_Lounge9_EV_SATK_Yes::
	msgbox BattleFrontier_Lounge9_EV_SATK_TEXT2, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_GARDEVOIR, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_NO_SHINY
	release
	end

BattleFrontier_Lounge9_EV_DEF::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge9_EV_DEF_TEXT, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_EV_DEF_Yes
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_EV_No
	end

BattleFrontier_Lounge9_EV_DEF_Yes::
	msgbox BattleFrontier_Lounge9_EV_DEF_TEXT2, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_AGGRON, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_NO_SHINY
	release
	end

BattleFrontier_Lounge9_EV_SDEF::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge9_EV_SDEF_TEXT, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_EV_SDEF_Yes
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_EV_No
	end

BattleFrontier_Lounge9_EV_SDEF_Yes::
	msgbox BattleFrontier_Lounge9_EV_SDEF_TEXT2, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_LUDICOLO, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_NO_SHINY
	release
	end

BattleFrontier_Lounge9_EV_SPD::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge9_EV_SPD_TEXT, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_EV_SPD_Yes
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_EV_No
	end

BattleFrontier_Lounge9_EV_SPD_Yes::
	msgbox BattleFrontier_Lounge9_EV_SPD_TEXT2, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_SCEPTILE, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_NO_SHINY
	release
	end

BattleFrontier_Lounge9_EV_HP_TEXT:
	.string "Hi ya buddy! I can train your\n"
	.string "POKéMON in HEALTH POINTS.\p"
	.string "Are you ready?$"

BattleFrontier_Lounge9_EV_HP_TEXT2:
	.string "Go WAILORD!$"

BattleFrontier_Lounge9_EV_ATK_TEXT:
	.string "OSHA! I can train your POKéMON\n"
	.string "in ATTACK.\p"
	.string "Are you ready?$"

BattleFrontier_Lounge9_EV_ATK_TEXT2:
	.string "Go GALLADE!$"

BattleFrontier_Lounge9_EV_SATK_TEXT:
	.string "Bonjour! I can train your POKéMON\n"
	.string "in SPECIAL ATTACK.\p"
	.string "Are you ready?$"

BattleFrontier_Lounge9_EV_SATK_TEXT2:
	.string "Go GARDEVOIR!$"
	
BattleFrontier_Lounge9_EV_DEF_TEXT:
	.string "Sup' kid! I can train your\n"
	.string "POKéMON in DEFENSE.\p"
	.string "Are you ready?$"

BattleFrontier_Lounge9_EV_DEF_TEXT2:
	.string "Go AGGRON!$"

BattleFrontier_Lounge9_EV_SDEF_TEXT:
	.string "Bonjour mon trainer! I can train your\n"
	.string "POKéMON in SPECIAL DEFENSE.\p"
	.string "Are you ready?$"

BattleFrontier_Lounge9_EV_SDEF_TEXT2:
	.string "Go LUDICOLO!$"

BattleFrontier_Lounge9_EV_SPD_TEXT:
	.string "Hmph… I can train your\n"
	.string "POKéMON in SPEED.\p"
	.string "Are you ready?$"

BattleFrontier_Lounge9_EV_SPD_TEXT2:
	.string "Go SCEPTILE!$"

BattleFrontier_Lounge9_EV_No_TEXT:
	.string "No? Okay.$"

@Columns text

BattleFrontier_Lounge9_EV_Column::
	msgbox BattleFrontier_Lounge9_EV_Column_Text, MSGBOX_SIGN
	end

BattleFrontier_Lounge9_EV_Column_Text:
    .string "Welcome to the TRAINING DOJO!\p"
    .string "Here, you will find various types of\n"
    .string "training to improve POKéMON STATS.\p"
    .string "EV RESET:\n"
    .string "EV-MAN can reset a POKéMON's EVs to\l"
    .string "zero. He is on the right column.\p"
    .string "EV TRAINING:\n"
    .string "Six trainers focus on each STAT, from\l"
    .string "left to right: DEF - ATK - HP - SPD -\l"
    .string "SP.ATK - SP.DEF.\p"
    .string "TIP: A MACHO BRACE multiplies EVs\n"
    .string "earned by 5!\p"
    .string "After becoming the HOENN CHAMPION,\n"
    .string "you unlock the following options:\p"
    .string "IV TRAINING & HIDDEN POWER:\n"
    .string "IV-MAN trains POKéMON to maximize IVs.\l"
    .string "He can also adjust IVs to change the\l"
    .string "type of HIDDEN POWER.\p"
    .string "EXPERIENCE TRAINING:\n"
    .string "The EXPERIENCE NURSE on the bottom\l"
    .string "left offers training for your team.\p"
    .string "ABILITY SWAPPER:\n"
    .string "The ABILITY EXPERT on the top left can\l"
    .string "swap between the abilities a POKéMON\l"
    .string "can naturally have.$"

@EV RESET

BattleFrontier_Lounge9_EV_SetZero::
	lockall
	faceplayer
	goto_if_unset FLAG_EV_MAN_FIRSTIME, BattleFrontier_Lounge9_EV_SetZeroIntro
	msgbox BattleFrontier_Lounge9_EV_SetZeroTextNoIntro, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroMoney
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroNo
	end

BattleFrontier_Lounge9_EV_SetZeroIntro::
	setflag FLAG_EV_MAN_FIRSTIME
	msgbox BattleFrontier_Lounge9_EV_SetZeroText, MSGBOX_NPC
	waitmessage
	end

BattleFrontier_Lounge9_EV_SetZeroMoney::
	msgbox BattleFrontier_Lounge9_EV_SetZeroMoneyText, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroCheckMoney
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroNo
	end

BattleFrontier_Lounge9_EV_SetZeroCheckMoney::
	checkmoney 20000, 0
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroYes
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroNoMoney
	end

BattleFrontier_Lounge9_EV_SetZeroYes::
	msgbox BattleFrontier_Lounge9_EV_SetZeroText2, MSGBOX_DEFAULT
	waitmessage
	closemessage
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_SIZE
	goto_if_ge BattleFrontier_Lounge9_EV_SetZeroNo
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroEgg
	goto BattleFrontier_Lounge9_EV_SetZeroSure
	end

BattleFrontier_Lounge9_EV_SetZeroNo::
	msgbox BattleFrontier_Lounge9_EV_SetZeroTextNo, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

BattleFrontier_Lounge9_EV_SetZeroNoMoney::
	msgbox BattleFrontier_Lounge9_EV_SetZeroTextNoMoney, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

BattleFrontier_Lounge9_EV_SetZeroEgg::
	msgbox BattleFrontier_Lounge9_EV_SetZeroTextEgg, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

BattleFrontier_Lounge9_EV_SetZeroSure::
	faceplayer
	msgbox BattleFrontier_Lounge9_EV_SetZeroTextSure, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroProceed
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroNo
	end

BattleFrontier_Lounge9_EV_SetZeroProceed::
	faceplayer
	fadescreen 0x1
	delay 30
	removemoney 20000, 0
	fadescreen 0x0
	setvar VAR_0x8000, 0
	setvar VAR_0x8001, 0
	setvar VAR_0x8002, 0
	setvar VAR_0x8003, 0
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special SetHpEvs
	special SetAtkEvs
	special SetDefEvs
	special SetSpdEvs
	special SetSpAtkEvs
	special SetSpDefEvs
	msgbox BattleFrontier_Lounge9_EV_SetZeroText3, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_EV_SetZeroText:
    .string "Greetings, trainer. My name is EVAN,\n"
    .string "though I am commonly referred to as\n"
    .string "EV-MAN.\p"
    .string "I am the owner of this facility,\n"
    .string "where I conduct training alongside my\n"
    .string "brother, IVAN.\p"
    .string "Should you wish to reset a POKéMON's\n"
    .string "EVs entirely, please speak to me.$"

BattleFrontier_Lounge9_EV_SetZeroTextNoIntro:
    .string "EV-MAN: Welcome back.\n"
    .string "Would you like me to reset all your\l"
    .string "POKéMON's EFFORT VALUES?$"

BattleFrontier_Lounge9_EV_SetZeroText2:
	.string "Which POKéMON EVs should I reset\n"
	.string "to zero?$"

BattleFrontier_Lounge9_EV_SetZeroText3:
    .string "Phew! That was tough, but I made it!\n"
    .string "All of its EVs have been reset to zero!$"

BattleFrontier_Lounge9_EV_SetZeroTextEgg:
	.string "Sorry, that will not work.$"

BattleFrontier_Lounge9_EV_SetZeroTextNo:
	.string "Come back if you need to!$"

BattleFrontier_Lounge9_EV_SetZeroMoneyText:
    .string "This process is rather difficult.\n"
    .string "It will cost 20,000¥.\l"
    .string "Would you like to proceed?$"

BattleFrontier_Lounge9_EV_SetZeroTextNoMoney:
    .string "You don't have enough money.\p"
    .string "Come back when you do.$"

BattleFrontier_Lounge9_EV_SetZeroTextSure:
    .string "Are you sure you want to reset this\n"
    .string "POKéMON's EVs?\p"
    .string "This process cannot be undone.$"

@IV setter to 31 (all of them) &&&& HIDDEN POWER Type selector

BattleFrontier_Lounge9_IV_Man::
	checkflag FLAG_IV_SETTER
	lockall
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, BattleFrontier_Lounge9_IV_ManNoChampion
	call_if_unset FLAG_IV_SETTER, BattleFrontier_Lounge9_IV_First_Time
	msgbox BattleFrontier_Lounge9_IV_Text1, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_IV_CheckMoney
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_IV_No
	end

BattleFrontier_Lounge9_IV_ManNoChampion::
	msgbox BattleFrontier_Lounge9_IV_TextNoChampion, MSGBOX_NPC
	releaseall
	end

BattleFrontier_Lounge9_IV_First_Time::
	msgbox BattleFrontier_Lounge9_IV_TextFirstTime, MSGBOX_NPC
	setflag FLAG_IV_SETTER
	releaseall
	end

BattleFrontier_Lounge9_IV_No::
	msgbox BattleFrontier_Lounge9_IV_Text_No, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

BattleFrontier_Lounge9_IV_NoLevel::
	msgbox BattleFrontier_Lounge9_IV_Text_NoLevel, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

BattleFrontier_Lounge9_IV_CheckMoney::
	checkmoney 100000, 0
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_Lounge9_IV_ChoosePkm
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroNoMoney
	end

BattleFrontier_Lounge9_IV_ChoosePkm::
	faceplayer
	closemessage
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_SIZE
	goto_if_ge BattleFrontier_Lounge9_IV_No
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroEgg
	goto BattleFrontier_Lounge9_IV_CheckIfLvlMax
	end

BattleFrontier_Lounge9_IV_CheckIfLvlMax::
	faceplayer
	waitmessage
	checkpartymonlevel 100
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_Lounge9_IV_Continue_Question_CustomOrMax
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_Lounge9_IV_NoLevel
	releaseall
	end

BattleFrontier_Lounge9_IV_Continue_Question_CustomOrMax::
	faceplayer
	msgbox BattleFrontier_Lounge9_IV_Text_CustomizeIVs, MSGBOX_DEFAULT
	waitmessage
	dynmultichoice 20, 8, FALSE, 2, 0, DYN_MULTICHOICE_CB_NONE, EventScript_IVSetter_Text_CustomizeIVs, EventScript_IVSetter_Text_SetMax
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge9_IV_CustomizeIVs_SelectType
	case 1, BattleFrontier_Lounge9_IV_SetMax
	case MULTI_B_PRESSED, BattleFrontier_Lounge9_IV_No
	closemessage
	release
	end

EventScript_IVSetter_Text_CustomizeIVs:
	.string "CUSTOMIZE$"

EventScript_IVSetter_Text_SetMax:
	.string "SET to MAX$"

BattleFrontier_Lounge9_IV_SetMax::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31
	setvar VAR_0x8008, 31
	setvar VAR_0x8009, 31
	setvar VAR_0x800A, 31
	setvar VAR_0x800B, 31
	setvar VAR_UNUSED_0x8014, 31
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpdIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_IV_CustomizeIVs_SelectType:
	msgbox BattleFrontier_Lounge9_IV_Text_CustomizeIVs_SetType, MSGBOX_DEFAULT
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, EventScript_IVSetter_Type_Fighting, EventScript_IVSetter_Type_Flying, EventScript_IVSetter_Type_Poison, EventScript_IVSetter_Type_Ground, EventScript_IVSetter_Type_Rock, EventScript_IVSetter_Type_Bug, EventScript_IVSetter_Type_Ghost, EventScript_IVSetter_Type_Steel, EventScript_IVSetter_Type_Fairy, EventScript_IVSetter_Type_Fire, EventScript_IVSetter_Type_Water, EventScript_IVSetter_Type_Grass, EventScript_IVSetter_Type_Electric, EventScript_IVSetter_Type_Psychic, EventScript_IVSetter_Type_Ice, EventScript_IVSetter_Type_Dragon, EventScript_IVSetter_Type_Dark 
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Fighting
	case 1, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Flying
	case 2, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Poison
	case 3, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Ground
	case 4, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Rock
	case 5, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Bug
	case 6, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Ghost
	case 7, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Steel
	case 8, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Fairy
	case 9, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Fire
	case 10, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Water
	case 11, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Grass
	case 12, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Electric
	case 13, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Psychic
	case 14, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Ice
	case 15, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Dragon
	case 16, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Dark
	closemessage
	release
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Fighting::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 30 @DEF
	setvar VAR_0x800B, 30 @SP. ATK
	setvar VAR_UNUSED_0x8014, 30 @SP. DEF
	setvar VAR_0x800A, 30 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Flying::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 31 @DEF
	setvar VAR_0x800B, 30 @SP. ATK
	setvar VAR_UNUSED_0x8014, 30 @SP. DEF
	setvar VAR_0x800A, 30 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Poison::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 30 @DEF
	setvar VAR_0x800B, 30 @SP. ATK
	setvar VAR_UNUSED_0x8014, 30 @SP. DEF
	setvar VAR_0x800A, 31 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Ground::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 31 @DEF
	setvar VAR_0x800B, 30 @SP. ATK
	setvar VAR_UNUSED_0x8014, 30 @SP. DEF
	setvar VAR_0x800A, 31 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Rock::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 30 @DEF
	setvar VAR_0x800B, 31 @SP. ATK
	setvar VAR_UNUSED_0x8014, 30 @SP. DEF
	setvar VAR_0x800A, 30 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Bug::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 31 @DEF
	setvar VAR_0x800B, 31 @SP. ATK
	setvar VAR_UNUSED_0x8014, 30 @SP. DEF
	setvar VAR_0x800A, 30 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Ghost::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 30 @DEF
	setvar VAR_0x800B, 31 @SP. ATK
	setvar VAR_UNUSED_0x8014, 30 @SP. DEF
	setvar VAR_0x800A, 31 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Steel::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 31 @DEF
	setvar VAR_0x800B, 31 @SP. ATK
	setvar VAR_UNUSED_0x8014, 30 @SP. DEF
	setvar VAR_0x800A, 31 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Fairy::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 30 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 30 @DEF
	setvar VAR_0x800B, 30 @SP. ATK
	setvar VAR_UNUSED_0x8014, 31 @SP. DEF
	setvar VAR_0x800A, 30 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Fire::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 30 @ATK
	setvar VAR_0x8009, 31 @DEF
	setvar VAR_0x800B, 30 @SP. ATK
	setvar VAR_UNUSED_0x8014, 31 @SP. DEF
	setvar VAR_0x800A, 30 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Water::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 30 @DEF
	setvar VAR_0x800B, 30 @SP. ATK
	setvar VAR_UNUSED_0x8014, 31 @SP. DEF
	setvar VAR_0x800A, 31 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Grass::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 31 @DEF
	setvar VAR_0x800B, 30 @SP. ATK
	setvar VAR_UNUSED_0x8014, 31 @SP. DEF
	setvar VAR_0x800A, 31 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Electric::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 30 @HP
	setvar VAR_0x8008, 30 @ATK
	setvar VAR_0x8009, 30 @DEF
	setvar VAR_0x800B, 31 @SP. ATK
	setvar VAR_UNUSED_0x8014, 31 @SP. DEF
	setvar VAR_0x800A, 30 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Psychic::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 30 @HP
	setvar VAR_0x8008, 30 @ATK
	setvar VAR_0x8009, 31 @DEF
	setvar VAR_0x800B, 31 @SP. ATK
	setvar VAR_UNUSED_0x8014, 31 @SP. DEF
	setvar VAR_0x800A, 30 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Ice::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 30 @HP
	setvar VAR_0x8008, 30 @ATK
	setvar VAR_0x8009, 30 @DEF
	setvar VAR_0x800B, 31 @SP. ATK
	setvar VAR_UNUSED_0x8014, 31 @SP. DEF
	setvar VAR_0x800A, 31 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Dragon::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 30 @HP
	setvar VAR_0x8008, 30 @ATK
	setvar VAR_0x8009, 31 @DEF
	setvar VAR_0x800B, 31 @SP. ATK
	setvar VAR_UNUSED_0x8014, 31 @SP. DEF
	setvar VAR_0x800A, 31 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Dark::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 31 @DEF
	setvar VAR_0x800B, 31 @SP. ATK
	setvar VAR_UNUSED_0x8014, 31 @SP. DEF
	setvar VAR_0x800A, 31 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_IV_TextNoChampion:
	.string "Hmm? What?\p"
	.string "Oh, you're a trainer. But not one I\n"
	.string "would call strong…\p"
	.string "Try beating the POKéMON LEAGUE and\n"
	.string "come back again.\p"
	.string "I will show you the strongest\n"
	.string "training routine of the region!$"

BattleFrontier_Lounge9_IV_Text_CustomizeIVs:
	.string "Would you like to set the IVs to\n"
	.string "a certain value to allow different\l"
	.string "HIDDEN POWER types?\p"
	.string "Or should I set all IVs to 31?$"

BattleFrontier_Lounge9_IV_Text_CustomizeIVs_SetType:
	.string "Which type of HIDDEN POWER are you\n"
	.string "looking for?$"

EventScript_IVSetter_Type_Fighting:
	.string "FIGHTING TYPE$"

EventScript_IVSetter_Type_Flying:
	.string "FLYING TYPE$"

EventScript_IVSetter_Type_Poison:
	.string "POISON TYPE$"

EventScript_IVSetter_Type_Ground:
	.string "GROUND TYPE$"

EventScript_IVSetter_Type_Rock:
	.string "ROCK TYPE$"

EventScript_IVSetter_Type_Bug:
	.string "BUG TYPE$"

EventScript_IVSetter_Type_Ghost:
	.string "GHOST TYPE$"

EventScript_IVSetter_Type_Steel:
	.string "STEEL TYPE$"

EventScript_IVSetter_Type_Fairy:
	.string "FAIRY TYPE$"

EventScript_IVSetter_Type_Fire:
	.string "FIRE TYPE$"

EventScript_IVSetter_Type_Water:
	.string "WATER TYPE$"

EventScript_IVSetter_Type_Grass:
	.string "GRASS TYPE$"

EventScript_IVSetter_Type_Electric:
	.string "ELECTRIC TYPE$"

EventScript_IVSetter_Type_Psychic:
	.string "PSYCHIC TYPE$"

EventScript_IVSetter_Type_Ice:
	.string "ICE TYPE$"

EventScript_IVSetter_Type_Dragon:
	.string "DRAGON TYPE$"

EventScript_IVSetter_Type_Dark:
	.string "DARK TYPE$"

BattleFrontier_Lounge9_IV_Text_SetMaxQuestion:
	.string "Then, I will set all IVs to the maximum\n"
	.string "value, which is 31. Should I continue?$"

BattleFrontier_Lounge9_IV_TextFirstTime:
    .string "Hey! It's you! Great to\n"
    .string "see you around here!\p"
    .string "Wait… You don't know me?\p"
    .string ". . .\p"
    .string ". . .\p"
    .string "Oh, right! I saw you on TV not\n"
    .string "long ago!\p"
    .string "I'm IVAN, but you can call me\n"
    .string "IV-MAN!\p"
    .string "Yes, I'm the brother of EV-MAN.\n"
    .string "no surprise there.\p"
    .string "And you…\p"
    .string "You're {PLAYER}, the one who\n"
    .string "recently won the POKéMON LEAGUE!\p"
    .string "Your last battle was amazing.\n"
    .string "I learned so much from watching you\n"
    .string "that I joined your FAN CLUB!\p"
    .string "After that, I decided to get\n"
    .string "stronger myself, so I created the\n"
    .string "ultimate training routine.\p"
    .string "For POKéMON, of course!\n"
    .string "If you want, we can train together to\n"
    .string "maximize your POKéMON's potential.\p"
    .string "But… to endure this training, a\n"
    .string "POKéMON must be fully prepared.\p"
    .string "Only those who have reached the\n"
    .string "MAXIMUM LEVEL can withstand it.\p"
    .string "Do you want to try it?\p"
    .string "It's a tough and lengthy process,\n"
    .string "so I need 100,000¥ to set it up.\p"
    .string "Just tell me when you're ready!$"

BattleFrontier_Lounge9_IV_Text1:
	.string "IV-MAN: Hi! Are you here for the ultimate\n"
	.string "training routine in all of HOENN?\p"
	.string "It costs 100.000¥, but it's worth it!\n"
	.string "Shall we begin?$"

BattleFrontier_Lounge9_IV_Text_No:
	.string "Oh… Well, see you another time.$"

BattleFrontier_Lounge9_IV_Text_NoLevel:
	.string "I don't think your POKéMON has reached\n"
	.string "its maximum LEVEL…$"

BattleFrontier_Lounge9_IV_Finish:
	.string "Phew… I'm exhausted…\n"
	.string "What about your POKéMON?\p"
	.string "You should rest a bit before going.\p"
	.string "Well, see you soon!$"

@Chansey training

BattleFrontier_Lounge9_Nurse::
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, BattleFrontier_Lounge9_NurseChampion
	msgbox BattleFrontier_Lounge9_NurseRepeat2, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_Lounge9_Chansey1End
	case YES, BattleFrontier_Lounge9_NurseBattle
	case MULTI_B_PRESSED, BattleFrontier_Lounge9_Chansey1End

BattleFrontier_Lounge9_NurseBattle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JOEY, 0, BattleFrontier_Lounge9_NurseIntro, BattleFrontier_Lounge9_NurseDefeat, BattleFrontier_Lounge9_ChanseyBattleAgain
	end

BattleFrontier_Lounge9_Chansey1End::
	closemessage
	end

BattleFrontier_Lounge9_ChanseyBattleAgain::
	faceplayer
	msgbox BattleFrontier_Lounge9_NurseRepeat, MSGBOX_AUTOCLOSE
	clearflag 0x85B
	end

BattleFrontier_Lounge9_NurseChampion:
	faceplayer
	msgbox BattleFrontier_Lounge9_NurseChampionText, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge9_NurseChampionText:
	.string "I'm the EXPERIENCE NURSE!\n"
	.string "Unfortunately, I can't battle you\l"
	.string "unless you become the CHAMPION.$"

BattleFrontier_Lounge9_NurseIntro:
	.string "Let's go, BLISSEY!$"

BattleFrontier_Lounge9_NurseDefeat:
	.string "Oh no… BLISSEY, use SOFT-BOILED!$"

BattleFrontier_Lounge9_NurseRepeat:
	.string "If you want, we can battle again!$"

BattleFrontier_Lounge9_NurseRepeat2:
	.string "Ready for a battle?$"

@Ability swapper

BattleFrontier_Lounge9_Ability_Man::
	lockall
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, BattleFrontier_Lounge9_Ability_ManNoChampion
	msgbox BattleFrontier_Lounge9_Ability_Text1, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_Ability_CheckMoney
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_Ability_No
	end

BattleFrontier_Lounge9_Ability_ManNoChampion::
	msgbox BattleFrontier_Lounge9_Ability_Text_NoChampion, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

BattleFrontier_Lounge9_Ability_No:
	msgbox BattleFrontier_Lounge9_Ability_Text_No, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

BattleFrontier_Lounge9_Ability_CheckMoney:
	checkmoney 25000, 0
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_Lounge9_Ability_Continue
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroNoMoney
	end

BattleFrontier_Lounge9_Ability_Continue:
	closemessage
	special ChoosePartyMon
	waitstate
	special SwitchMonAbility
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_Lounge9_Ability_Finish
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_Lounge9_Ability_Cant
	end

BattleFrontier_Lounge9_Ability_Cant:
	msgbox BattleFrontier_Lounge9_Ability_Text_Cant, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

BattleFrontier_Lounge9_Ability_Finish:
	fadescreen 0x1
	delay 100
	fadescreen 0x0
	faceplayer
	waitse
	playse SE_EXP_MAX
	msgbox BattleFrontier_Lounge9_Ability_Finish_Text, MSGBOX_DEFAULT
	removemoney 25000, 0
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_Ability_Finish_Text:
	.string "That's it! You're welcome!$"

BattleFrontier_Lounge9_Ability_Text1:
	.string "Welcome! I'm the ABILITY EXPERT!\p"
	.string "I can swap POKéMON's abilities in\n"
	.string "a heartbeat, only for 25.000¥!\p"
	.string "Would you like me to swap any\n"
	.string "POKéMON's ability?$"

BattleFrontier_Lounge9_Ability_Text_No:
	.string "Sure. I'll be here if you need me.$"

BattleFrontier_Lounge9_Ability_Text_Cant:
	.string "I cannot do that. This POKéMON\n"
	.string "does not have a second ABILITY!$"

BattleFrontier_Lounge9_Ability_Text_NoChampion:
	.string "Welcome! I'm the ABILITY EXPERT!\p"
	.string "I can swap POKéMON's abilities\n"
	.string "in a heartbeat.\p"
	.string "Unfortunately, my back hurts and\n"
	.string "I can't work today.\p"
	.string "Come again later!$"

