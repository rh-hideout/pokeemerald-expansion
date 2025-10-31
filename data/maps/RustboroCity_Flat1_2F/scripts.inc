# 1 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 2 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_MapScripts::
# 3 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.byte 0
# 4 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 5 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_WaldasDad::
# 6 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	lock
# 7 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	faceplayer
# 8 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	specialvar VAR_RESULT, TryBufferWaldaPhrase
# 9 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
# 10 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase
# 11 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 12 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_GivePhrase::
# 13 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	special DoWaldaNamingScreen
# 14 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	waitstate
# 15 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
# 16 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
# 17 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
# 18 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
# 19 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
# 20 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	end
# 21 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 22 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
# 23 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
# 24 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
# 25 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
# 26 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase
# 27 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 28 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
# 29 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
# 30 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
# 31 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
# 32 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase
# 33 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 34 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
# 35 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
# 36 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	release
# 37 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	end
# 38 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 39 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
# 40 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
# 41 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	release
# 42 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	end
# 43 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 44 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
# 45 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
# 46 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
# 47 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
# 48 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	release
# 49 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	end
# 50 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 51 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
# 52 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
# 53 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
# 54 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
# 55 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	applymovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
# 56 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	waitmovement 0
# 57 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
# 58 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	release
# 59 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	end
# 60 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 61 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
# 62 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
# 63 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
# 64 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
# 65 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	release
# 66 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	end
# 67 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 68 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
# 69 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
# 70 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	return
# 71 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 72 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_WaldasMom::
# 73 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
# 74 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	end
# 75 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 76 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_PokeDoll::
# 77 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
# 78 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	end
# 79 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 80 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
# 81 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Oh, it's so hard every day…\p"
# 82 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "What's hard?\n"
# 83 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "You need to ask?\p"
# 84 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "It's trying to figure out what to\n"
# 85 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "make for meals every day.\p"
# 86 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "It really isn't easy coming up with\n"
# 87 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "meals every day.$"
# 88 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 89 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
# 90 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Oh, hello!\n"
# 91 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Welcome to the PEPPER household.\p"
# 92 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "I have a question for you.\n"
# 93 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Have you ever baby-sat?\p"
# 94 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "You see, I'm a new father, so raising\n"
# 95 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "a child is all new to me.\p"
# 96 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "And I have a problem. My daughter\n"
# 97 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "WALDA doesn't laugh enough.\p"
# 98 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "I think she'd laugh for me if I told\n"
# 99 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "her something funny.\p"
# 100 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Do you know of a funny word or\n"
# 101 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "phrase you can tell me?$"
# 102 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 103 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
# 104 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "I've been saying “{STR_VAR_1}”\n"
# 105 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "to amuse her lately.\p"
# 106 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Do you know of a better word or\n"
# 107 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "a phrase that might work?$"
# 108 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 109 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
# 110 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Oh, that's wonderful.\n"
# 111 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "So, let's hear it, your suggestion.$"
# 112 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 113 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_OhIsThatRight:
# 114 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Oh, is that right?\p"
# 115 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Well, if you come up with a good\n"
# 116 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "suggestion, I'm all ears.$"
# 117 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 118 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
# 119 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Ah, I see.\n"
# 120 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Well, let's give it a try, shall we?$"
# 121 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 122 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_OhShesLaughing:
# 123 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "{STR_VAR_1}.\n"
# 124 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "{STR_VAR_1}.\p"
# 125 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Oh, yes! She's laughing!\n"
# 126 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Oh, I am as delighted as she!$"
# 127 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 128 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_LetsGiveItATry:
# 129 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Ah, I see.\n"
# 130 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Well, let's give it a try, shall we?$"
# 131 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 132 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
# 133 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "{STR_VAR_1}.\n"
# 134 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "{STR_VAR_1}.\p"
# 135 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Hmmm… She's not smiling at all.\n"
# 136 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Maybe WALDA is one serious child…$"
# 137 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 138 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
# 139 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Oh, so you don't know any good words.\n"
# 140 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "I'd better think for myself, then.\p"
# 141 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Hmm…\n"
# 142 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "How about “{STR_VAR_1}”?\l"
# 143 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Let's see if that will work.$"
# 144 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 145 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
# 146 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "{STR_VAR_1}.\n"
# 147 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "{STR_VAR_1}.\p"
# 148 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Hmmm… She's not smiling at all.\n"
# 149 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Maybe WALDA is one serious child…$"
# 150 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 151 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
# 152 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Oh, so you don't know any good words.\n"
# 153 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "I guess I'll try to amuse her with\l"
# 154 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "the saying I used before.\p"
# 155 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Anyways, if you have a good suggestion,\n"
# 156 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "don't hesitate in telling me, okay?$"
# 157 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 158 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
# 159 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Thank you!\p"
# 160 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Thanks to you, my darling WALDA\n"
# 161 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "laughed for me!\p"
# 162 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Actually, I may not look all that\n"
# 163 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "special, but I'm one of DEVON\l"
# 164 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "CORPORATION's top researchers.\p"
# 165 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "So, how about I do something in return\n"
# 166 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "for you?\p"
# 167 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "I know, I'll add some new wallpaper\n"
# 168 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "patterns for the BOXES in the PC\l"
# 169 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "POKéMON Storage System.\p"
# 170 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "In the wallpaper pattern menu,\n"
# 171 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "select “FRIENDS.”\p"
# 172 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "That will give you access to the new\n"
# 173 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "wallpaper patterns.$"
# 174 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 175 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
# 176 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "It's a POKéMON plush DOLL!$"
