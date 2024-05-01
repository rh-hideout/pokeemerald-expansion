ApricornTreeScript::
	special ObjectEventInteractionGetApricornTreeData
	goto_if_gt VAR_0x8005, 0, ApricornTree_EventScript_WantToPick
	end

ApricornTree_EventScript_WantToPick::
	buffernumberstring STR_VAR_2, VAR_0x8005
	lock
	faceplayer
	msgbox ApricornTree_Text_WantToPick, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ApricornTree_EventScript_PickApricorn
	goto_if_eq VAR_RESULT, NO, ApricornTree_EventScript_CancelPickingApricorn

.set APRICORN_NORMAL_BAG_FULL, 0
.set APRICORN_NORMAL_SPACE_IN_BAG, 1

ApricornTree_EventScript_PickApricorn::
	special ObjectEventInteractionPickApricornTree
	goto_if_eq VAR_0x8006, APRICORN_NORMAL_BAG_FULL, ApricornTree_EventScript_PocketFull
	message ApricornTree_Text_PickedTheApricorn
	@ uncomment the lines below if you're using ghoulslash's item description branch
	@ copyvar VAR_0x8006 VAR_0x8004
	delay 10
	@ showberrydesc
	playfanfare MUS_OBTAIN_BERRY
	waitmessage
	waitfanfare
	waitbuttonpress
	message ApricornTree_Text_PutAwayApricorn
	waitmessage
	waitbuttonpress
	@ hideitemdesc
	release
	end

ApricornTree_EventScript_PocketFull::
	message ApricornTree_Text_PocketFull
	waitmessage
	waitbuttonpress
	release
	end

ApricornTree_EventScript_CancelPickingApricorn::
	message ApricornTree_Text_ApricornLeftUnpicked
	waitmessage
	waitbuttonpress
	release
	end

ApricornTree_Text_WantToPick:
	.string "You found {STR_VAR_2} {STR_VAR_1}!\p"
	.string "Do you want to pick the\n"
	.string "{STR_VAR_1}?$"

ApricornTree_Text_PickedTheApricorn:
	.string "{PLAYER} picked the\n"
	.string "{STR_VAR_2} {STR_VAR_1}.$"

ApricornTree_Text_PutAwayApricorn:
	.string "{PLAYER} put away the\n"
	.string "{STR_VAR_1} in\l"
	.string "the BAG's ITEMS POCKET.$"

ApricornTree_Text_PocketFull:
	.string "The BAG's ITEMS POCKET is full.\p"
	.string "The {STR_VAR_1} couldn't be taken.$"

ApricornTree_Text_ApricornLeftUnpicked:
	.string "{PLAYER} left the {STR_VAR_1}\n"
	.string "unpicked.$"
