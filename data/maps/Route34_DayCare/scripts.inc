.set LOCALID_DAYCARE_LADY, 1

Route34_DayCare_MapScripts::
	.byte 0

Route34_DayCare_Bookshelf1::
	msgbox Route34_DayCare_Text_Bookshelf1, MSGBOX_SIGN
	end

Route34_DayCare_Bookshelf2::
	msgbox Route34_DayCare_Text_Bookshelf2, MSGBOX_SIGN
	end

Route34_DayCare_Bookshelf3::
	msgbox Route34_DayCare_Text_Bookshelf3, MSGBOX_SIGN
	end

Route34_DayCare_Bookshelf4::
	msgbox Route34_DayCare_Text_Bookshelf4, MSGBOX_SIGN
	end

Route34_DayCare_Text_Bookshelf1:
	.string "A dictionary!\p"
	.string "{PLAYER} opened the dictionary to\n"
	.string "a random page.\p"
	.string "'BABE'\n"
	.string "A noun, meaning infant or baby.\p"
	.string "{PLAYER} put away the dictionary.$"

Route34_DayCare_Text_Bookshelf2:
	.string "A book about POKéMON!\p"
	.string "{PLAYER} flipped through\n"
	.string "the book.\p"
	.string "It must have the word\n"
	.string "POKéMON written on every page.\p"
	.string "{PLAYER} put away the book.$"

Route34_DayCare_Text_Bookshelf3:
	.string "A book of word assocations!\p"
	.string "{PLAYER} flipped through\n"
	.string "the book.\p"
	.string "PICHU -> CUTE\l"
	.string "CLEFFA -> CUTE\l"
	.string "IGGLYBUFF -> SONG\l"
	.string "TYROGUE -> FIGHTING\l"
	.string "SMOOCHUM -> ICE\l"
	.string "ELEKID -> ELECTRIC\l"
	.string "MAGBY -> FIRE\p"
	.string "{PLAYER} put away the book.$"

Route34_DayCare_Text_Bookshelf4:
	.string "A book of POKéMON abilities!\p"
	.string "{PLAYER} flipped through\n"
	.string "the book.\p"
	.string "PICHU -> STATIC\l"
	.string "CLEFFA -> CUTE CHARM\l"
	.string "IGGLYBUFF -> CUTE CHARM\l"
	.string "TYROGUE -> GUTS\l"
	.string "SMOOCHUM -> OBLIVIOUS\l"
	.string "ELEKID -> STATIC\l"
	.string "MAGBY -> FLAME BODY\p"
	.string "{PLAYER} put away the book.$"

Route34_DayCare_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_ODD_EGG, Route34_DayCare_EventScript_ClerkAfter
	msgbox Route34_DayCare_Text_ClerkBefore, MSGBOX_DEFAULT
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, Route34_DayCare_EventScript_ClerkPartyFull
	msgbox Route34_DayCare_Text_ClerkQuestion, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_INTERVIEW
	setvar VAR_0x8005, 0
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	switch VAR_RESULT
	case 0, Route34_DayCare_EventScript_ClerkRejection
	case 1, Route34_DayCare_EventScript_GivePichu
	case 2, Route34_DayCare_EventScript_GiveCleffa
	case 3, Route34_DayCare_EventScript_GiveIgglybuff
	case 4, Route34_DayCare_EventScript_GiveTyrogue
	case 5, Route34_DayCare_EventScript_GiveSmoochum
	case 6, Route34_DayCare_EventScript_GiveElekid
	case 7, Route34_DayCare_EventScript_GiveMagby
	closemessage
	release
	end

Route34_DayCare_EventScript_GivePichu::
	giveoddegg 1
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveCleffa::
	giveoddegg 2
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveIgglybuff::
	giveoddegg 3
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveTyrogue::
	giveoddegg 4
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveSmoochum::
	giveoddegg 5
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveElekid::
	giveoddegg 6
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveMagby::
	giveoddegg 7
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_Clerk_GaveEgg::
	msgbox Route34_DayCare_Text_TakeCare, MSGBOX_DEFAULT
	closemessage
	delay 30
	setflag FLAG_RECEIVED_ODD_EGG
	playfanfare MUS_OBTAIN_ITEM
	message Route34_DayCare_Text_ReceivedOddEgg
	waitfanfare
	closemessage
	release
	end

Route34_DayCare_EventScript_ClerkPartyFull::
	msgbox Route34_DayCare_Text_ClerkNoRoom, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34_DayCare_EventScript_ClerkRejection::
	msgbox Route34_DayCare_Text_Rejection, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34_DayCare_EventScript_ClerkAfter::
	msgbox Route34_DayCare_Text_ClerkAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34_DayCare_Text_ClerkBefore:
	.string "I'm the DAY-CARE couple's son.\p"
	.string "An ODD EGG was found with a TRAINER's\n"
	.string "POKéMON, but they didn't want it...\p"
	.string "I'd offer it to you...\n"
	.string "But how can I know you'll take good\l"
	.string "care of it?$"

Route34_DayCare_Text_ClerkNoRoom:
	.string "It looks like you can't carry another\n"
	.string "POKéMON anyway.$"

Route34_DayCare_Text_ClerkQuestion:
	.string "Answer this question for me.\n"
	.string "How do you feel about this ODD EGG?$"

Route34_DayCare_Text_Rejection:
	.string "Hmm, I think this EGG isn't for you.\p"
	.string "It would be irresponsible of me to\n"
	.string "give out a precious EGG like this\l"
	.string "to someone who isn't as well-read\l"
	.string "on the subject of Pokémon breeding!$"

Route34_DayCare_Text_ReceivedOddEgg:
	.string "{PLAYER} Received the ODD EGG.$"

Route34_DayCare_Text_TakeCare:
	.string "I knew you were the right trainer\n"
	.string "for the job. Take good care of it!$"

Route34_DayCare_Text_ClerkAfter:
	.string "We see a lot of those eggs around\n"
	.string "here.\p"
	.string "Something was different about that\n"
	.string "one, though.$"

Route34_DayCare_EventScript_Ditto::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DITTO, CRY_MODE_NORMAL
	msgbox Route34_DayCare_Text_Ditto, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route34_DayCare_Text_Ditto:
	.string "DITTO: Tto!$"

Route34_EventScript_DaycareMan::
	lock
	faceplayer
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_EventScript_DaycareEggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_EventScript_CheckOnOneMon
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route34_EventScript_CheckOnTwoMons
	msgbox Route34_Text_SeeWifeIfYoudLikeMeToRaiseMon, MSGBOX_DEFAULT
	release
	end

Route34_EventScript_DaycareEggWaiting::
	msgbox Route34_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_EventScript_DaycareAcceptEgg
	msgbox Route34_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_EventScript_DaycareAcceptEgg
	msgbox Route34_Text_IllKeepIt, MSGBOX_DEFAULT
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	release
	end

Route34_EventScript_DaycareAcceptEgg::
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, VAR_0x8004, Route34_EventScript_DaycareReceiveEgg
	msgbox Route34_Text_YouHaveNoRoomForIt, MSGBOX_DEFAULT
	release
	end

Route34_EventScript_DaycareReceiveEgg::
	message Route34_Text_ReceivedEgg
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	msgbox Route34_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	release
	end

Route34_EventScript_CheckMonReceivedMail::
	specialvar VAR_RESULT, CheckDaycareMonReceivedMail
	call_if_eq VAR_RESULT, 1, Route34_EventScript_MonReceivedMail
	return

Route34_EventScript_MonReceivedMail::
	msgbox Route34_Text_FriendlyWithOtherTrainersMon, MSGBOX_DEFAULT
	return

Route34_EventScript_CheckOnOneMon::
	special GetDaycareMonNicknames
	msgbox Route34_Text_YourMonIsDoingFine, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route34_EventScript_CheckMonReceivedMail
	release
	end

Route34_EventScript_CheckOnTwoMons::
	special GetDaycareMonNicknames
	msgbox Route34_Text_YourMonsAreDoingFine, MSGBOX_DEFAULT
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 0
	call Route34_EventScript_CheckMonReceivedMail
	setvar VAR_0x8004, 1
	call Route34_EventScript_CheckMonReceivedMail
	release
	end

Route34_DayCare_EventScript_DaycareWoman::
	lock
	faceplayer
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_DayCare_EventScript_EggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_OneMonInDaycare
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route34_DayCare_EventScript_TwoMonsInDaycare
	msgbox Route34_DayCare_Text_WouldYouLikeUsToRaiseAMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_GiveMonToRaise
	msgbox Route34_DayCare_Text_FineThenComeAgain, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_GiveMonToRaise::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_eq VAR_RESULT, 1, Route34_DayCare_EventScript_OnlyOneMon
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
	goto_if_eq VAR_RESULT, 2, Route34_DayCare_EventScript_OnlyTwoAliveMons
	msgbox Route34_DayCare_Text_WhichMonShouldWeRaise, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseSendDaycareMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route34_DayCare_EventScript_ComeAgain
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	goto_if_eq VAR_RESULT, 0, Route34_DayCare_EventScript_OnlyOneAliveMon
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox Route34_DayCare_Text_WellRaiseYourMon, MSGBOX_DEFAULT
	waitmoncry
	special StoreSelectedPokemonInDaycare
	callnative UpdateFollowingPokemon
	incrementgamestat GAME_STAT_USED_DAYCARE
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_CanRaiseOneMore
	release
	end

Route34_DayCare_EventScript_ComeAgain::
	msgbox Route34_DayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_CanRaiseOneMore::
	msgbox Route34_DayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_GiveMonToRaise
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_OnlyOneMon::
	msgbox Route34_DayCare_Text_YouHaveJustOneMon, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_OnlyOneAliveMon::
	msgbox Route34_DayCare_Text_WhatWillYouBattleWith, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_OnlyTwoAliveMons::
	msgbox Route34_DayCare_Text_YoullBeLeftWithJustOne, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_EggWaiting::
	msgbox Route34_DayCare_Text_HusbandWasLookingForYou, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_YourMonHasGrownXLevels::
	msgbox Route34_DayCare_Text_YourMonHasGrownXLevels, MSGBOX_DEFAULT
	return

Route34_DayCare_EventScript_DisplayLevelsGained::
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	call_if_ne VAR_RESULT, 0, Route34_DayCare_EventScript_YourMonHasGrownXLevels
	return

Route34_DayCare_EventScript_OneMonInDaycare::
	msgbox Route34_DayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route34_DayCare_EventScript_DisplayLevelsGained
	msgbox Route34_DayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_GiveMonToRaise
	msgbox Route34_DayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_TryRetrieveMon
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_TryRetrieveMon::
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, VAR_0x8004, Route34_DayCare_EventScript_NoRoom
	specialvar VAR_RESULT, GetDaycareState
	setvar VAR_0x8004, 0
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_CostPrompt
	special ShowDaycareLevelMenu
	waitstate
	copyvar VAR_0x8004, VAR_RESULT
	goto_if_eq VAR_RESULT, DAYCARE_EXITED_LEVEL_MENU, Route34_DayCare_EventScript_ComeAgain
	goto Route34_DayCare_EventScript_CostPrompt
	end

Route34_DayCare_EventScript_CostPrompt::
	special GetDaycareCost
	msgbox Route34_DayCare_Text_ItWillCostX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_CheckEnoughMoney
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_CheckEnoughMoney::
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	goto_if_eq VAR_RESULT, 1, Route34_DayCare_EventScript_RetrieveMon
	msgbox Route34_DayCare_Text_NotEnoughMoney, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_RetrieveMon::
	@applymovement LOCALID_DAYCARE_LADY, Route34_DayCare_Movement_RetrieveDaycareMon
	@waitmovement 0
	specialvar VAR_RESULT, TakePokemonFromDaycare
	special SubtractMoneyFromVar0x8005
	playse SE_SHOP
	msgbox Route34_DayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	waitse
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	msgbox Route34_DayCare_Text_TookBackMon, MSGBOX_DEFAULT
	waitmoncry
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_AskRetrieveOtherMon
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_AskRetrieveOtherMon::
	msgbox Route34_DayCare_Text_TakeOtherOneBackToo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_TryRetrieveMon
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_NoRoom::
	msgbox Route34_DayCare_Text_YourTeamIsFull, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_Movement_RetrieveDaycareMon:
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_up
	walk_slow_up
	set_invisible
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	set_visible
	walk_slow_down
	step_end

@ Unused. Possibly a commented script, or a typo end added to the above Movement script
Route34_DayCare_EventScript_UnusedEnd::
	end

Route34_DayCare_EventScript_TwoMonsInDaycare::
	msgbox Route34_DayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route34_DayCare_EventScript_DisplayLevelsGained
	setvar VAR_0x8004, 1
	call Route34_DayCare_EventScript_DisplayLevelsGained
	msgbox Route34_DayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_TryRetrieveMon
	msgbox Route34_DayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route34_Text_SeeWifeIfYoudLikeMeToRaiseMon:
	.string "I'm the DAY-CARE MAN.\p"
	.string "I help take care of the precious\n"
	.string "POKéMON of TRAINERS.\p"
	.string "If you'd like me to raise your POKéMON,\n"
	.string "have a word with my wife.$"

Route34_Text_DoYouWantEgg:
	.string "Ah, it's you!\p"
	.string "We were raising your POKéMON,\n"
	.string "and my goodness, were we surprised!\p"
	.string "Your POKéMON had an EGG!\p"
	.string "We don't know how it got there,\n"
	.string "but your POKéMON had it.\p"
	.string "You do want it, yes?$"

Route34_Text_YourMonIsDoingFine:
	.string "Ah, it's you! Good to see you.\n"
	.string "Your {STR_VAR_1}'s doing fine.$"

Route34_Text_IllKeepIt:
	.string "Well then, I'll keep it.\n"
	.string "Thanks!$"

Route34_Text_YouHaveNoRoomForIt:
	.string "You have no room for it…\n"
	.string "Come back when you've made room.$"

Route34_Text_ReceivedEgg:
	.string "{PLAYER} received the EGG from\n"
	.string "the DAY-CARE MAN.$"

Route34_Text_TakeGoodCareOfIt:
	.string "Take good care of it.$"

Route34_Text_FriendlyWithOtherTrainersMon:
	.string "By the way, about your {STR_VAR_1},\n"
	.string "it seemed to be friendly with\l"
	.string "{STR_VAR_2}'s {STR_VAR_3}.\p"
	.string "I may even have seen it receiving\n"
	.string "a piece of MAIL.$"

@ Unused
Route34_Text_SeeWifeIfYouWantToPickUpMon:
	.string "If you want to pick up your POKéMON,\n"
	.string "have a word with my wife.$"

Route34_Text_YourMonsAreDoingFine:
	.string "Ah, it's you! Your {STR_VAR_1} and\n"
	.string "{STR_VAR_2} are doing fine.$"

Route34_Text_IWillKeepDoYouWantIt:
	.string "I really will keep it.\n"
	.string "You do want this, yes?$"

Route34_DayCare_Text_WouldYouLikeUsToRaiseAMon:
	.string "I'm the DAY-CARE LADY.\p"
	.string "We can raise POKéMON for you.\p"
	.string "Would you like us to raise one?$"

Route34_DayCare_Text_WhichMonShouldWeRaise:
	.string "Which POKéMON should we raise for\n"
	.string "you?$"

Route34_DayCare_Text_WellRaiseYourMon:
	.string "Fine, we'll raise your {STR_VAR_1}\n"
	.string "for a while.\p"
	.string "Come back for it later.$"

Route34_DayCare_Text_WeCanRaiseOneMore:
	.string "We can raise two of your POKéMON.\n"
	.string "Would you like us to raise one more?$"

Route34_DayCare_Text_HusbandWasLookingForYou:
	.string "My husband was looking for you.$"

Route34_DayCare_Text_FineThenComeAgain:
	.string "Oh, fine, then.\n"
	.string "Come again.$"

Route34_DayCare_Text_NotEnoughMoney:
	.string "You don't have enough money…$"

Route34_DayCare_Text_TakeOtherOneBackToo:
	.string "Will you take back the other one,\n"
	.string "too?$"

Route34_DayCare_Text_ComeAgain:
	.string "Fine.\n"
	.string "Come again.$"

Route34_DayCare_Text_GoodToSeeYou:
	.string "Ah, it's you! Good to see you.\n"
	.string "Your POKéMON can only be doing good!$"

Route34_DayCare_Text_YourMonHasGrownXLevels:
	.string "By level, your {STR_VAR_1} has\n"
	.string "grown by {STR_VAR_2}.$"

Route34_DayCare_Text_YourTeamIsFull:
	.string "Your POKéMON team is full.\n"
	.string "Make room, then come see me.$"

@ Unused
Route34_DayCare_Text_TakeBackWhichMon:
	.string "Which POKéMON will you take back?$"

Route34_DayCare_Text_ItWillCostX:
	.string "If you want your {STR_VAR_1} back,\n"
	.string "it will cost ¥{STR_VAR_2}.$"

Route34_DayCare_Text_HeresYourMon:
	.string "Perfect!\n"
	.string "Here's your POKéMON.$"

Route34_DayCare_Text_TookBackMon:
	.string "{PLAYER} took back {STR_VAR_1} from\n"
	.string "the DAY-CARE LADY.$"

Route34_DayCare_Text_YouHaveJustOneMon:
	.string "Oh? But you have just one\n"
	.string "POKéMON.\p"
	.string "Come back another time.$"

Route34_DayCare_Text_TakeYourMonBack:
	.string "Will you take your POKéMON back?$"

Route34_DayCare_Text_WhatWillYouBattleWith:
	.string "If you leave me that POKéMON,\n"
	.string "what will you battle with?\p"
	.string "Come back another time.$"

Route34_DayCare_Text_YoullBeLeftWithJustOne:
	.string "Huh?\n"
	.string "Now, now.\p"
	.string "If you leave that POKéMON with\n"
	.string "me, you'll be left with just one.\p"
	.string "You will be better off if you catch\n"
	.string "some more, I dare say.$"
