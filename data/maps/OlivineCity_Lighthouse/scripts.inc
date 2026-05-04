.set LOCALID_LIGHTHOUSE_JASMINE, 12
.set LOCALID_LIGHTHOUSE_AMPHAROS, 13

OlivineCity_Lighthouse_MapScripts::
	.byte 0

OlivineLighthouse_EventScript_Item_Ether::
    finditem ITEM_ETHER
    end

OlivineLighthouse_EventScript_Item_RareCandy::
    finditem ITEM_RARE_CANDY
    end

OlivineLighthouse_EventScript_Item_TMBulkUp::
    finditem ITEM_TM_BULK_UP
    end

OlivineLighthouse_EventScript_Item_HyperPotion::
    finditem ITEM_HYPER_POTION
    end

OlivineLighthouse_EventScript_Item_Protein::
    finditem ITEM_PROTEIN
    end

OlivineLighthouse_EventScript_1FSailor::
	lock
	faceplayer
	msgbox OlivineLighthouse_Text_1FSailor, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_EventScript_1FPokefanF::
	lock
	faceplayer
	msgbox OlivineLighthouse_Text_1FPokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_1FSailor:
	.string "People train at this LIGHTHOUSE.\p"
	.string "It's not easy to climb with all\n"
	.string "the trainers waiting inside.$"

OlivineLighthouse_Text_1FPokefanF:
	.string "In the past, POKéMON used to light\n"
	.string "the sea around OLIVINE at night.\p"
	.string "The LIGHTHOUSE was built in honor\n"
	.string "of those noble POKéMON.$"

@2nd floor==============================================================================================================================

OlivineLighthouse_EventScript_Huey::
	trainerbattle_single TRAINER_HUEY, OlivineLighthouse_Text_SailorHueySeen, OlivineLighthouse_Text_SailorHueyBeaten
	msgbox OlivineLighthouse_Text_SailorHueyAfter, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse_EventScript_GentlemanAlfred::
    trainerbattle_single TRAINER_ALFRED, OlivineLighthouse_Text_GentlemanAlfredSeen, OlivineLighthouse_Text_GentlemanAlfredBeaten
    msgbox OlivineLighthouse_Text_GentlemanAlfredAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_Text_SailorHueySeen:
	.string "Men of the sea are always\n"
	.string "spoiling for a good fight!$"

OlivineLighthouse_Text_SailorHueyBeaten:
	.string "Urf!\n"
	.string "I lose!$"

OlivineLighthouse_Text_SailorHueyAfter:
	.string "What power! How would you like\n"
	.string "to sail the seas with me?$"

OlivineLighthouse_Text_GentlemanAlfredSeen:
	.string "Hm? This is no place\n"
	.string "for playing.$"

OlivineLighthouse_Text_GentlemanAlfredBeaten:
	.string "Ah! I can see that you're\n"
	.string "serious.$"

OlivineLighthouse_Text_GentlemanAlfredAfter:
	.string "Up top is a POKéMON that keeps\n"
	.string "the LIGHTHOUSE lit.\p"
	.string "But I hear that it's sick now,\n"
	.string "and can't be cured normally.$"

@3rd floor==============================================================================================================================

OlivineLighthouse_EventScript_BirdKeeperTheo::
    trainerbattle_single TRAINER_THEO, OlivineLighthouse_Text_BirdKeeperTheoSeen, OlivineLighthouse_Text_BirdKeeperTheoBeaten
    msgbox OlivineLighthouse_Text_BirdKeeperTheoAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_SailorTerrell::
    trainerbattle_single TRAINER_TERRELL, OlivineLighthouse_Text_SailorTerrellSeen, OlivineLighthouse_Text_SailorTerrellBeaten
    msgbox OlivineLighthouse_Text_SailorTerrellAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_GentlemanPreston::
    trainerbattle_single TRAINER_PRESTON, OlivineLighthouse_Text_GentlemanPrestonSeen, OlivineLighthouse_Text_GentlemanPrestonBeaten
    msgbox OlivineLighthouse_Text_GentlemanPrestonAfter, MSGBOX_AUTOCLOSE
    end


OlivineLighthouse_Text_BirdKeeperTheoSeen:
	.string "Why are you here? Are you just\n"
	.string "going to gawk? I suggest you leave!$"

OlivineLighthouse_Text_BirdKeeperTheoBeaten:
	.string "You really are concerned about\n"
	.string "the sick POKéMON…$"

OlivineLighthouse_Text_BirdKeeperTheoAfter:
	.string "How the heck do you go up?\p"
	.string "I want to visit the sick POKéMON,\n"
	.string "but I can't get up there…$"

OlivineLighthouse_Text_SailorTerrellSeen:
	.string "Sailors are both kind and strong.\n"
	.string "How about you?$"

OlivineLighthouse_Text_SailorTerrellBeaten:
	.string "You are both kind and strong…$"

OlivineLighthouse_Text_SailorTerrellAfter:
	.string "Every time I return to OLIVINE,\n"
	.string "I visit the GYM.\p"
	.string "The GYM LEADER’s POKéMON type\n"
	.string "changed without me noticing.$"

OlivineLighthouse_Text_GentlemanPrestonSeen:
	.string "I travel the world to train my\n"
	.string "POKéMON. I wish to battle you.$"

OlivineLighthouse_Text_GentlemanPrestonBeaten:
	.string "…sigh… I must train some more…$"

OlivineLighthouse_Text_GentlemanPrestonAfter:
	.string "JASMINE used to use ROCK-type\n"
	.string "POKéMON like ONIX.$"

@4th floor==============================================================================================================================

OlivineLighthouse_EventScript_SailorKent::
    trainerbattle_single TRAINER_KENT, OlivineLighthouse_Text_SailorKentSeen, OlivineLighthouse_Text_SailorKentBeaten
    msgbox OlivineLighthouse_Text_SailorKentAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_LassConnie::
    trainerbattle_single TRAINER_CONNIE, OlivineLighthouse_Text_LassConnieSeen, OlivineLighthouse_Text_LassConnieBeaten
    msgbox OlivineLighthouse_Text_LassConnieAfter, MSGBOX_AUTOCLOSE
    end


OlivineLighthouse_Text_SailorKentSeen:
	.string "JASMINE must be worried sick about\n"
	.string "the POKéMON here.\p"
	.string "She won't even smile these days.$"

OlivineLighthouse_Text_SailorKentBeaten:
	.string "I can't manage a smile either…$"

OlivineLighthouse_Text_SailorKentAfter:
	.string "Speaking of sick, I've heard there's\n"
	.string "a good PHARMACY in CIANWOOD.$"

OlivineLighthouse_Text_LassConnieSeen:
	.string "JASMINE is this city's GYM LEADER.\p"
	.string "I mean to bring her back with me.\p"
	.string "Nobody had better get in my way!$"

OlivineLighthouse_Text_LassConnieBeaten:
	.string "Aaack! My POKéMON!$"

OlivineLighthouse_Text_LassConnieAfter:
	.string "Right. Anybody would be worried if\n"
	.string "his or her own POKéMON were hurt.\p"
	.string "I'll pray for the POKéMON here, so\n"
	.string "JASMINE can come back to the GYM.$"

@5th floor==============================================================================================================================

OlivineLighthouse_EventScript_SailorErnest::
    trainerbattle_single TRAINER_ERNEST, OlivineLighthouse_Text_SailorErnestSeen, OlivineLighthouse_Text_SailorErnestBeaten
    msgbox OlivineLighthouse_Text_SailorErnestAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_BirdKeeperDenis::
    trainerbattle_single TRAINER_DENIS, OlivineLighthouse_Text_BirdKeeperDenisSeen, OlivineLighthouse_Text_BirdKeeperDenisBeaten
    msgbox OlivineLighthouse_Text_BirdKeeperDenisAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_Text_SailorErnestSeen:
	.string "I wanted to battle JASMINE, but she's\n"
	.string "not up to it now.\p"
	.string "So, how about you?$"

OlivineLighthouse_Text_SailorErnestBeaten:
	.string "Whoa, whoa. You're overwhelming!$"

OlivineLighthouse_Text_SailorErnestAfter:
	.string "A GYM LEADER isn't just about being\n"
	.string "strong.\p"
	.string "A LEADER also needs to be\n"
	.string "compassionate.$"

OlivineLighthouse_Text_BirdKeeperDenisSeen:
	.string "We're pretty high up here. My bird\n"
	.string "POKéMON are in prime form.$"

OlivineLighthouse_Text_BirdKeeperDenisBeaten:
	.string "Oops… They crashed…$"

OlivineLighthouse_Text_BirdKeeperDenisAfter:
	.string "My POKéMON learned how to use FLY in\n"
	.string "CIANWOOD.\p"
	.string "Well, since I'm a loser, I'll FLY\n"
	.string "across the sea…$"

@6th floor==============================================================================================================================

OlivineLighthouse_EventScript_Jasmine::
	lock
	faceplayer
	goto_if_eq VAR_OLIVINE_CITY_STATE, 3, OlivineLighthouse_EventScript_JasmineGoGetPotion
	goto_if_eq VAR_OLIVINE_CITY_STATE, 4, OlivineLighthouse_EventScript_JasmineDeliverPotion
	msgbox OlivineLighthouse_Text_JasmineCianwoodPharmacy, MSGBOX_DEFAULT
	msgbox OlivineLighthouse_Text_JasmineGetMedicine, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 3
	release
	end
OlivineLighthouse_EventScript_JasmineGoGetPotion::
	msgbox OlivineLighthouse_Text_JasmineGetMedicine2, MSGBOX_DEFAULT
	release
	end


OlivineLighthouse_EventScript_Ampharos::
	lock
	faceplayer
	goto_if_lt VAR_OLIVINE_CITY_STATE, 5, OlivineLighthouse_EventScript_AmpharosSick
	fadescreen FADE_TO_WHITE
	playse SE_M_THUNDERBOLT2
	waitse
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPaluPalulu, MSGBOX_DEFAULT
	waitmoncry
	setflag FLAG_AMPHAROS_HEALED
	release
	end

OlivineLighthouse_EventScript_AmpharosSick::
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPalPaloo, MSGBOX_DEFAULT
	waitmoncry
	msgbox OlivineLighthouse_Text_AmphyBreathingLabored, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_JasmineCianwoodPharmacy:
	.string "JASMINE: …This POKéMON always kept\n"
	.string "the sea lit at night.\p"
	.string "…But it suddenly got sick… It's\n"
	.string "gasping for air…\p"
	.string "…I understand that there is a\n"
	.string "wonderful PHARMACY in CIANWOOD…\p"
	.string "But that's across the sea…\n"
	.string "And I can't leave AMPHY unattended…$"

OlivineLighthouse_Text_JasmineGetMedicine:
	.string "…May I ask you to get some medicine\n"
	.string "for me? Please?$"

OlivineLighthouse_Text_JasmineGetMedicine2:
	.string "There is a wonderful PHARMACY\n"
	.string "in CIANWOOD…\p"
	.string "But that's across the sea…\n"
	.string "And I can't leave AMPHY unattended…\p"
	.string "…May I ask you to get some medicine\n"
	.string "for me? Please?$"

OlivineLighthouse_Text_JasmineCureAmphy:
	.string "JASMINE: …Will that medicine cure\n"
	.string "AMPHY?$"


OlivineLighthouse_EventScript_JasmineDeliverPotion::
	msgbox OlivineLighthouse_Text_JasmineCureAmphy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivineLighthouse_EventScript_JasmineRefuse
	playse SE_USE_ITEM
	removeitem ITEM_SECRET_POTION
	msgbox OlivineLighthouse_Text_PlayerHandedSecretpotion, MSGBOX_DEFAULT
	waitse
	msgbox OlivineLighthouse_Text_JasmineDontBeOffended, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_LIGHTHOUSE_JASMINE, DIR_NORTH
	delay 20
	turnobject LOCALID_LIGHTHOUSE_AMPHAROS, DIR_SOUTH
	playse MUS_HEAL
	waitse
	msgbox OlivineLighthouse_Text_JasmineAmphyHowFeeling, MSGBOX_DEFAULT
	fadescreen FADE_TO_WHITE
	playse SE_M_THUNDERBOLT2
	waitse
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPaluPalulu, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	applymovement LOCALID_LIGHTHOUSE_AMPHAROS, OlivineLighthouse_Movement_Amphy
	waitmovement 0
	applymovement LOCALID_LIGHTHOUSE_JASMINE, OlivineLighthouse_Movement_Jasmine
	msgbox OlivineLighthouse_Text_JasmineThankYou, MSGBOX_DEFAULT
	closemessage

	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_LIGHTHOUSE_JASMINE
	removeobject LOCALID_LIGHTHOUSE_JASMINE
	waitse
	delay 50
	fadescreen FADE_FROM_BLACK
	setvar VAR_SAFARI_ZONE_GATE_STATE, 1
	setvar VAR_OLIVINE_CITY_STATE, 5
	setflag FLAG_AMPHAROS_HEALED
	clearflag FLAG_HIDE_OLIVINE_CITY_GYM_JASMINE
	release
	end

OlivineLighthouse_Movement_Jasmine:
	face_player
	step_end

OlivineLighthouse_Movement_Amphy:
	walk_up
	jump_in_place_down
	jump_in_place_left
	jump_in_place_right
	jump_in_place_up
	face_down
	step_end


OlivineLighthouse_EventScript_JasmineRefuse::
	msgbox OlivineLighthouse_Text_JasmineISee, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_PlayerHandedSecretpotion:
	.string "{PLAYER} handed the SECRET POTION to\n"
	.string "JASMINE.$"

OlivineLighthouse_Text_JasmineDontBeOffended:
	.string "JASMINE: …Um, please don't be\n"
	.string "offended…\p"
	.string "…AMPHY will not take anything from\n"
	.string "anyone but me…$"

OlivineLighthouse_Text_JasmineAmphyHowFeeling:
	.string "JASMINE: …\p"
	.string "AMPHY, how are you feeling?$"

OlivineLighthouse_Text_JasmineThankYou:
	.string "JASMINE: …Oh, I'm so relieved…\p"
	.string "This is just so wonderful…\p"
	.string "Thank you so very, very much.\p"
	.string "…I will return to the GYM…\p"
	.string "I'll also warn you, STEEL types\n"
	.string "are powerful.$"

OlivineLighthouse_Text_JasmineISee:
	.string "JASMINE: …I see…\n"
	.string "…AMPHY, hang on!$"

OlivineLighthouse_Text_AmphyPalPaloo:
	.string "AMPHY: …\n"
	.string "…Pa… paloo…$"

OlivineLighthouse_Text_AmphyBreathingLabored:
	.string "Its breathing is terribly\n"
	.string "labored…$"

OlivineLighthouse_Text_AmphyPaluPalulu:
	.string "AMPHY: Palu! Palulu!$"


