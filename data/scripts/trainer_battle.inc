Movement_RevealTrainer:
	reveal_trainer
	step_end

Std_MsgboxAutoclose::
	message NULL
	waitmessage
	waitbuttonpress
	release
	return

@ Event Snippets for dynamic trainer battle scripting
EventSnippet_Lock::
	lock
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	return

EventSnippet_FacePlayer::
	faceplayer
	return

EventSnippet_StartTrainerApproach::
	selectapproachingtrainer
	lockfortrainer
	return

EventSnippet_TrainerApproach::
	special DoTrainerApproach
	waitstate
	return

EventSnippet_RevealTrainer::
	applymovement VAR_LAST_TALKED, Movement_RevealTrainer
	waitmovement 0
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	return

EventSnippet_PlayTrainerEncounterMusic::
	special PlayTrainerEncounterMusic
	return

EventSnippet_SetTrainerFacingDirection::
	special SetTrainerFacingDirection
	return

EventSnippet_ShowTrainerIntroMsg::
	special ShowTrainerIntroSpeech
	waitmessage
	waitbuttonpress
	return 

EventSnippet_PrepareSecondTrainerApproach::
	special PrepareSecondApproachingTrainer
	return

EventSnippet_GotoPostBattleScript::
	gotopostbattlescript
	return

EventSnippet_DoTrainerBattle::
	dotrainerbattle
	return

EventSnippet_DoRematchTrainerBattle::
	special BattleSetup_StartRematchBattle
	waitstate
	return

EventSnippet_EndTrainerBattle::
	gotobeatenscript
	releaseall
	end

EventSnippet_NotEnoughMonsForDoubleBattle::
	special ShowTrainerCantBattleSpeech
	waitmessage
	waitbuttonpress
	release
	end
