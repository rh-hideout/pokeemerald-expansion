MtSilver_1F_WaterfallRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_1F_WaterfallRoom_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtSilver_1F_WaterfallRoom_OnTransition: 
	callnative SetTimeBasedEncounters
	end

MtSilver_1F_WaterfallRoom_EventScript_MaxPotion::
	finditem ITEM_MAX_POTION
	end

MtSilver_1F_WaterfallRoom_EventScript_DireHit::
	finditem ITEM_DIRE_HIT
	end

MtSilver_1F_WaterfallRoom_EventScript_FullRestore::
	finditem ITEM_FULL_RESTORE
	end

MtSilver_1F_WaterfallRoom_EventScript_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

MtSilver_1F_WaterfallRoom_EventScript_SpellTag::
	finditem ITEM_SPELL_TAG
	end
