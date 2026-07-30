Text_RoamerNearby::
	.string "A powerful entity is nearby!$"

EventScript_RoamerNearby::
	lock
	delay 40
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	delay 40
	message Text_RoamerNearby
	delay 150
	waitmessage
	waitbuttonpress
	releaseall
	end