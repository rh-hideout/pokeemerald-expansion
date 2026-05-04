WhirlIslands_Descent_MapScripts::
	.byte 0

WhirlIslands_Descent_EventScript_Item_Max_Revive::
	finditem ITEM_MAX_REVIVE
	end

WhirlIslands_Descent_EventScript_Item_Full_Restore::
	finditem ITEM_FULL_RESTORE
	end

WhirlIslands_Descent_EventScript_Item_PP_Max::
	finditem ITEM_PP_MAX
	end

WhirlIslands_B2F_Trigger_Fog::
	setweather WEATHER_FOG_HORIZONTAL
	doweather
	end
