NuvemaTownOverworld_MapScripts::
	.byte 0


NuvemaTownOverworld_EventScript_NPC0::
# 8 "data/maps/NuvemaTownOverworld/scripts.pory"
	lock
# 9 "data/maps/NuvemaTownOverworld/scripts.pory"
	faceplayer
# 10 "data/maps/NuvemaTownOverworld/scripts.pory"
	msgbox NuvemaTownOverworld_EventScript_NPC0_Text_0, MSGBOX_YESNO
# 11 "data/maps/NuvemaTownOverworld/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NuvemaTownOverworld_EventScript_NPC0_2
# 14 "data/maps/NuvemaTownOverworld/scripts.pory"
	msgbox NuvemaTownOverworld_EventScript_NPC0_Text_2
NuvemaTownOverworld_EventScript_NPC0_1:
# 16 "data/maps/NuvemaTownOverworld/scripts.pory"
	release
	end

NuvemaTownOverworld_EventScript_NPC0_2:
# 12 "data/maps/NuvemaTownOverworld/scripts.pory"
	msgbox NuvemaTownOverworld_EventScript_NPC0_Text_1
	goto NuvemaTownOverworld_EventScript_NPC0_1


NuvemaTownOverworld_EventScript_NPC1::
# 21 "data/maps/NuvemaTownOverworld/scripts.pory"
	lock
# 22 "data/maps/NuvemaTownOverworld/scripts.pory"
	faceplayer
# 23 "data/maps/NuvemaTownOverworld/scripts.pory"
	msgbox NuvemaTownOverworld_EventScript_NPC1_Text_0, MSGBOX_YESNO
# 24 "data/maps/NuvemaTownOverworld/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NuvemaTownOverworld_EventScript_NPC1_2
NuvemaTownOverworld_EventScript_NPC1_1:
# 28 "data/maps/NuvemaTownOverworld/scripts.pory"
	release
	end

NuvemaTownOverworld_EventScript_NPC1_2:
# 25 "data/maps/NuvemaTownOverworld/scripts.pory"
	msgbox NuvemaTownOverworld_EventScript_NPC1_Text_1
	goto NuvemaTownOverworld_EventScript_NPC1_1


NuvemaTownOverworld_EventScript_NPC2::
# 33 "data/maps/NuvemaTownOverworld/scripts.pory"
	lock
# 34 "data/maps/NuvemaTownOverworld/scripts.pory"
	faceplayer
# 35 "data/maps/NuvemaTownOverworld/scripts.pory"
	msgbox NuvemaTownOverworld_EventScript_NPC2_Text_0, MSGBOX_NPC
# 36 "data/maps/NuvemaTownOverworld/scripts.pory"
	release
	end


NuvemaTownOverworld_EventScript_NPC3::
# 41 "data/maps/NuvemaTownOverworld/scripts.pory"
	lock
# 42 "data/maps/NuvemaTownOverworld/scripts.pory"
	faceplayer
# 43 "data/maps/NuvemaTownOverworld/scripts.pory"
	msgbox NuvemaTownOverworld_EventScript_NPC3_Text_0, MSGBOX_NPC
# 44 "data/maps/NuvemaTownOverworld/scripts.pory"
	release
	end


NuvemaTownOverworld_EventScript_NPC4::
# 49 "data/maps/NuvemaTownOverworld/scripts.pory"
	lock
# 50 "data/maps/NuvemaTownOverworld/scripts.pory"
	faceplayer
# 51 "data/maps/NuvemaTownOverworld/scripts.pory"
	msgbox NuvemaTownOverworld_EventScript_NPC4_Text_0, MSGBOX_NPC
# 52 "data/maps/NuvemaTownOverworld/scripts.pory"
	release
	end


NuvemaTownOverworld_EventScript_NPC5::
# 57 "data/maps/NuvemaTownOverworld/scripts.pory"
	lock
# 58 "data/maps/NuvemaTownOverworld/scripts.pory"
	faceplayer
# 60 "data/maps/NuvemaTownOverworld/scripts.pory"
	release
	end


NuvemaTownOverworld_EventScript_Sign0::
# 65 "data/maps/NuvemaTownOverworld/scripts.pory"
	msgbox NuvemaTownOverworld_EventScript_Sign0_Text_0, MSGBOX_SIGN
	end


NuvemaTownOverworld_EventScript_Sign1::
# 70 "data/maps/NuvemaTownOverworld/scripts.pory"
	msgbox NuvemaTownOverworld_EventScript_Sign1_Text_0, MSGBOX_SIGN
	end


NuvemaTownOverworld_EventScript_Sign2::
# 75 "data/maps/NuvemaTownOverworld/scripts.pory"
	msgbox NuvemaTownOverworld_EventScript_Sign2_Text_0, MSGBOX_SIGN
	end


NuvemaTownOverworld_EventScript_Sign3::
# 80 "data/maps/NuvemaTownOverworld/scripts.pory"
	msgbox NuvemaTownOverworld_EventScript_Sign3_Text_0, MSGBOX_SIGN
	end


NuvemaTownOverworld_EventScript_Sign4::
# 85 "data/maps/NuvemaTownOverworld/scripts.pory"
	msgbox NuvemaTownOverworld_EventScript_Sign4_Text_0, MSGBOX_SIGN
	end


NuvemaTownOverworld_EventScript_Trigger0::
# 90 "data/maps/NuvemaTownOverworld/scripts.pory"
	lockall
# 92 "data/maps/NuvemaTownOverworld/scripts.pory"
	msgbox NuvemaTownOverworld_EventScript_Trigger0_Text_0
# 93 "data/maps/NuvemaTownOverworld/scripts.pory"
	releaseall
	end


NuvemaTownOverworld_EventScript_Trigger1::
# 98 "data/maps/NuvemaTownOverworld/scripts.pory"
	lockall
# 100 "data/maps/NuvemaTownOverworld/scripts.pory"
	msgbox NuvemaTownOverworld_EventScript_Trigger1_Text_0
# 101 "data/maps/NuvemaTownOverworld/scripts.pory"
	msgbox NuvemaTownOverworld_EventScript_Trigger1_Text_1
# 102 "data/maps/NuvemaTownOverworld/scripts.pory"
	msgbox NuvemaTownOverworld_EventScript_Trigger1_Text_2
# 103 "data/maps/NuvemaTownOverworld/scripts.pory"
	msgbox NuvemaTownOverworld_EventScript_Trigger1_Text_3
# 104 "data/maps/NuvemaTownOverworld/scripts.pory"
	msgbox NuvemaTownOverworld_EventScript_Trigger1_Text_4
# 105 "data/maps/NuvemaTownOverworld/scripts.pory"
	msgbox NuvemaTownOverworld_EventScript_Trigger1_Text_5
# 106 "data/maps/NuvemaTownOverworld/scripts.pory"
	msgbox NuvemaTownOverworld_EventScript_Trigger1_Text_6
# 107 "data/maps/NuvemaTownOverworld/scripts.pory"
	msgbox NuvemaTownOverworld_EventScript_Trigger1_Text_7
# 108 "data/maps/NuvemaTownOverworld/scripts.pory"
	msgbox NuvemaTownOverworld_EventScript_Trigger1_Text_8
# 109 "data/maps/NuvemaTownOverworld/scripts.pory"
	msgbox NuvemaTownOverworld_EventScript_Trigger1_Text_9
# 110 "data/maps/NuvemaTownOverworld/scripts.pory"
	msgbox NuvemaTownOverworld_EventScript_Trigger1_Text_10
# 111 "data/maps/NuvemaTownOverworld/scripts.pory"
	msgbox NuvemaTownOverworld_EventScript_Trigger1_Text_11
# 112 "data/maps/NuvemaTownOverworld/scripts.pory"
	msgbox NuvemaTownOverworld_EventScript_Trigger1_Text_12
# 113 "data/maps/NuvemaTownOverworld/scripts.pory"
	msgbox NuvemaTownOverworld_EventScript_Trigger1_Text_13
# 114 "data/maps/NuvemaTownOverworld/scripts.pory"
	msgbox NuvemaTownOverworld_EventScript_Trigger1_Text_14
# 115 "data/maps/NuvemaTownOverworld/scripts.pory"
	releaseall
	end


NuvemaTownOverworld_EventScript_NPC0_Text_0:
# 10 "data/maps/NuvemaTownOverworld/scripts.pory"
	.string "Do you think traveling with Pokémon\n"
	.string "changes people?$"

NuvemaTownOverworld_EventScript_NPC0_Text_1:
# 12 "data/maps/NuvemaTownOverworld/scripts.pory"
	.string "Me too! Traveling and thinking about\n"
	.string "many things can definitely make a\l"
	.string "difference.$"

NuvemaTownOverworld_EventScript_NPC0_Text_2:
# 14 "data/maps/NuvemaTownOverworld/scripts.pory"
	.string "You're right! It's fine to just enjoy\n"
	.string "the journey without overthinking it!$"

NuvemaTownOverworld_EventScript_NPC1_Text_0:
# 23 "data/maps/NuvemaTownOverworld/scripts.pory"
	.string "Cheren: OK! Let's go meet the\n"
	.string "professor.$"

NuvemaTownOverworld_EventScript_NPC1_Text_1:
# 25 "data/maps/NuvemaTownOverworld/scripts.pory"
	.string "Cheren: I'm sorry, but could you go to\n"
	.string "Bianca's house? I'll bet she's spacing\l"
	.string "out like she usually does. She's totally\l"
	.string "flighty.$"

NuvemaTownOverworld_EventScript_NPC2_Text_0:
# 35 "data/maps/NuvemaTownOverworld/scripts.pory"
	.string "Cheren: {PLAYER}!\n"
	.string "I understand the feeling. I want to go\l"
	.string "somewhere with my Pokémon too, but\l"
	.string "first we have to go thank Professor\l"
	.string "Juniper. Come on. The lab is this way!$"

NuvemaTownOverworld_EventScript_NPC3_Text_0:
# 43 "data/maps/NuvemaTownOverworld/scripts.pory"
	.string "Nuvema Town The Start of Something\n"
	.string "Big!$"

NuvemaTownOverworld_EventScript_NPC4_Text_0:
# 51 "data/maps/NuvemaTownOverworld/scripts.pory"
	.string "I've heard there are a lot of Pokémon\n"
	.string "and many different people in the world.\l"
	.string "When I hear stories about them, I get\l"
	.string "very excited!$"

NuvemaTownOverworld_EventScript_Sign0_Text_0:
# 65 "data/maps/NuvemaTownOverworld/scripts.pory"
	.string "Mom: Oh, there you are! And...? What did\n"
	.string "the professor have to say? She asked\l"
	.string "you to complete the Pokédex?! I can't\l"
	.string "believe it!$"

NuvemaTownOverworld_EventScript_Sign1_Text_0:
# 70 "data/maps/NuvemaTownOverworld/scripts.pory"
	.string "{PLAYER}'s House$"

NuvemaTownOverworld_EventScript_Sign2_Text_0:
# 75 "data/maps/NuvemaTownOverworld/scripts.pory"
	.string "Cheren's House$"

NuvemaTownOverworld_EventScript_Sign3_Text_0:
# 80 "data/maps/NuvemaTownOverworld/scripts.pory"
	.string "Juniper Pokémon Lab$"

NuvemaTownOverworld_EventScript_Sign4_Text_0:
# 85 "data/maps/NuvemaTownOverworld/scripts.pory"
	.string "Bianca's House$"

NuvemaTownOverworld_EventScript_Trigger0_Text_0:
# 92 "data/maps/NuvemaTownOverworld/scripts.pory"
	.string "Bianca: ...That's a secret, OK?$"

NuvemaTownOverworld_EventScript_Trigger1_Text_0:
# 100 "data/maps/NuvemaTownOverworld/scripts.pory"
	.string "Cheren: Hey, {PLAYER}. Is Looker\n"
	.string "through talking to you?$"

NuvemaTownOverworld_EventScript_Trigger1_Text_1:
# 101 "data/maps/NuvemaTownOverworld/scripts.pory"
	.string "Bianca: ...I'm sorry. By the time I went\n"
	.string "to get the Striaton City Gym Leaders,\l"
	.string "everything was over...$"

NuvemaTownOverworld_EventScript_Trigger1_Text_2:
# 102 "data/maps/NuvemaTownOverworld/scripts.pory"
	.string "Cheren: If that's the case... I let\n"
	.string "Ghetsis escape when the Shadow Triad\l"
	.string "created an opening.$"

NuvemaTownOverworld_EventScript_Trigger1_Text_3:
# 103 "data/maps/NuvemaTownOverworld/scripts.pory"
	.string "Bianca: ...Ghetsis? The Shadow Triad?$"

NuvemaTownOverworld_EventScript_Trigger1_Text_4:
# 104 "data/maps/NuvemaTownOverworld/scripts.pory"
	.string "Cheren: I'll tell you later about what\n"
	.string "happened in the castle. It's more\l"
	.string "important to ask what you plan to do\l"
	.string "now, Bianca.$"

NuvemaTownOverworld_EventScript_Trigger1_Text_5:
# 105 "data/maps/NuvemaTownOverworld/scripts.pory"
	.string "Cheren: That's the city on the other\n"
	.string "side of Route 16 when you leave from\l"
	.string "Nimbasa City. Hmm. If you go that way,\l"
	.string "you might be able to meet all sorts of\l"
	.string "Pokémon you've never seen before.$"

NuvemaTownOverworld_EventScript_Trigger1_Text_6:
# 106 "data/maps/NuvemaTownOverworld/scripts.pory"
	.string "Cedric: Oh! Well, this is nice timing! I\n"
	.string "see you're all here!$"

NuvemaTownOverworld_EventScript_Trigger1_Text_7:
# 107 "data/maps/NuvemaTownOverworld/scripts.pory"
	.string "Just a moment ago, I got some National\n"
	.string "Pokédex data from an acquaintance.\l"
	.string "Since you're here, let's upgrade your\l"
	.string "Pokédex with the National Pokédex\l"
	.string "data. I'm sure you'll be visiting a wider\l"
	.string "range of places. Naturally, that means\l"
	.string "you'll be encountering more Pokémon.\l"
	.string "Let me see your Pokédex for a sec!$"

NuvemaTownOverworld_EventScript_Trigger1_Text_8:
# 108 "data/maps/NuvemaTownOverworld/scripts.pory"
	.string "There you go, Bianca!$"

NuvemaTownOverworld_EventScript_Trigger1_Text_9:
# 109 "data/maps/NuvemaTownOverworld/scripts.pory"
	.string "Next up is Cheren!$"

NuvemaTownOverworld_EventScript_Trigger1_Text_10:
# 110 "data/maps/NuvemaTownOverworld/scripts.pory"
	.string "And last, but not least...$"

NuvemaTownOverworld_EventScript_Trigger1_Text_11:
# 111 "data/maps/NuvemaTownOverworld/scripts.pory"
	.string "{PLAYER}'s Pokédex was upgraded with\n"
	.string "the National Mode!$"

NuvemaTownOverworld_EventScript_Trigger1_Text_12:
# 112 "data/maps/NuvemaTownOverworld/scripts.pory"
	.string "Bianca: Wow, the National Pokédex... It\n"
	.string "looks like there are tons of Pokémon I\l"
	.string "don't know yet! Oh! Ooh! I want to show\l"
	.string "Mom and Dad my Pokédex! I gotta go!\l"
	.string "Let's meet again somewhere, OK?!$"

NuvemaTownOverworld_EventScript_Trigger1_Text_13:
# 113 "data/maps/NuvemaTownOverworld/scripts.pory"
	.string "Cheren: Huh. Bianca's as impetuous as\n"
	.string "ever, no matter what is going on.$"

NuvemaTownOverworld_EventScript_Trigger1_Text_14:
# 114 "data/maps/NuvemaTownOverworld/scripts.pory"
	.string "I think I'll travel all the way around\n"
	.string "Unova, starting at Route 1 again. I'm\l"
	.string "sure I'll discover lots of new things.\l"
	.string "Could be I'll encounter the Seven Sages\l"
	.string "along the way... And, {PLAYER}, if we spy\l"
	.string "each other along the way, let's battle\l"
	.string "again, OK?$"
