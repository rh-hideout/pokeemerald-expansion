Route45_MapScripts::
	.byte 0

Route45_EventScript_Erik::
	trainerbattle_single TRAINER_ERIK Route45_Text_HikerErikSeen, Route45_Text_HikerErikBeaten
	msgbox Route45_Text_HikerErikAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Michael::
	trainerbattle_single TRAINER_MICHAEL Route45_Text_HikerMichaelSeen, Route45_Text_HikerMichaelBeaten
	msgbox Route45_Text_HikerMichaelAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Parry::
	trainerbattle_single TRAINER_PARRY Route45_Text_HikerParrySeen, Route45_Text_HikerParryBeaten
	msgbox Route45_Text_HikerParryAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Timothy::
	trainerbattle_single TRAINER_TIMOTHY Route45_Text_HikerTimothySeen, Route45_Text_HikerTimothyBeaten
	msgbox Route45_Text_HikerTimothyAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Kenji::
	trainerbattle_single TRAINER_KENJI Route45_Text_BlackbeltKenjiSeen, Route45_Text_BlackbeltKenjiBeaten
	msgbox Route45_Text_BlackbeltKenjiAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Ryan::
	trainerbattle_single TRAINER_RYAN Route45_Text_CooltrainermRyanSeen, Route45_Text_CooltrainermRyanBeaten
	msgbox Route45_Text_CooltrainermRyanAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Kelly::
	trainerbattle_single TRAINER_KELLY Route45_Text_CooltrainerfKellySeen, Route45_Text_CooltrainerfKellyBeaten
	msgbox Route45_Text_CooltrainerfKellyAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Quentin::
	trainerbattle_single TRAINER_QUENTIN Route45_Text_CamperQuentinSeen, Route45_Text_CamperQuentinBeaten
	msgbox Route45_Text_CamperQuentinAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Sign::
	msgbox Route45_Text_Sign, MSGBOX_SIGN
	end

Route45_EventScript_Item_Elixir::
	finditem ITEM_ELIXIR
	end

Route45_EventScript_Item_Max_Potion::
	finditem ITEM_MAX_POTION
	end

Route45_EventScript_Item_Full_Heal::
	finditem ITEM_FULL_HEAL
	end

Route45_EventScript_Item_Nugget::
	finditem ITEM_NUGGET
	end

Route45_Text_HikerErikSeen:
    .string "Be prepared for anything!\p"
    .string "Let me see if your POKéMON have\n"
    .string "been raised properly!$"

Route45_Text_HikerErikBeaten:
    .string "Oh, I lost that!$"

Route45_Text_HikerErikAfter:
    .string "I'll head back to BLACKTHORN's\n"
    .string "ICE PATH and train some more.$"

Route45_Text_HikerMichaelSeen:
    .string "Yo! You're spunky! But you know\n"
    .string "what?\p"
    .string "When it comes to sheer\n"
    .string "spunkiness, I'm the man!$"

Route45_Text_HikerMichaelBeaten:
    .string "My POKéMON weren't spunky enough!$"

Route45_Text_HikerMichaelAfter:
    .string "Boy, do I love HP UP! Mmmm, yum!\p"
    .string "I keep drinking my POKéMON's!\p"
    .string "I can't help it!$"

Route45_Text_HikerParrySeen:
    .string "My POKéMON are power packed!$"

Route45_Text_HikerParryBeaten:
    .string "Wahahah! I'm the big loser!$"

Route45_Text_HikerParryAfter:
    .string "I'm not much good at thinking,\n"
    .string "see?\p"
    .string "So, I just plow ahead with power!$"


Route45_Text_HikerTimothySeen:
    .string "Why do I climb mountains?\p"
    .string "Because they're there.\p"
    .string "Why do I train POKéMON?\p"
    .string "Because they're there!$"

Route45_Text_HikerTimothyBeaten:
    .string "Losses… They're there too!$"

Route45_Text_HikerTimothyAfter:
    .string "The best thing to ever happen to\n"
    .string "me was discovering POKéMON.$"

Route45_Text_HikerParryGivesIron:
    .string "I just can't find a way to win!\p"
    .string "Keep it up!\p"
    .string "Oh, and take this -- it's the\n"
    .string "gift you couldn't take when we\n"
    .string "last met.$"

Route45_Text_BlackbeltKenjiSeen:
    .string "I was training here alone.\p"
    .string "Behold the fruits of my labor!$"

Route45_Text_BlackbeltKenjiBeaten:
    .string "Waaaargh!$"

Route45_Text_BlackbeltKenjiAfter:
    .string "This calls for extreme measures.\p"
    .string "I must take to the hills and train\n"
    .string "in solitude.$"

Route45_Text_BlackbeltKenjiMorning:
    .string "I'm going to train a bit more\n"
    .string "before I break for lunch.$"

Route45_Text_BlackbeltKenjiNight:
    .string "We had plenty of rest at lunch, so\p"
    .string "now we're all ready to go again!\p"
    .string "We're going to train again!$"

Route45_Text_CooltrainermRyanSeen:
    .string "What are your thoughts on\n"
    .string "raising POKéMON?$"

Route45_Text_CooltrainermRyanBeaten:
    .string "You've won my respect.$"

Route45_Text_CooltrainermRyanAfter:
    .string "I see you're raising your POKéMON\n"
    .string "with care.\p"
    .string "The bond you build will save you\n"
    .string "in tough situations.$"

Route45_Text_CooltrainerfKellySeen:
    .string "What is your battle strategy?\p"
    .string "It is foolish to use strong moves\n"
    .string "indiscriminately.$"

Route45_Text_CooltrainerfKellyBeaten:
    .string "Fine. I lost.$"

Route45_Text_CooltrainerfKellyAfter:
    .string "I'm not in favor of overly\n"
    .string "powerful moves.\p"
    .string "I want to win, but I also don't\n"
    .string "want to harm POKéMON.$"

Route45_Text_CamperQuentinSeen:
    .string "I'm really, really tough!$"

Route45_Text_CamperQuentinBeaten:
    .string "I was tough at the TRAINER HILL…$"

Route45_Text_CamperQuentinAfter:
    .string "Have you been to the TRAINER HILL?\p"
    .string "I never, ever lose there, but…$"

Route45_Text_Sign:
    .string "ROUTE 45\n"
    .string "MOUNTAIN RD. AHEAD$"
