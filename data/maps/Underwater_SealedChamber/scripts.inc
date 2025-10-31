# 1 "data/maps/Underwater_SealedChamber/scripts.pory"

# 2 "data/maps/Underwater_SealedChamber/scripts.pory"
Underwater_SealedChamber_MapScripts::
# 3 "data/maps/Underwater_SealedChamber/scripts.pory"
	map_script MAP_SCRIPT_ON_DIVE_WARP, Underwater_SealedChamber_OnDive
# 4 "data/maps/Underwater_SealedChamber/scripts.pory"
	.byte 0
# 5 "data/maps/Underwater_SealedChamber/scripts.pory"

# 6 "data/maps/Underwater_SealedChamber/scripts.pory"
Underwater_SealedChamber_OnDive:
# 7 "data/maps/Underwater_SealedChamber/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 8 "data/maps/Underwater_SealedChamber/scripts.pory"
	goto_if_ne VAR_0x8004, 12, Underwater_SealedChamber_EventScript_SurfaceRoute134
# 9 "data/maps/Underwater_SealedChamber/scripts.pory"
	goto_if_ne VAR_0x8005, 44, Underwater_SealedChamber_EventScript_SurfaceRoute134
# 10 "data/maps/Underwater_SealedChamber/scripts.pory"
	goto Underwater_SealedChamber_EventScript_SurfaceSealedChamber
# 11 "data/maps/Underwater_SealedChamber/scripts.pory"

# 12 "data/maps/Underwater_SealedChamber/scripts.pory"
Underwater_SealedChamber_EventScript_SurfaceRoute134::
# 13 "data/maps/Underwater_SealedChamber/scripts.pory"
	setdivewarp MAP_ROUTE134, 60, 31
# 14 "data/maps/Underwater_SealedChamber/scripts.pory"
	end
# 15 "data/maps/Underwater_SealedChamber/scripts.pory"

# 16 "data/maps/Underwater_SealedChamber/scripts.pory"
Underwater_SealedChamber_EventScript_SurfaceSealedChamber::
# 17 "data/maps/Underwater_SealedChamber/scripts.pory"
	setdivewarp MAP_SEALED_CHAMBER_OUTER_ROOM, 10, 19
# 18 "data/maps/Underwater_SealedChamber/scripts.pory"
	end
# 19 "data/maps/Underwater_SealedChamber/scripts.pory"

# 20 "data/maps/Underwater_SealedChamber/scripts.pory"
Underwater_SealedChamber_EventScript_Braille::
# 21 "data/maps/Underwater_SealedChamber/scripts.pory"
	lockall
# 22 "data/maps/Underwater_SealedChamber/scripts.pory"
	braillemsgbox Underwater_SealedChamber_Braille_GoUpHere
# 23 "data/maps/Underwater_SealedChamber/scripts.pory"
	releaseall
# 24 "data/maps/Underwater_SealedChamber/scripts.pory"
	end
