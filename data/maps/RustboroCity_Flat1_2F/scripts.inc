# 1 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 2 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
.set LOCALID_WALDAS_DAD, 6
# 3 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 4 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_MapScripts::
# 5 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.byte 0
# 6 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 7 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_WaldasDad::
# 8 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	lock
# 9 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	faceplayer
# 10 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	specialvar VAR_RESULT, TryBufferWaldaPhrase
# 11 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
# 12 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase
# 13 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 14 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_GivePhrase::
# 15 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	special DoWaldaNamingScreen
# 16 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	waitstate
# 17 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
# 18 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
# 19 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
# 20 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
# 21 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
# 22 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	end
# 23 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 24 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
# 25 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
# 26 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
# 27 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
# 28 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase
# 29 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 30 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
# 31 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
# 32 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
# 33 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
# 34 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase
# 35 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 36 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
# 37 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
# 38 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	release
# 39 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	end
# 40 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 41 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
# 42 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
# 43 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	release
# 44 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	end
# 45 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 46 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
# 47 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
# 48 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
# 49 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
# 50 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	release
# 51 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	end
# 52 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 53 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
# 54 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
# 55 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
# 56 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
# 57 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	applymovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
# 58 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	waitmovement 0
# 59 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
# 60 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	release
# 61 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	end
# 62 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 63 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
# 64 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
# 65 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
# 66 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
# 67 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	release
# 68 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	end
# 69 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 70 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
# 71 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
# 72 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	return
# 73 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 74 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_WaldasMom::
# 75 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
# 76 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	end
# 77 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 78 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_EventScript_PokeDoll::
# 79 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
# 80 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	end
# 81 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 82 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
# 83 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Oh, it's so hard every day…\p"
# 84 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "What's hard?\n"
# 85 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "You need to ask?\p"
# 86 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "It's trying to figure out what to\n"
# 87 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "make for meals every day.\p"
# 88 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "It really isn't easy coming up with\n"
# 89 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "meals every day.$"
# 90 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 91 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
# 92 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Oh, hello!\n"
# 93 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Welcome to the PEPPER household.\p"
# 94 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "I have a question for you.\n"
# 95 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Have you ever baby-sat?\p"
# 96 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "You see, I'm a new father, so raising\n"
# 97 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "a child is all new to me.\p"
# 98 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "And I have a problem. My daughter\n"
# 99 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "WALDA doesn't laugh enough.\p"
# 100 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "I think she'd laugh for me if I told\n"
# 101 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "her something funny.\p"
# 102 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Do you know of a funny word or\n"
# 103 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "phrase you can tell me?$"
# 104 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 105 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
# 106 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "I've been saying “{STR_VAR_1}”\n"
# 107 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "to amuse her lately.\p"
# 108 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Do you know of a better word or\n"
# 109 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "a phrase that might work?$"
# 110 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 111 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
# 112 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Oh, that's wonderful.\n"
# 113 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "So, let's hear it, your suggestion.$"
# 114 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 115 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_OhIsThatRight:
# 116 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Oh, is that right?\p"
# 117 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Well, if you come up with a good\n"
# 118 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "suggestion, I'm all ears.$"
# 119 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 120 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
# 121 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Ah, I see.\n"
# 122 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Well, let's give it a try, shall we?$"
# 123 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 124 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_OhShesLaughing:
# 125 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "{STR_VAR_1}.\n"
# 126 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "{STR_VAR_1}.\p"
# 127 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Oh, yes! She's laughing!\n"
# 128 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Oh, I am as delighted as she!$"
# 129 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 130 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_LetsGiveItATry:
# 131 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Ah, I see.\n"
# 132 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Well, let's give it a try, shall we?$"
# 133 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 134 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
# 135 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "{STR_VAR_1}.\n"
# 136 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "{STR_VAR_1}.\p"
# 137 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Hmmm… She's not smiling at all.\n"
# 138 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Maybe WALDA is one serious child…$"
# 139 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 140 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
# 141 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Oh, so you don't know any good words.\n"
# 142 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "I'd better think for myself, then.\p"
# 143 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Hmm…\n"
# 144 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "How about “{STR_VAR_1}”?\l"
# 145 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Let's see if that will work.$"
# 146 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 147 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
# 148 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "{STR_VAR_1}.\n"
# 149 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "{STR_VAR_1}.\p"
# 150 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Hmmm… She's not smiling at all.\n"
# 151 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Maybe WALDA is one serious child…$"
# 152 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 153 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
# 154 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Oh, so you don't know any good words.\n"
# 155 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "I guess I'll try to amuse her with\l"
# 156 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "the saying I used before.\p"
# 157 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Anyways, if you have a good suggestion,\n"
# 158 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "don't hesitate in telling me, okay?$"
# 159 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 160 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
# 161 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Thank you!\p"
# 162 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Thanks to you, my darling WALDA\n"
# 163 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "laughed for me!\p"
# 164 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "Actually, I may not look all that\n"
# 165 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "special, but I'm one of DEVON\l"
# 166 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "CORPORATION's top researchers.\p"
# 167 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "So, how about I do something in return\n"
# 168 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "for you?\p"
# 169 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "I know, I'll add some new wallpaper\n"
# 170 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "patterns for the BOXES in the PC\l"
# 171 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "POKéMON Storage System.\p"
# 172 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "In the wallpaper pattern menu,\n"
# 173 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "select “FRIENDS.”\p"
# 174 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "That will give you access to the new\n"
# 175 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "wallpaper patterns.$"
# 176 "data/maps/RustboroCity_Flat1_2F/scripts.pory"

# 177 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
# 178 "data/maps/RustboroCity_Flat1_2F/scripts.pory"
	.string "It's a POKéMON plush DOLL!$"
