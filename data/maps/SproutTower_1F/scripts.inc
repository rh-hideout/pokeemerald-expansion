SproutTower_1F_MapScripts::
	.byte 0

SproutTower_1F_EventScript_SageChow::
	trainerbattle_single TRAINER_CHOW, SproutTower_Text_SageChow_Seen, SproutTower_Text_SageChow_Beaten
	msgbox SproutTower_Text_SageChow_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_1F_EventScript_Sage1::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Sage1, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Sage2::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Sage2, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Granny::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Teacher::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_ItemParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

SproutTower_Text_SageChow_Seen:
	.string "We stand guard in this tower.\p"
	.string "Here, we express our gratitude\n"
	.string "to honor all POKéMON.$"

SproutTower_Text_SageChow_Beaten:
	.string "Th-Thank you!$"

SproutTower_Text_SageChow_AfterBattle:
	.string "All living beings coexist\n"
	.string "through cooperation.\p"
	.string "We must always be thankful\n"
	.string "for this.$"

SproutTower_Text_1F_Sage1:
	.string "Only if you reach the top will\n"
	.string "you obtain an HM.$"

SproutTower_Text_1F_Sage2:
	.string "SPROUT TOWER was built long ago\n"
	.string "as a place for POKéMON training.$"

SproutTower_Text_1F_Granny:
	.string "A BELLSPROUT over 100 feet\n"
	.string "tall…\p"
	.string "People say that it became the\n"
	.string "center pillar here.$"

SproutTower_Text_1F_Teacher:
	.string "See the pillar shaking?\p"
	.string "People are training upstairs.$"

SproutTower_Text_1F_Statue:
	.string "A POKéMON statue…\p"
	.string "It looks very distinguished.$"
