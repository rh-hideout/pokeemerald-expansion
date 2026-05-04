MtMortar_1F_South_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMortar_1F_South_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtMortar_1F_South_OnTransition: 
	callnative SetTimeBasedEncounters
	end



MtMortar_1F_South_EventScript_Item_Revive::
    finditem ITEM_REVIVE
    end

MtMortar_1F_South_EventScript_Item_Elixir::
    finditem ITEM_ELIXIR
    end
