HouvertClass_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, HouvertClass_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, HouvertClass_OnFrame
	.byte 0

HouvertClass_OnFrame:
	map_script_2 VAR_TEMP_B, 0, HouvertClass_EventScript_ReturnFromFlashback
	.2byte 0

HouvertClass_OnLoad:
	setvar VAR_TEMP_B, 1
	call_if_set FLAG_CTF_HOUVERT_EXAM_RESUME, HouvertClass_EventScript_EnableReturnFromFlashback
	end

HouvertClass_EventScript_ProfHouvertExam::
	goto_if_set FLAG_CTF_HOUVERT_EXAM_COMPLETED, HouvertClass_EventScript_ProfHouvertExam_PostBattle
	lockall
	faceplayer
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_ne VAR_TEMP_1, 4, HouvertClass_EventScript_ProfHouvertExam_NotInFront
	goto_if_eq VAR_TEMP_0, 6, HouvertClass_EventScript_ProfHouvertExam_Start
	goto_if_eq VAR_TEMP_0, 5, HouvertClass_EventScript_ProfHouvertExam_FromLeft
	goto_if_eq VAR_TEMP_0, 7, HouvertClass_EventScript_ProfHouvertExam_FromRight
	goto HouvertClass_EventScript_ProfHouvertExam_NotInFront

HouvertClass_EventScript_ProfHouvertExam_FromLeft:
	applymovement LOCALID_PLAYER, HouvertClass_Movement_PlayerApproachFromLeft
	waitmovement 0
	goto HouvertClass_EventScript_ProfHouvertExam_Start

HouvertClass_EventScript_ProfHouvertExam_FromRight:
	applymovement LOCALID_PLAYER, HouvertClass_Movement_PlayerApproachFromRight
	waitmovement 0
	goto HouvertClass_EventScript_ProfHouvertExam_Start

HouvertClass_EventScript_ProfHouvertExam_Start:
	msgbox HouvertClass_Text_ProfHouvertArrival, MSGBOX_DEFAULT
	msgbox HouvertClass_Text_ProfHouvertSitDown, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, HouvertClass_Movement_PlayerWalkToSeat
	waitmovement 0
	delay 20
	msgbox HouvertClass_Text_ProfHouvertExamRules, MSGBOX_DEFAULT
	msgbox HouvertClass_Text_ProfHouvertRegistrationRequest, MSGBOX_DEFAULT
	delay 30
	msgbox HouvertClass_Text_PlayerForgotRegistration, MSGBOX_DEFAULT
	delay 20
	msgbox HouvertClass_Text_ProfHouvertWell, MSGBOX_DEFAULT
	msgbox HouvertClass_Text_ProfHouvertTrivialExam, MSGBOX_DEFAULT
	delay 10
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_CTF_HOUVERT_EXAM_FLASHBACK
	releaseall
	warpsilent MAP_HALLWAY_TO_SECRETARIAT_2, 8, 6, 1
	end

HouvertClass_EventScript_ProfHouvertExam_PostBattle:
	lock
	faceplayer
	msgbox HouvertClass_Text_HouvertAfterPass, MSGBOX_DEFAULT
	release
	end

HouvertClass_EventScript_ProfHouvertExam_NotInFront:
	msgbox HouvertClass_Text_ProfHouvertComeToFront, MSGBOX_DEFAULT
	releaseall
	end

HouvertClass_EventScript_Student1::
	lock
	faceplayer
	msgbox HouvertClass_Text_StudentIntro, MSGBOX_DEFAULT
	msgbox HouvertClass_Text_StudentPunchline, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HouvertClass_EventScript_CyberStudent::
	lock
	faceplayer
	msgbox HouvertClass_Text_CyberStudentIntro, MSGBOX_DEFAULT
	msgbox HouvertClass_Text_CyberStudentPunchline, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HouvertClass_EventScript_CryptoStudent::
	lock
	faceplayer
	msgbox HouvertClass_Text_CryptoStudentIntro, MSGBOX_DEFAULT
	msgbox HouvertClass_Text_CryptoStudentPunchline, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HouvertClass_EventScript_SecondSemesterStudent::
	lock
	faceplayer
	msgbox HouvertClass_Text_SecondSemesterIntro, MSGBOX_DEFAULT
	msgbox HouvertClass_Text_SecondSemesterPunchline, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HouvertClass_EventScript_DualSystemStudent::
	lock
	faceplayer
	msgbox HouvertClass_Text_DualSystemIntro, MSGBOX_DEFAULT
	msgbox HouvertClass_Text_DualSystemPunchline, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HouvertClass_EventScript_ExamStudent::
	lock
	faceplayer
	msgbox HouvertClass_Text_ExamStudentIntro, MSGBOX_DEFAULT
	msgbox HouvertClass_Text_ExamStudentPunchline, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HouvertClass_EventScript_BackRowStudent::
	lock
	faceplayer
	msgbox HouvertClass_Text_BackRowIntro, MSGBOX_DEFAULT
	msgbox HouvertClass_Text_BackRowPunchline, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HouvertClass_EventScript_RowStudent::
	lock
	faceplayer
	msgbox HouvertClass_Text_RowIntro, MSGBOX_DEFAULT
	msgbox HouvertClass_Text_RowPunchline, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HouvertClass_EventScript_BackObserverStudent::
	lock
	faceplayer
	msgbox HouvertClass_Text_BackObserverIntro, MSGBOX_DEFAULT
	msgbox HouvertClass_Text_BackObserverPunchline, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HouvertClass_EventScript_SecurityTipStudent::
	lock
	faceplayer
	msgbox HouvertClass_Text_SecurityTipIntro, MSGBOX_DEFAULT
	msgbox HouvertClass_Text_SecurityTipPunchline, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HouvertClass_EventScript_BackImportanceStudent::
	lock
	faceplayer
	msgbox HouvertClass_Text_BackImportanceIntro, MSGBOX_DEFAULT
	msgbox HouvertClass_Text_BackImportancePunchline, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HouvertClass_EventScript_SystemReflectionStudent::
	lock
	faceplayer
	msgbox HouvertClass_Text_SystemReflectionIntro, MSGBOX_DEFAULT
	msgbox HouvertClass_Text_SystemReflectionPunchline, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HouvertClass_EventScript_LookStudent::
	lock
	faceplayer
	msgbox HouvertClass_Text_LookIntro, MSGBOX_DEFAULT
	msgbox HouvertClass_Text_LookPunchline, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HouvertClass_EventScript_MemoryStudent::
	lock
	faceplayer
	msgbox HouvertClass_Text_Memory, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HouvertClass_EventScript_RememberStudent::
	lock
	faceplayer
	msgbox HouvertClass_Text_RememberIntro, MSGBOX_DEFAULT
	msgbox HouvertClass_Text_RememberPunchline, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HouvertClass_EventScript_EnableReturnFromFlashback:
	setvar VAR_TEMP_B, 0
	return

HouvertClass_EventScript_ReturnFromFlashback::
	setvar VAR_TEMP_B, 1
	clearflag FLAG_CTF_HOUVERT_EXAM_RESUME
	clearflag FLAG_CTF_HOUVERT_EXAM_FLASHBACK
	clearflag FLAG_CTF_HOUVERT_FLASHBACK_INTRO_SEEN
	lockall
	setobjectxy LOCALID_PLAYER, 7, 7
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	fadescreenswapbuffers FADE_FROM_BLACK
	delay 20
	msgbox HouvertClass_Text_PlayerRight, MSGBOX_DEFAULT
	msgbox HouvertClass_Text_PlayerThatsIt, MSGBOX_DEFAULT
	msgbox HouvertClass_Text_PlayerCanWrite, MSGBOX_DEFAULT
	fadescreenswapbuffers FADE_TO_BLACK
	delay 20
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox HouvertClass_Text_HouvertTimeUp, MSGBOX_DEFAULT
	msgbox HouvertClass_Text_HouvertPensDown, MSGBOX_DEFAULT
	waitmovement 0
	applymovement LOCALID_HOUVERT, HouvertClass_Movement_HouvertApproachSeat
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox HouvertClass_Text_HouvertPassPapers, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_HOUVERT, HouvertClass_Movement_walkDeskAndBack
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox HouvertClass_Text_HouvertFail, MSGBOX_DEFAULT
	msgbox HouvertClass_Text_PlayerWhat, MSGBOX_DEFAULT
	msgbox HouvertClass_Text_HouvertTrivial, MSGBOX_DEFAULT
	msgbox HouvertClass_Text_HouvertCritique, MSGBOX_DEFAULT
	msgbox HouvertClass_Text_HouvertHowever, MSGBOX_DEFAULT
	msgbox HouvertClass_Text_HouvertBattleChallenge, MSGBOX_DEFAULT
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_HOUVERT, TRAINER_HOUVERT, HouvertClass_Text_HouvertBattleIntro, HouvertClass_Text_HouvertBattleDefeat, HouvertClass_EventScript_HouvertPostBattle, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	end

HouvertClass_EventScript_HouvertPostBattle::
	special PlayerFaceTrainerAfterBattle
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_HOUVERT, Common_Movement_FaceDown
	msgbox HouvertClass_Text_HouvertPassConfirmation, MSGBOX_DEFAULT
	message HouvertClass_Text_HouvertBadgeReward
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox HouvertClass_Text_HouvertBadgeInfo, MSGBOX_DEFAULT
	setflag FLAG_BADGE02_GET
	setflag FLAG_CTF_HOUVERT_EXAM_COMPLETED
	waitmovement 0
	applymovement LOCALID_HOUVERT, HouvertClass_Movement_HouvertReturnToPodium
	waitmovement 0
	releaseall
	end

HouvertClass_Movement_PlayerApproachFromLeft:
	walk_right
	step_end

HouvertClass_Movement_PlayerApproachFromRight:
	walk_left
	step_end

HouvertClass_Movement_PlayerWalkToSeat:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	face_up
	step_end

HouvertClass_Movement_HouvertApproachSeat:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	face_left
	step_end

HouvertClass_Movement_HouvertReturnToPodium:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	face_down
	step_end

HouvertClass_Movement_walkDeskAndBack:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	face_left
	step_end

HouvertClass_Text_ProfHouvertComeToFront:
	.string "DR. PROF. HOUVERT: Approach the\n"
	.string "front like everyone else.\p"
	.string "If you need directions again,\n"
	.string "I'll draw you a map.$"

HouvertClass_Text_PlayerRight:
	.string "You: Right...$"

HouvertClass_Text_PlayerThatsIt:
	.string "You: That's it.$"

HouvertClass_Text_PlayerCanWrite:
	.string "You: Now I can actually write the\n"
	.string "exam.$"

HouvertClass_Text_HouvertTimeUp:
	.string "DR. PROF. HOUVERT: Time is up.$"

HouvertClass_Text_HouvertPensDown:
	.string "DR. PROF. HOUVERT: Pens down.$"

HouvertClass_Text_HouvertPassPapers:
	.string "DR. PROF. HOUVERT: Pass your papers\n"
	.string "forward.$"

HouvertClass_Text_HouvertBadgeReward:
	.string "DR. PROF. HOUVERT: You may claim the\n"
	.string "second badge.$"

HouvertClass_Text_HouvertBadgeInfo:
	.string "It proves you survived this exam.\p"
	.string "Keep it safe.$"

HouvertClass_Text_HouvertFail:
	.string "DR. PROF. HOUVERT: Hmm...\p"
	.string "You have failed.$"

HouvertClass_Text_PlayerWhat:
	.string "You: What? How can you tell already?$"

HouvertClass_Text_HouvertTrivial:
	.string "DR. PROF. HOUVERT: It is trivial.$"

HouvertClass_Text_HouvertCritique:
	.string "DR. PROF. HOUVERT: Your reasoning lacks\n"
	.string "structure.\p"
	.string "Your execution lacks precision.\p"
	.string "Your result lacks merit.$"

HouvertClass_Text_HouvertHowever:
	.string "DR. PROF. HOUVERT: However.\p"
	.string "This is the DHBW.\p"
	.string "To pass this semester...\n"
	.string "You will defeat me in battle.$"

HouvertClass_Text_HouvertBattleChallenge:
	.string "DR. PROF. HOUVERT: Let us proceed.$"

HouvertClass_Text_HouvertBattleIntro:
	.string "DR. PROF. HOUVERT: Let us see if you\n"
	.string "perform better under pressure.$"

HouvertClass_Text_HouvertBattleDefeat:
	.string "DR. PROF. HOUVERT: Hm.\p"
	.string "Acceptable.\p"
	.string "Very well.\p"
	.string "You pass.$"

HouvertClass_Text_HouvertPassConfirmation:
	.string "DR. PROF. HOUVERT: Very well. You\n"
	.string "have passed this examination.$"

HouvertClass_Text_HouvertAfterPass:
	.string "DR. PROF. HOUVERT: Tomorrow I captain\n"
	.string "Germany's national squad.\p"
	.string "We'll defend the table football title\n"
	.string "with the same edge you showed today.$"

HouvertClass_Text_ProfHouvertArrival:
	.string "DR. PROF. HOUVERT: Good. You're\n"
	.string "the last one.\p"
	.string "If I were that late, I'd never reach\n"
	.string "AlpCity in winter.$"

HouvertClass_Text_ProfHouvertSitDown:
	.string "DR. PROF. HOUVERT: Sit down.\p"
	.string "We are about to begin.$"

HouvertClass_Text_ProfHouvertExamRules:
	.string "DR. PROF. HOUVERT: This is a\n"
	.string "written examination.\p"
	.string "No talking. No devices. No\n"
	.string "excuses.$"

HouvertClass_Text_ProfHouvertRegistrationRequest:
	.string "DR. PROF. HOUVERT: Before we\n"
	.string "start...\p"
	.string "Write your Registration Number at\n"
	.string "the top of the page.$"

HouvertClass_Text_PlayerForgotRegistration:
	.string "You: ...My Registration Number.\p"
	.string "Wait.\p"
	.string "I don't remember it.$"

HouvertClass_Text_ProfHouvertWell:
	.string "DR. PROF. HOUVERT: Well?$"

HouvertClass_Text_ProfHouvertTrivialExam:
	.string "DR. PROF. HOUVERT: You do not have\n"
	.string "all day.\p"
	.string "Even though the exam is quite\n"
	.string "trivial.$"

HouvertClass_Text_StudentIntro:
	.string "DHBW sounded great on paper.\p"
	.string "Theory at university, practice at\n"
	.string "the company...$"

HouvertClass_Text_StudentPunchline:
	.string "No one told me I'd have both\n"
	.string "at the same time.$"

HouvertClass_Text_CyberStudentIntro:
	.string "Cyber security isn't about hacking\n"
	.string "all day. It's about understanding\p"
	.string "systems better than attackers do.$"

HouvertClass_Text_CyberStudentPunchline:
	.string "Most breaches start with\n"
	.string "something... simple.$"

HouvertClass_Text_CryptoStudentIntro:
	.string "We just covered basic\n"
	.string "cryptography. XOR looks simple,\p"
	.string "but it shows up everywhere.$"

HouvertClass_Text_CryptoStudentPunchline:
	.string "Authentication, obfuscation...\n"
	.string "even student systems.$"

HouvertClass_Text_SecondSemesterIntro:
	.string "Second semester already feels\n"
	.string "different. Less introductions,\p"
	.string "more expectations.$"

HouvertClass_Text_SecondSemesterPunchline:
	.string "They assume you know who you\n"
	.string "are in the system.$"

HouvertClass_Text_DualSystemIntro:
	.string "I like the dual system. What we\n"
	.string "learn here actually matters at work.$"

HouvertClass_Text_DualSystemPunchline:
	.string "IDs, logs, names... everything has\n"
	.string "to match.$"

HouvertClass_Text_ExamStudentIntro:
	.string "Exams at DHBW are strict.\n"
	.string "No ID, no number, no access.$"

HouvertClass_Text_ExamStudentPunchline:
	.string "They don't care if you forgot.$"

HouvertClass_Text_BackRowIntro:
	.string "You know the rule.$"

HouvertClass_Text_BackRowPunchline:
	.string "The cool kids always sit in\n"
	.string "the back row.$"

HouvertClass_Text_RowIntro:
	.string "Front row is for questions.$"

HouvertClass_Text_RowPunchline:
	.string "Back row is for answers.$"

HouvertClass_Text_BackObserverIntro:
	.string "We see everything from back here.$"

HouvertClass_Text_BackObserverPunchline:
	.string "Including who's stressed... and who's\n"
	.string "pretending not to be.$"

HouvertClass_Text_SecurityTipIntro:
	.string "Security tip? Never sit where\n"
	.string "everyone's watching.$"

HouvertClass_Text_SecurityTipPunchline:
	.string "Back row gives you... options.$"

HouvertClass_Text_BackImportanceIntro:
	.string "Everyone thinks nothing important\n"
	.string "happens back here.$"

HouvertClass_Text_BackImportancePunchline:
	.string "That's why important things happen\n"
	.string "back here.$"

HouvertClass_Text_SystemReflectionIntro:
	.string "I thought I understood the\n"
	.string "system.$"

HouvertClass_Text_SystemReflectionPunchline:
	.string "Turns out, the system understands\n"
	.string "me better.$"

HouvertClass_Text_LookIntro:
	.string "It's not hard.$"

HouvertClass_Text_LookPunchline:
	.string "You just have to know where to\n"
	.string "look.$"

HouvertClass_Text_Memory:
	.string "It's funny...\p"
	.string "Some faces stick with you long\n"
	.string "before you know their names.$"

HouvertClass_Text_RememberIntro:
	.string "I don't think we've met.$"

HouvertClass_Text_RememberPunchline:
	.string "And yet... I remember you.$"
