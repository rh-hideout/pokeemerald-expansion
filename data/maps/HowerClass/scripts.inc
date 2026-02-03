HowerClass_MapScripts::
	.byte 0

HowerClass_EventScript_Student1::
	lock
	faceplayer
	msgbox HowerClass_Text_StudentIntro, MSGBOX_DEFAULT
	msgbox HowerClass_Text_StudentPunchline, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HowerClass_EventScript_CyberStudent::
	lock
	faceplayer
	msgbox HowerClass_Text_CyberStudentIntro, MSGBOX_DEFAULT
	msgbox HowerClass_Text_CyberStudentPunchline, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HowerClass_EventScript_CryptoStudent::
	lock
	faceplayer
	msgbox HowerClass_Text_CryptoStudentIntro, MSGBOX_DEFAULT
	msgbox HowerClass_Text_CryptoStudentPunchline, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HowerClass_EventScript_SecondSemesterStudent::
	lock
	faceplayer
	msgbox HowerClass_Text_SecondSemesterIntro, MSGBOX_DEFAULT
	msgbox HowerClass_Text_SecondSemesterPunchline, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HowerClass_EventScript_DualSystemStudent::
	lock
	faceplayer
	msgbox HowerClass_Text_DualSystemIntro, MSGBOX_DEFAULT
	msgbox HowerClass_Text_DualSystemPunchline, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HowerClass_EventScript_ExamStudent::
	lock
	faceplayer
	msgbox HowerClass_Text_ExamStudentIntro, MSGBOX_DEFAULT
	msgbox HowerClass_Text_ExamStudentPunchline, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HowerClass_EventScript_BackRowStudent::
	lock
	faceplayer
	msgbox HowerClass_Text_BackRowIntro, MSGBOX_DEFAULT
	msgbox HowerClass_Text_BackRowPunchline, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HowerClass_EventScript_RowStudent::
	lock
	faceplayer
	msgbox HowerClass_Text_RowIntro, MSGBOX_DEFAULT
	msgbox HowerClass_Text_RowPunchline, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HowerClass_EventScript_BackObserverStudent::
	lock
	faceplayer
	msgbox HowerClass_Text_BackObserverIntro, MSGBOX_DEFAULT
	msgbox HowerClass_Text_BackObserverPunchline, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HowerClass_EventScript_SecurityTipStudent::
	lock
	faceplayer
	msgbox HowerClass_Text_SecurityTipIntro, MSGBOX_DEFAULT
	msgbox HowerClass_Text_SecurityTipPunchline, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HowerClass_EventScript_BackImportanceStudent::
	lock
	faceplayer
	msgbox HowerClass_Text_BackImportanceIntro, MSGBOX_DEFAULT
	msgbox HowerClass_Text_BackImportancePunchline, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HowerClass_EventScript_SystemReflectionStudent::
	lock
	faceplayer
	msgbox HowerClass_Text_SystemReflectionIntro, MSGBOX_DEFAULT
	msgbox HowerClass_Text_SystemReflectionPunchline, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HowerClass_EventScript_LookStudent::
	lock
	faceplayer
	msgbox HowerClass_Text_LookIntro, MSGBOX_DEFAULT
	msgbox HowerClass_Text_LookPunchline, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HowerClass_Text_StudentIntro:
	.string "DHBW sounded great on paper.\p"
	.string "Theory at university, practice at\n"
	.string "the company...$"

HowerClass_Text_StudentPunchline:
	.string "No one told me I'd have both\n"
	.string "at the same time.$"

HowerClass_Text_CyberStudentIntro:
	.string "Cyber security isn't about hacking\n"
	.string "all day. It's about understanding\p"
	.string "systems better than attackers do.$"

HowerClass_Text_CyberStudentPunchline:
	.string "Most breaches start with\n"
	.string "something... simple.$"

HowerClass_Text_CryptoStudentIntro:
	.string "We just covered basic\n"
	.string "cryptography. XOR looks simple,\p"
	.string "but it shows up everywhere.$"

HowerClass_Text_CryptoStudentPunchline:
	.string "Authentication, obfuscation...\n"
	.string "even student systems.$"

HowerClass_Text_SecondSemesterIntro:
	.string "Second semester already feels\n"
	.string "different. Less introductions,\p"
	.string "more expectations.$"

HowerClass_Text_SecondSemesterPunchline:
	.string "They assume you know who you\n"
	.string "are in the system.$"

HowerClass_Text_DualSystemIntro:
	.string "I like the dual system. What we\n"
	.string "learn here actually matters at work.$"

HowerClass_Text_DualSystemPunchline:
	.string "IDs, logs, names... everything has\n"
	.string "to match.$"

HowerClass_Text_ExamStudentIntro:
	.string "Exams at DHBW are strict.\n"
	.string "No ID, no number, no access.$"

HowerClass_Text_ExamStudentPunchline:
	.string "They don't care if you forgot.$"

HowerClass_Text_BackRowIntro:
	.string "You know the rule.$"

HowerClass_Text_BackRowPunchline:
	.string "The cool kids always sit in\n"
	.string "the back row.$"

HowerClass_Text_RowIntro:
	.string "Front row is for questions.$"

HowerClass_Text_RowPunchline:
	.string "Back row is for answers.$"

HowerClass_Text_BackObserverIntro:
	.string "We see everything from back here.$"

HowerClass_Text_BackObserverPunchline:
	.string "Including who's stressed... and who's\n"
	.string "pretending not to be.$"

HowerClass_Text_SecurityTipIntro:
	.string "Security tip? Never sit where\n"
	.string "everyone's watching.$"

HowerClass_Text_SecurityTipPunchline:
	.string "Back row gives you... options.$"

HowerClass_Text_BackImportanceIntro:
	.string "Everyone thinks nothing important\n"
	.string "happens back here.$"

HowerClass_Text_BackImportancePunchline:
	.string "That's why important things happen\n"
	.string "back here.$"

HowerClass_Text_SystemReflectionIntro:
	.string "I thought I understood the\n"
	.string "system.$"

HowerClass_Text_SystemReflectionPunchline:
	.string "Turns out, the system understands\n"
	.string "me better.$"

HowerClass_Text_LookIntro:
	.string "It's not hard.$"

HowerClass_Text_LookPunchline:
	.string "You just have to know where to\n"
	.string "look.$"
