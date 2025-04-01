.set LOCALID_LILYCOVE_LADY, 4
.set LOCALID_LADYS_MON, 5

LilycoveCity_PokemonCentre_1F_EventScript_LilycoveLady::
	special Script_GetLilycoveLadyId
	switch VAR_RESULT
	case LILYCOVE_LADY_QUIZ, LilycoveCity_PokemonCentre_1F_EventScript_QuizLady
	case LILYCOVE_LADY_FAVOUR, LilycoveCity_PokemonCentre_1F_EventScript_FavourLady
	case LILYCOVE_LADY_CONTEST, LilycoveCity_PokemonCentre_1F_EventScript_ContestLady
	end

LilycoveCity_PokemonCentre_1F_EventScript_FavourLady::
	lock
	faceplayer
	msgbox LilycoveCity_PokemonCentre_1F_Text_ImTheFavourLady, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetFavourLadyState
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_READY, LilycoveCity_PokemonCentre_1F_EventScript_FavourLadyReady
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_COMPLETED, LilycoveCity_PokemonCentre_1F_EventScript_FavourLadyCompleted
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_PRIZE, LilycoveCity_PokemonCentre_1F_EventScript_FavourLadyPrize
	end

LilycoveCity_PokemonCentre_1F_EventScript_FavourLadyCompleted::
	msgbox LilycoveCity_PokemonCentre_1F_Text_ThankYouForLastTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCentre_1F_EventScript_FavourLadyReady::
	special BufferFavourLadyRequest
	msgbox LilycoveCity_PokemonCentre_1F_Text_ObsessedWithThing, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasAnotherPlayerGivenFavourLadyItem
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCentre_1F_EventScript_RequestItem
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCentre_1F_EventScript_TellAboutPlayersItem
	end

LilycoveCity_PokemonCentre_1F_EventScript_TellAboutPlayersItem::
	special BufferFavourLadyItemName
	special BufferFavourLadyPlayerName
	specialvar VAR_RESULT, DidFavourLadyLikeItem
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCentre_1F_EventScript_PlayerGaveBadThing
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCentre_1F_EventScript_PlayerGaveGreatThing
	end

LilycoveCity_PokemonCentre_1F_EventScript_PlayerGaveBadThing::
	msgbox LilycoveCity_PokemonCentre_1F_Text_PlayerGaveMeBadThing, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCentre_1F_EventScript_RequestItem
	end

LilycoveCity_PokemonCentre_1F_EventScript_PlayerGaveGreatThing::
	msgbox LilycoveCity_PokemonCentre_1F_Text_PlayerGaveMeGreatThing, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCentre_1F_EventScript_RequestItem
	end

LilycoveCity_PokemonCentre_1F_EventScript_RequestItem::
	msgbox LilycoveCity_PokemonCentre_1F_Text_WillYouShareThing, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCentre_1F_EventScript_DeclineFavour
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCentre_1F_EventScript_AcceptFavour
	end

LilycoveCity_PokemonCentre_1F_EventScript_DeclineFavour::
	msgbox LilycoveCity_PokemonCentre_1F_Text_IsThatSoGoodbye, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCentre_1F_EventScript_AcceptFavour::
	msgbox LilycoveCity_PokemonCentre_1F_Text_WhatWillYouGiveMe, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCentre_1F_EventScript_ChooseFavourItem
	end

LilycoveCity_PokemonCentre_1F_EventScript_ChooseFavourItem::
	fadescreen FADE_TO_BLACK
	setvar VAR_RESULT, 0
	special Script_FavourLadyOpenBagMenu
	waitstate
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCentre_1F_EventScript_AskQuitChooseFavourItem
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCentre_1F_EventScript_GiveFavourItem
	end

LilycoveCity_PokemonCentre_1F_EventScript_AskQuitChooseFavourItem::
	msgbox LilycoveCity_PokemonCentre_1F_Text_NotWillingToShare, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCentre_1F_EventScript_DeclineFavour
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCentre_1F_EventScript_ChooseFavourItem
	end

LilycoveCity_PokemonCentre_1F_EventScript_GiveFavourItem::
	specialvar VAR_RESULT, Script_DoesFavourLadyLikeItem
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCentre_1F_EventScript_DidntLikeFavourItem
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCentre_1F_EventScript_CheckLovedItem
	end

LilycoveCity_PokemonCentre_1F_EventScript_DidntLikeFavourItem::
	special BufferFavourLadyRequest
	msgbox LilycoveCity_PokemonCentre_1F_Text_IllTryToCherishIt, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCentre_1F_EventScript_CheckLovedItem::
	specialvar VAR_RESULT, IsFavourLadyThresholdMet
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCentre_1F_EventScript_LikedFavourItem
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCentre_1F_EventScript_LovedFavourItem
	end

LilycoveCity_PokemonCentre_1F_EventScript_LikedFavourItem::
	special BufferFavourLadyRequest
	msgbox LilycoveCity_PokemonCentre_1F_Text_IWillCherishThis, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCentre_1F_EventScript_LovedFavourItem::
	special BufferFavourLadyRequest
	msgbox LilycoveCity_PokemonCentre_1F_Text_IWillTreasureThis, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCentre_1F_EventScript_FavourLadyPrize
	end

LilycoveCity_PokemonCentre_1F_EventScript_FavourLadyPrize::
	setvar VAR_0x8004, 0
	specialvar VAR_0x8004, FavourLadyGetPrize
	msgbox LilycoveCity_PokemonCentre_1F_Text_IllGiveYouThisInReturn, MSGBOX_DEFAULT
	giveitem VAR_0x8004
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCentre_1F_EventScript_NoRoomForFavourPrize
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCentre_1F_EventScript_ReceivedFavourPrize
	end

LilycoveCity_PokemonCentre_1F_EventScript_NoRoomForFavourPrize::
	msgbox LilycoveCity_PokemonCentre_1F_Text_YouDontHaveSpaceForIt, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCentre_1F_EventScript_ReceivedFavourPrize::
	special SetFavourLadyState_Complete
	release
	end

LilycoveCity_PokemonCentre_1F_EventScript_QuizLady::
	lock
	faceplayer
	msgbox LilycoveCity_PokemonCentre_1F_Text_ImTheQuizLady, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetQuizLadyState
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_READY, LilycoveCity_PokemonCentre_1F_EventScript_HasQuiz
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_COMPLETED, LilycoveCity_PokemonCentre_1F_EventScript_CheckMadeQuiz
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_PRIZE, LilycoveCity_PokemonCentre_1F_EventScript_ReadyGivePrize
	end

LilycoveCity_PokemonCentre_1F_EventScript_HasQuiz::
	specialvar VAR_RESULT, GetQuizAuthor
	goto_if_eq VAR_RESULT, QUIZ_AUTHOR_PLAYER, LilycoveCity_PokemonCentre_1F_EventScript_WaitingToTakeYourQuiz
	goto_if_eq VAR_RESULT, QUIZ_AUTHOR_OTHER_PLAYER, LilycoveCity_PokemonCentre_1F_EventScript_PlayerQuizReady
	goto_if_eq VAR_RESULT, QUIZ_AUTHOR_LADY, LilycoveCity_PokemonCentre_1F_EventScript_LadyQuizReady
	end

LilycoveCity_PokemonCentre_1F_EventScript_CheckMadeQuiz::
	specialvar VAR_RESULT, IsQuizLadyWaitingForChallenger
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCentre_1F_EventScript_AskMakeQuiz
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCentre_1F_EventScript_WaitingToTakeYourQuiz
	end

LilycoveCity_PokemonCentre_1F_EventScript_WaitingToTakeYourQuiz::
	msgbox LilycoveCity_PokemonCentre_1F_Text_WaitingToTakeYourQuiz, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCentre_1F_EventScript_PlayerQuizReady::
	msgbox LilycoveCity_PokemonCentre_1F_Text_WaitingForChallenger, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCentre_1F_EventScript_AskTakeQuiz
	end

LilycoveCity_PokemonCentre_1F_EventScript_LadyQuizReady::
	msgbox LilycoveCity_PokemonCentre_1F_Text_WaitingForChallenger, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCentre_1F_EventScript_AskTakeQuiz
	end

LilycoveCity_PokemonCentre_1F_EventScript_AskTakeQuiz::
	setvar VAR_0x8004, 0
	msgbox LilycoveCity_PokemonCentre_1F_Text_TakeQuizChallenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCentre_1F_EventScript_TakeQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCentre_1F_EventScript_DeclineQuiz
	end

LilycoveCity_PokemonCentre_1F_EventScript_DeclineQuiz::
	msgbox LilycoveCity_PokemonCentre_1F_Text_HowBoringBye, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCentre_1F_EventScript_TakeQuiz::
	special ClearQuizLadyPlayerAnswer
	goto_if_eq VAR_0x8004, 0, LilycoveCity_PokemonCentre_1F_EventScript_ShowQuestion
	goto_if_eq VAR_0x8004, EASY_CHAT_TYPE_QUIZ_ANSWER, LilycoveCity_PokemonCentre_1F_EventScript_GetAnswer

LilycoveCity_PokemonCentre_1F_EventScript_CheckQuizTakingState::
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCentre_1F_EventScript_AskQuitQuiz
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCentre_1F_EventScript_SubmitQuizResponse
	end

LilycoveCity_PokemonCentre_1F_EventScript_ShowQuestion::
	special QuizLadyShowQuizQuestion
	waitstate
	goto LilycoveCity_PokemonCentre_1F_EventScript_CheckQuizTakingState
	end

LilycoveCity_PokemonCentre_1F_EventScript_GetAnswer::
	special QuizLadyGetPlayerAnswer
	waitstate
	goto LilycoveCity_PokemonCentre_1F_EventScript_CheckQuizTakingState
	end

LilycoveCity_PokemonCentre_1F_EventScript_AskQuitQuiz::
	msgbox LilycoveCity_PokemonCentre_1F_Text_YoureGoingToQuit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCentre_1F_EventScript_QuitTakingQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCentre_1F_EventScript_TakeQuiz
	end

LilycoveCity_PokemonCentre_1F_EventScript_QuitTakingQuiz::
	msgbox LilycoveCity_PokemonCentre_1F_Text_TakeTheQuizAnotherTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCentre_1F_EventScript_SubmitQuizResponse::
	special SetQuizLadyState_Complete
	msgbox LilycoveCity_PokemonCentre_1F_Text_WaitForAnswer, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsQuizAnswerCorrect
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCentre_1F_EventScript_IncorrectResponse
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCentre_1F_EventScript_CorrectResponse
	end

LilycoveCity_PokemonCentre_1F_EventScript_CorrectResponse::
	playse SE_SUCCESS
	delay 10
	playse SE_SUCCESS
	msgbox LilycoveCity_PokemonCentre_1F_Text_YouGotItRight, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCentre_1F_EventScript_ReadyGivePrize
	end

LilycoveCity_PokemonCentre_1F_EventScript_IncorrectResponse::
	special BufferQuizCorrectAnswer
	special BufferQuizPrizeName
	playse SE_FAILURE
	delay 10
	playse SE_FAILURE
	msgbox LilycoveCity_PokemonCentre_1F_Text_WrongTheCorrectAnswerIs, MSGBOX_DEFAULT
	msgbox LilycoveCity_PokemonCentre_1F_Text_IGetToKeepPrize, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCentre_1F_EventScript_AskMakeQuiz
	end

@ VAR_RESULT is essentially ignored, both jumps are identical
LilycoveCity_PokemonCentre_1F_EventScript_ReadyGivePrize::
	specialvar VAR_RESULT, BufferQuizAuthorNameAndCheckIfLady
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCentre_1F_EventScript_GivePrize1
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCentre_1F_EventScript_GivePrize0
	end

LilycoveCity_PokemonCentre_1F_EventScript_GivePrize1::
	msgbox LilycoveCity_PokemonCentre_1F_Text_YouGotItRightYouveWonPersonsPrize, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCentre_1F_EventScript_GivePrize
	end

LilycoveCity_PokemonCentre_1F_EventScript_GivePrize0::
	msgbox LilycoveCity_PokemonCentre_1F_Text_YouGotItRightYouveWonPersonsPrize, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCentre_1F_EventScript_GivePrize
	end

LilycoveCity_PokemonCentre_1F_EventScript_GivePrize::
	setvar VAR_0x8005, 0
	special BufferQuizPrizeItem
	special SetQuizLadyState_Complete
	giveitem VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCentre_1F_EventScript_NoSpaceForQuizPrize
	goto LilycoveCity_PokemonCentre_1F_EventScript_AskMakeQuiz
	end

LilycoveCity_PokemonCentre_1F_EventScript_NoSpaceForQuizPrize::
	msgbox LilycoveCity_PokemonCentre_1F_Text_YourBagIsFilledUp, MSGBOX_DEFAULT
	special SetQuizLadyState_GivePrize
	release
	end

LilycoveCity_PokemonCentre_1F_EventScript_AskMakeQuiz::
	msgbox LilycoveCity_PokemonCentre_1F_Text_MakeYourOwnQuiz, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCentre_1F_EventScript_MakeQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCentre_1F_EventScript_DeclineMakeQuiz
	end

LilycoveCity_PokemonCentre_1F_EventScript_DeclineMakeQuiz::
	special QuizLadyPickNewQuestion
	msgbox LilycoveCity_PokemonCentre_1F_Text_MaybeNextTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCentre_1F_EventScript_MakeQuiz::
	msgbox LilycoveCity_PokemonCentre_1F_Text_PickYourPrize, MSGBOX_DEFAULT
LilycoveCity_PokemonCentre_1F_EventScript_PickPrize::
	fadescreen FADE_TO_BLACK
	setvar VAR_RESULT, 0
	special Script_QuizLadyOpenBagMenu
	waitstate
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCentre_1F_EventScript_AskQuitChoosingPrize
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCentre_1F_EventScript_WriteQuiz
	end

LilycoveCity_PokemonCentre_1F_EventScript_AskQuitChoosingPrize::
	msgbox LilycoveCity_PokemonCentre_1F_Text_QuitChoosingPrize, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCentre_1F_EventScript_DeclineMakeQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCentre_1F_EventScript_PickPrize
	end

LilycoveCity_PokemonCentre_1F_EventScript_WriteQuiz::
	msgbox LilycoveCity_PokemonCentre_1F_Text_WriteYourQuiz, MSGBOX_DEFAULT
	special ClearQuizLadyQuestionAndAnswer
	special ClearQuizLadyPlayerAnswer
	setvar VAR_0x8004, EASY_CHAT_TYPE_QUIZ_QUESTION
LilycoveCity_PokemonCentre_1F_EventScript_WriteQuizQuestion::
	fadescreen FADE_TO_BLACK
	special QuizLadySetCustomQuestion
	waitstate
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCentre_1F_EventScript_AskQuitWritingQuizQuestion
	goto LilycoveCity_PokemonCentre_1F_EventScript_FinishMakingQuiz
	end

LilycoveCity_PokemonCentre_1F_EventScript_AskQuitWritingQuizQuestion::
	msgbox LilycoveCity_PokemonCentre_1F_Text_QuitWritingQuizQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCentre_1F_EventScript_DeclineMakeQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCentre_1F_EventScript_WriteQuizQuestion
	end

LilycoveCity_PokemonCentre_1F_EventScript_FinishMakingQuiz::
	special QuizLadyTakePrizeForCustomQuiz
	special QuizLadyRecordCustomQuizData
	special QuizLadySetWaitingForChallenger
	msgbox LilycoveCity_PokemonCentre_1F_Text_IllLookForAChallenger, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCentre_1F_EventScript_ContestLady::
	lock
	faceplayer
	msgbox LilycoveCity_PokemonCentre_1F_Text_ImTheContestLady, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasPlayerGivenContestLadyPokeblock
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCentre_1F_EventScript_NotGivenPokeblock
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCentre_1F_EventScript_GivenPokeblock
	end

@ Redundant with above script, VAR_RESULT will always be FALSE here
LilycoveCity_PokemonCentre_1F_EventScript_NotGivenPokeblock::
	specialvar VAR_RESULT, ShouldContestLadyShowGoOnAir
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCentre_1F_EventScript_AskForPokeblock
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCentre_1F_EventScript_GivenPokeblock
	end

LilycoveCity_PokemonCentre_1F_EventScript_GivenPokeblock::
	msgbox LilycoveCity_PokemonCentre_1F_Text_ThankForPokeblock, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCentre_1F_EventScript_AskForPokeblock::
	special Script_BufferContestLadyCategoryAndMonName
	msgbox LilycoveCity_PokemonCentre_1F_Text_MyFriendDisplaysQuality, MSGBOX_DEFAULT
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCentre_1F_EventScript_NoPokeblockCase
	msgbox LilycoveCity_PokemonCentre_1F_Text_AskingForOnePokeblock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCentre_1F_EventScript_DeclineGivePokeblock
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCentre_1F_EventScript_ChoosePokeblock
	end

LilycoveCity_PokemonCentre_1F_EventScript_DeclineGivePokeblock::
	msgbox LilycoveCity_PokemonCentre_1F_Text_WhatACheapskate, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCentre_1F_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseForContestLady
	waitstate
	goto_if_eq VAR_RESULT, 0xFFFF, LilycoveCity_PokemonCentre_1F_EventScript_AskQuitGivingPokeblock
	goto_if_ne VAR_RESULT, 0xFFFF, LilycoveCity_PokemonCentre_1F_EventScript_GivePokeblock
	end

LilycoveCity_PokemonCentre_1F_EventScript_AskQuitGivingPokeblock::
	msgbox LilycoveCity_PokemonCentre_1F_Text_ICantHaveOnePokeblock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCentre_1F_EventScript_DeclineGivePokeblock
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCentre_1F_EventScript_ChoosePokeblock
	end

LilycoveCity_PokemonCentre_1F_EventScript_GivePokeblock::
	msgbox LilycoveCity_PokemonCentre_1F_Text_IllUseYourPokeblock, MSGBOX_DEFAULT
	special SetContestLadyGivenPokeblock
	special GetContestLadyMonSpecies
	goto LilycoveCity_PokemonCentre_1F_EventScript_FeedPokeblock
	end

@ VAR_0x8004 here is the return value from GivePokeblockToContestLady
LilycoveCity_PokemonCentre_1F_EventScript_FeedPokeblock::
	applymovement LOCALID_LILYCOVE_LADY, LilycoveCity_PokemonCentre_1F_Movement_LadyFaceMon
	waitmovement 0
	delay 60
	applymovement LOCALID_LADYS_MON, LilycoveCity_PokemonCentre_1F_Movement_MonFaceLady
	waitmovement 0
	delay 60
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	delay 120
	waitmoncry
	goto_if_eq VAR_0x8004, 1, LilycoveCity_PokemonCentre_1F_EventScript_MonEnjoyPokeblock
	goto LilycoveCity_PokemonCentre_1F_EventScript_FinishFeedPokeblock
	end

@ VAR_0x8004 here is the return value from GivePokeblockToContestLady
LilycoveCity_PokemonCentre_1F_EventScript_MonEnjoyPokeblock::
	applymovement LOCALID_LADYS_MON, LilycoveCity_PokemonCentre_1F_Movement_MonJump
	waitmovement 0
	delay 60
LilycoveCity_PokemonCentre_1F_EventScript_FinishFeedPokeblock::
	applymovement LOCALID_LILYCOVE_LADY, LilycoveCity_PokemonCentre_1F_Movement_LadyFacePlayer
	waitmovement 0
	delay 60
	goto_if_eq VAR_0x8004, 0, LilycoveCity_PokemonCentre_1F_EventScript_MonDislikedPokeblock
	goto_if_eq VAR_0x8004, 1, LilycoveCity_PokemonCentre_1F_EventScript_MonLikedPokeblock
	end

LilycoveCity_PokemonCentre_1F_EventScript_MonDislikedPokeblock::
	msgbox LilycoveCity_PokemonCentre_1F_Text_NoChangeThanks, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCentre_1F_EventScript_CheckAirContestLadyShow
	end

LilycoveCity_PokemonCentre_1F_EventScript_MonLikedPokeblock::
	special Script_BufferContestLadyCategoryAndMonName
	msgbox LilycoveCity_PokemonCentre_1F_Text_ReallyImprovedThanks, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCentre_1F_EventScript_CheckAirContestLadyShow
	end

LilycoveCity_PokemonCentre_1F_EventScript_CheckAirContestLadyShow::
	specialvar VAR_RESULT, ShouldContestLadyShowGoOnAir
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCentre_1F_EventScript_AirContestLadyShow
	release
	end

LilycoveCity_PokemonCentre_1F_EventScript_AirContestLadyShow::
	msgbox LilycoveCity_PokemonCentre_1F_Text_ReadyToEnterContests, MSGBOX_DEFAULT
	special PutLilycoveContestLadyShowOnTheAir
	release
	end

LilycoveCity_PokemonCentre_1F_EventScript_NoPokeblockCase::
	msgbox LilycoveCity_PokemonCentre_1F_Text_DontHaveAPokeblockCase, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCentre_1F_Movement_LadyFaceMon:
	face_right
	delay_8
	step_end

LilycoveCity_PokemonCentre_1F_Movement_MonFaceLady:
	face_left
	delay_8
	step_end

@ Unused
LilycoveCity_PokemonCentre_1F_Movement_MonFaceDown:
	face_down
	step_end

LilycoveCity_PokemonCentre_1F_Movement_LadyFacePlayer:
	face_player
	step_end

LilycoveCity_PokemonCentre_1F_Movement_MonJump:
	disable_jump_landing_ground_effect
	jump_in_place_left
	disable_jump_landing_ground_effect
	jump_in_place_left
	step_end

LilycoveCity_PokemonCentre_1F_EventScript_ContestLadyMon::
	specialvar VAR_RESULT, GetContestLadyCategory
	special Script_BufferContestLadyCategoryAndMonName
	special GetContestLadyMonSpecies
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_COOL, LilycoveCity_PokemonCentre_1F_EventScript_Zigzagoon
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_BEAUTY, LilycoveCity_PokemonCentre_1F_EventScript_Skitty
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_CUTE, LilycoveCity_PokemonCentre_1F_EventScript_Poochyena
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_SMART, LilycoveCity_PokemonCentre_1F_EventScript_Kecleon
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_TOUGH, LilycoveCity_PokemonCentre_1F_EventScript_Pikachu
	end

LilycoveCity_PokemonCentre_1F_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCentre_1F_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCentre_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCentre_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCentre_1F_EventScript_Poochyena::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCentre_1F_Text_Poochyena, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCentre_1F_EventScript_Kecleon::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCentre_1F_Text_Kecleon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCentre_1F_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCentre_1F_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCentre_1F_Text_ImTheFavourLady:
	.string "I'm the FAVOUR LADY…$"

LilycoveCity_PokemonCentre_1F_Text_ObsessedWithThing:
	.string "I've recently developed an obsession\n"
	.string "for {STR_VAR_1} things…$"

LilycoveCity_PokemonCentre_1F_Text_ThankYouForLastTime:
	.string "Oh…\n"
	.string "Thank you for last time…$"

LilycoveCity_PokemonCentre_1F_Text_PlayerGaveMeBadThing:
	.string "Before, I think it was {STR_VAR_3}…\p"
	.string "{STR_VAR_3} gave me one {STR_VAR_2},\n"
	.string "saying it was {STR_VAR_1}.\p"
	.string "But it wasn't {STR_VAR_1}.\n"
	.string "Not in the least bit.$"

LilycoveCity_PokemonCentre_1F_Text_PlayerGaveMeGreatThing:
	.string "Before, {STR_VAR_3} gave me a very\n"
	.string "{STR_VAR_1} {STR_VAR_2}.\p"
	.string "I cherish it now.$"

LilycoveCity_PokemonCentre_1F_Text_WillYouShareThing:
	.string "Listen, if you have anything that\n"
	.string "is {STR_VAR_1}, will you share it\l"
	.string "with me?$"

LilycoveCity_PokemonCentre_1F_Text_WhatWillYouGiveMe:
	.string "…Really?\n"
	.string "What will you give me?$"

LilycoveCity_PokemonCentre_1F_Text_IsThatSoGoodbye:
	.string "Is that so?\n"
	.string "Then, it's good-bye…$"

LilycoveCity_PokemonCentre_1F_Text_NotWillingToShare:
	.string "Oh…\n"
	.string "You're not willing to share?$"

LilycoveCity_PokemonCentre_1F_Text_IllTryToCherishIt:
	.string "Oh?\n"
	.string "That {STR_VAR_2} is {STR_VAR_1}?\p"
	.string "…Oh, is that right?\p"
	.string "Well, I owe you a thanks anyway.\n"
	.string "I'll try to cherish it…$"

LilycoveCity_PokemonCentre_1F_Text_IWillCherishThis:
	.string "Oh…\p"
	.string "That's a quite {STR_VAR_1}\n"
	.string "{STR_VAR_2}…\p"
	.string "Isn't it nice?\n"
	.string "It's so dreamy…\p"
	.string "Thank you…\n"
	.string "I will cherish this…$"

LilycoveCity_PokemonCentre_1F_Text_IWillTreasureThis:
	.string "…Oh, oh, oh…\p"
	.string "This is amazing!\n"
	.string "This really is {STR_VAR_1}!\p"
	.string "I never knew that one {STR_VAR_2}\n"
	.string "could be this {STR_VAR_1}!\p"
	.string "Thank you!\p"
	.string "I will treasure this for the rest\n"
	.string "of my life!$"

LilycoveCity_PokemonCentre_1F_Text_IllGiveYouThisInReturn:
	.string "I'll give you this wonderful item in\n"
	.string "return for your fabulous gift.\p"
	.string "I hope you will cherish it…$"

LilycoveCity_PokemonCentre_1F_Text_YouDontHaveSpaceForIt:
	.string "Oh, you can't have it if you don't have\n"
	.string "the space for it.\p"
	.string "Please come see me when you get\n"
	.string "your BAG organized…$"

LilycoveCity_PokemonCentre_1F_Text_ImTheQuizLady:
	.string "I'm the QUIZ LADY!\n"
	.string "I love quizzes!$"

LilycoveCity_PokemonCentre_1F_Text_WaitingToTakeYourQuiz:
	.string "Oh?\p"
	.string "I'm waiting for a challenger to answer\n"
	.string "the quiz you made.\p"
	.string "We can chat another time, okay?$"

LilycoveCity_PokemonCentre_1F_Text_WaitingForChallenger:
	.string "I'm waiting for someone to challenge\n"
	.string "a quiz this {STR_VAR_1} thought up!$"

LilycoveCity_PokemonCentre_1F_Text_TakeQuizChallenge:
	.string "If you answer correctly, you can win\n"
	.string "fabulous prizes!\p"
	.string "Would you like to take the quiz\n"
	.string "challenge?$"

LilycoveCity_PokemonCentre_1F_Text_WaitForAnswer:
	.string "… … … … … …\n"
	.string "… … … … … …$"

LilycoveCity_PokemonCentre_1F_Text_HowBoringBye:
	.string "Oh, how boring!\n"
	.string "Bye-bye!$"

LilycoveCity_PokemonCentre_1F_Text_YoureGoingToQuit:
	.string "Awww!\n"
	.string "You're going to quit?$"

LilycoveCity_PokemonCentre_1F_Text_TakeTheQuizAnotherTime:
	.string "Please take the quiz challenge\n"
	.string "another time!$"

LilycoveCity_PokemonCentre_1F_Text_YouGotItRight:
	.string "You're amazing! You've got it right!\n"
	.string "You're one sharp customer!$"

LilycoveCity_PokemonCentre_1F_Text_YouGotItRightYouveWonPersonsPrize:
	.string "Congratulations!\n"
	.string "You've got the quiz right!\p"
	.string "You've won a prize provided by\n"
	.string "{STR_VAR_1}!$"

@ Unused
LilycoveCity_PokemonCentre_1F_Text_XReceivedOneY:
	.string "{STR_VAR_1} received\n"
	.string "one {STR_VAR_2}!$"

LilycoveCity_PokemonCentre_1F_Text_YourBagIsFilledUp:
	.string "Oh? Your BAG is filled up!\n"
	.string "Come see me when you have room.$"

LilycoveCity_PokemonCentre_1F_Text_WrongTheCorrectAnswerIs:
	.string "Hmm… Wrong!\n"
	.string "The correct answer is “{STR_VAR_3}”!$"

LilycoveCity_PokemonCentre_1F_Text_IGetToKeepPrize:
	.string "Too bad!\p"
	.string "I get to keep the quiz prize\n"
	.string "{STR_VAR_1} now!$"

LilycoveCity_PokemonCentre_1F_Text_MakeYourOwnQuiz:
	.string "Listen, listen!\n"
	.string "Would you like to make your own quiz?$"

LilycoveCity_PokemonCentre_1F_Text_MaybeNextTime:
	.string "Oh, I see…\n"
	.string "Well, maybe next time!$"

LilycoveCity_PokemonCentre_1F_Text_PickYourPrize:
	.string "Okay, the first thing you have to do\n"
	.string "is pick the prize for the person that\l"
	.string "answers your quiz correctly.\p"
	.string "But beware, if the person taking\n"
	.string "the quiz can't get it right, I get to\l"
	.string "keep the prize!$"

LilycoveCity_PokemonCentre_1F_Text_QuitChoosingPrize:
	.string "If you don't choose a prize,\n"
	.string "your quiz can't be made.\p"
	.string "Are you going to quit making\n"
	.string "your quiz?$"

LilycoveCity_PokemonCentre_1F_Text_WriteYourQuiz:
	.string "Oh, how nice!\n"
	.string "That's a wonderful prize!\p"
	.string "Next, you need to write your quiz\n"
	.string "question and its answer.$"

LilycoveCity_PokemonCentre_1F_Text_QuitWritingQuizQuestion:
	.string "Are you going to quit writing\n"
	.string "your quiz question?$"

@ Unused
LilycoveCity_PokemonCentre_1F_Text_QuitWritingQuizAnswer:
	.string "Are you going to quit choosing\n"
	.string "your quiz answer?$"

LilycoveCity_PokemonCentre_1F_Text_IllLookForAChallenger:
	.string "Thank you!\n"
	.string "You've put together a nice quiz.\p"
	.string "I'll go look for someone who'll take\n"
	.string "your quiz challenge right away.$"

LilycoveCity_PokemonCentre_1F_Text_ImTheContestLady:
	.string "I'm the CONTEST LADY!\n"
	.string "I sure do love CONTESTS!$"

LilycoveCity_PokemonCentre_1F_Text_ThankForPokeblock:
	.string "Thanks for your {POKEBLOCK} before!$"

LilycoveCity_PokemonCentre_1F_Text_MyFriendDisplaysQuality:
	.string "This is my friend {STR_VAR_1}!\n"
	.string "It's the epitome of {STR_VAR_2}!\p"
	.string "But I think that it will display\n"
	.string "even more {STR_VAR_2}!$"

LilycoveCity_PokemonCentre_1F_Text_DontHaveAPokeblockCase:
	.string "So, I need your help!\p"
	.string "Please, may I have one {POKEBLOCK}?\n"
	.string "All I'm asking for is one!\p"
	.string "…Oh, but…\n"
	.string "Don't you have a {POKEBLOCK} CASE?\l"
	.string "That's no good. Next time, then!$"

LilycoveCity_PokemonCentre_1F_Text_AskingForOnePokeblock:
	.string "So, I need your help!\p"
	.string "Please, may I have one {POKEBLOCK}?\n"
	.string "All I'm asking for is one!$"

LilycoveCity_PokemonCentre_1F_Text_ICantHaveOnePokeblock:
	.string "Awww!\n"
	.string "I can't have one {POKEBLOCK}?!$"

LilycoveCity_PokemonCentre_1F_Text_WhatACheapskate:
	.string "Sheesh!\n"
	.string "What a cheapskate!$"

LilycoveCity_PokemonCentre_1F_Text_IllUseYourPokeblock:
	.string "Yay!\n"
	.string "Thank you!\p"
	.string "I'll feed my POKéMON your {POKEBLOCK}\n"
	.string "right away.$"

LilycoveCity_PokemonCentre_1F_Text_NoChangeThanks:
	.string "…It doesn't seem to have changed\n"
	.string "in any way at all…\p"
	.string "Hmm…\p"
	.string "Oh, well!\n"
	.string "Thank you very much!$"

LilycoveCity_PokemonCentre_1F_Text_ReallyImprovedThanks:
	.string "Oh, yay!\n"
	.string "It's really delighted!\p"
	.string "I think it really improved {STR_VAR_1}'s\n"
	.string "{STR_VAR_2} quality, too.\p"
	.string "Thank you so much!$"

LilycoveCity_PokemonCentre_1F_Text_ReadyToEnterContests:
	.string "Hmm…\p"
	.string "I think we may be ready to enter\n"
	.string "some CONTESTS.\p"
	.string "If you see us in one somewhere,\n"
	.string "I hope you'll cheer for us.$"

LilycoveCity_PokemonCentre_1F_Text_Zigzagoon:
	.string "{STR_VAR_1}: Guguuh!$"

LilycoveCity_PokemonCentre_1F_Text_Kecleon:
	.string "{STR_VAR_1}: Igigigiiih!$"

LilycoveCity_PokemonCentre_1F_Text_Poochyena:
	.string "{STR_VAR_1}: Baaarun…$"

LilycoveCity_PokemonCentre_1F_Text_Pikachu:
	.string "{STR_VAR_1}: Pikka!$"

LilycoveCity_PokemonCentre_1F_Text_Skitty:
	.string "{STR_VAR_1}: Umyaaaan!$"
