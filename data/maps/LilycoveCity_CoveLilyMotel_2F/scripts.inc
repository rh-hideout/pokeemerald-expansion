# 1 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 2 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_MapScripts::
# 3 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.byte 0
# 4 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 5 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
# 6 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	lock
# 7 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	faceplayer
# 8 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
# 9 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
# 10 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	specialvar VAR_RESULT, HasAllHoennMons
# 11 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
# 12 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
# 13 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 14 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 15 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
# 16 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
# 17 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	return
# 18 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 19 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
# 20 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_TEMP_2
# 21 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 22 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitfanfare
# 23 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
# 24 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 25 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 26 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
# 27 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
# 28 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitmessage
# 29 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 30 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	special Special_ShowDiploma
# 31 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	waitstate
# 32 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
# 33 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 34 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 35 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
# 36 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
# 37 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 38 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 39 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
# 40 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
# 41 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 42 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 43 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
# 44 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
# 45 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 46 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 47 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
# 48 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
# 49 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 50 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 51 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
# 52 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
# 53 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 54 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 55 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
# 56 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	lock
# 57 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	faceplayer
# 58 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
# 59 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
# 60 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 61 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
# 62 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
# 63 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 64 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 65 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
# 66 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
# 67 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	release
# 68 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	end
# 69 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 70 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
# 71 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm the GAME DESIGNER.\p"
# 72 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Oh, is that right?\n"
# 73 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You're working on a POKéDEX?\p"
# 74 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "It's tough trying to complete it,\n"
# 75 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "but don't give up.\p"
# 76 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "If you do complete it, please come\n"
# 77 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "show me.$"
# 78 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 79 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
# 80 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Wow! That's awesome!\n"
# 81 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Yep, it's totally awesome!\p"
# 82 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "This POKéDEX is completely filled!\n"
# 83 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You really must love POKéMON!\p"
# 84 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm so impressed!\p"
# 85 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Let me give you something in\n"
# 86 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "recognition of your feat!$"
# 87 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 88 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
# 89 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Me? You're talking to me?\n"
# 90 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm the PROGRAMMER.\p"
# 91 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I wonder what the SLOTS are\n"
# 92 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "like here.$"
# 93 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 94 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
# 95 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I'm the GRAPHIC ARTIST! Aren't the\n"
# 96 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "POKéMON of HOENN interesting?$"
# 97 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 98 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
# 99 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "The girl TUBERS, they're cute, hey?\n"
# 100 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "To battle against a cute TUBER…\p"
# 101 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Whoop, it's so awesome!\p"
# 102 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "And the TWINS! Aren't they cute?\n"
# 103 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "A 2-on-2 battle with TWINS…\p"
# 104 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Whoop, it's unbearably fun!$"
# 105 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 106 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
# 107 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "The sea breeze tickles my heart.\n"
# 108 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "It feels wonderful here!$"
# 109 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 110 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
# 111 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "You never know when and where\n"
# 112 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "people will challenge you.\p"
# 113 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "That's why I never leave home without\n"
# 114 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "my GAME BOY ADVANCE.$"
# 115 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 116 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
# 117 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "SCOTT: … … … … …\n"
# 118 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … … Zzz…\p"
# 119 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "… … … … … Huh?!\n"
# 120 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Oh, sorry, sorry! I was snoozing!\p"
# 121 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I came to check out this POKéMON\n"
# 122 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "CONTEST thing.\p"
# 123 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "I have to admit, it does look quite\n"
# 124 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "entertaining, but…\p"
# 125 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Consider me a purist--I prefer\n"
# 126 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "battles and tough TRAINERS.\p"
# 127 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "But that's just me.\p"
# 128 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "{PLAYER}{KUN}, I hope you'll enjoy everything\n"
# 129 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "like the GYMS, CONTESTS, BATTLE TENT,\l"
# 130 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "the whole works!$"
# 131 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"

# 132 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
# 133 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "SCOTT: I think it does take strategy\n"
# 134 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "to win a CONTEST.\p"
# 135 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "Devising CONTEST strategies is one way\n"
# 136 "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.pory"
	.string "of becoming a better TRAINER, I'd say.$"
