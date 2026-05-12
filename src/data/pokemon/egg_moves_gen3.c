#include "global.h"
#include "pokemon.h"
#include "constants/species.h"

#include "egg_moves_gen3.h"

const u16 *const gEggMoves_Gen3[NUM_SPECIES] = {
#if P_FAMILY_BULBASAUR
    [SPECIES_BULBASAUR] = sBulbasaurEggMoveLearnset_Gen3,
#endif // P_FAMILY_BULBASAUR
#if P_FAMILY_CHARMANDER
    [SPECIES_CHARMANDER] = sCharmanderEggMoveLearnset_Gen3,
#endif // P_FAMILY_CHARMANDER
#if P_FAMILY_SQUIRTLE
    [SPECIES_SQUIRTLE] = sSquirtleEggMoveLearnset_Gen3,
#endif // P_FAMILY_SQUIRTLE
#if P_FAMILY_PIDGEY
    [SPECIES_PIDGEY] = sPidgeyEggMoveLearnset_Gen3,
#endif // P_FAMILY_PIDGEY
#if P_FAMILY_RATTATA
    [SPECIES_RATTATA] = sRattataEggMoveLearnset_Gen3,
#endif // P_FAMILY_RATTATA
#if P_FAMILY_SPEAROW
    [SPECIES_SPEAROW] = sSpearowEggMoveLearnset_Gen3,
#endif // P_FAMILY_SPEAROW
#if P_FAMILY_EKANS
    [SPECIES_EKANS] = sEkansEggMoveLearnset_Gen3,
#endif // P_FAMILY_EKANS
#if P_FAMILY_SANDSHREW
    [SPECIES_SANDSHREW] = sSandshrewEggMoveLearnset_Gen3,
#endif // P_FAMILY_SANDSHREW
#if P_FAMILY_NIDORAN
    [SPECIES_NIDORAN_F] = sNidoranFEggMoveLearnset_Gen3,
    [SPECIES_NIDORAN_M] = sNidoranMEggMoveLearnset_Gen3,
#endif // P_FAMILY_NIDORAN
#if P_FAMILY_VULPIX
    [SPECIES_VULPIX] = sVulpixEggMoveLearnset_Gen3,
#endif // P_FAMILY_VULPIX
#if P_FAMILY_ZUBAT
    [SPECIES_ZUBAT] = sZubatEggMoveLearnset_Gen3,
#endif // P_FAMILY_ZUBAT
#if P_FAMILY_ODDISH
    [SPECIES_ODDISH] = sOddishEggMoveLearnset_Gen3,
#endif // P_FAMILY_ODDISH
#if P_FAMILY_PARAS
    [SPECIES_PARAS] = sParasEggMoveLearnset_Gen3,
#endif // P_FAMILY_PARAS
#if P_FAMILY_VENONAT
    [SPECIES_VENONAT] = sVenonatEggMoveLearnset_Gen3,
#endif // P_FAMILY_VENONAT
#if P_FAMILY_DIGLETT
    [SPECIES_DIGLETT] = sDiglettEggMoveLearnset_Gen3,
#endif // P_FAMILY_DIGLETT
#if P_FAMILY_MEOWTH
    [SPECIES_MEOWTH] = sMeowthEggMoveLearnset_Gen3,
#endif // P_FAMILY_MEOWTH
#if P_FAMILY_PSYDUCK
    [SPECIES_PSYDUCK] = sPsyduckEggMoveLearnset_Gen3,
#endif // P_FAMILY_PSYDUCK
#if P_FAMILY_MANKEY
    [SPECIES_MANKEY] = sMankeyEggMoveLearnset_Gen3,
#endif // P_FAMILY_MANKEY
#if P_FAMILY_GROWLITHE
    [SPECIES_GROWLITHE] = sGrowlitheEggMoveLearnset_Gen3,
#endif // P_FAMILY_GROWLITHE
#if P_FAMILY_POLIWAG
    [SPECIES_POLIWAG] = sPoliwagEggMoveLearnset_Gen3,
#endif // P_FAMILY_POLIWAG
#if P_FAMILY_ABRA
    [SPECIES_ABRA] = sAbraEggMoveLearnset_Gen3,
#endif // P_FAMILY_ABRA
#if P_FAMILY_MACHOP
    [SPECIES_MACHOP] = sMachopEggMoveLearnset_Gen3,
#endif // P_FAMILY_MACHOP
#if P_FAMILY_BELLSPROUT
    [SPECIES_BELLSPROUT] = sBellsproutEggMoveLearnset_Gen3,
#endif // P_FAMILY_BELLSPROUT
#if P_FAMILY_TENTACOOL
    [SPECIES_TENTACOOL] = sTentacoolEggMoveLearnset_Gen3,
#endif // P_FAMILY_TENTACOOL
#if P_FAMILY_GEODUDE
    [SPECIES_GEODUDE] = sGeodudeEggMoveLearnset_Gen3,
#endif // P_FAMILY_GEODUDE
#if P_FAMILY_PONYTA
    [SPECIES_PONYTA] = sPonytaEggMoveLearnset_Gen3,
#endif // P_FAMILY_PONYTA
#if P_FAMILY_SLOWPOKE
    [SPECIES_SLOWPOKE] = sSlowpokeEggMoveLearnset_Gen3,
#endif // P_FAMILY_SLOWPOKE
#if P_FAMILY_FARFETCHD
    [SPECIES_FARFETCHD] = sFarfetchdEggMoveLearnset_Gen3,
#endif // P_FAMILY_FARFETCHD
#if P_FAMILY_DODUO
    [SPECIES_DODUO] = sDoduoEggMoveLearnset_Gen3,
#endif // P_FAMILY_DODUO
#if P_FAMILY_SEEL
    [SPECIES_SEEL] = sSeelEggMoveLearnset_Gen3,
#endif // P_FAMILY_SEEL
#if P_FAMILY_GRIMER
    [SPECIES_GRIMER] = sGrimerEggMoveLearnset_Gen3,
#endif // P_FAMILY_GRIMER
#if P_FAMILY_SHELLDER
    [SPECIES_SHELLDER] = sShellderEggMoveLearnset_Gen3,
#endif // P_FAMILY_SHELLDER
#if P_FAMILY_GASTLY
    [SPECIES_GASTLY] = sGastlyEggMoveLearnset_Gen3,
#endif // P_FAMILY_GASTLY
#if P_FAMILY_ONIX
    [SPECIES_ONIX] = sOnixEggMoveLearnset_Gen3,
#endif // P_FAMILY_ONIX
#if P_FAMILY_DROWZEE
    [SPECIES_DROWZEE] = sDrowzeeEggMoveLearnset_Gen3,
#endif // P_FAMILY_DROWZEE
#if P_FAMILY_KRABBY
    [SPECIES_KRABBY] = sKrabbyEggMoveLearnset_Gen3,
#endif // P_FAMILY_KRABBY
#if P_FAMILY_EXEGGCUTE
    [SPECIES_EXEGGCUTE] = sExeggcuteEggMoveLearnset_Gen3,
#endif // P_FAMILY_EXEGGCUTE
#if P_FAMILY_CUBONE
    [SPECIES_CUBONE] = sCuboneEggMoveLearnset_Gen3,
#endif // P_FAMILY_CUBONE
#if P_FAMILY_LICKITUNG
    [SPECIES_LICKITUNG] = sLickitungEggMoveLearnset_Gen3,
#endif // P_FAMILY_LICKITUNG
#if P_FAMILY_KOFFING
    [SPECIES_KOFFING] = sKoffingEggMoveLearnset_Gen3,
#endif // P_FAMILY_KOFFING
#if P_FAMILY_RHYHORN
    [SPECIES_RHYHORN] = sRhyhornEggMoveLearnset_Gen3,
#endif // P_FAMILY_RHYHORN
#if P_FAMILY_CHANSEY
    [SPECIES_CHANSEY] = sChanseyEggMoveLearnset_Gen3,
#endif // P_FAMILY_CHANSEY
#if P_FAMILY_TANGELA
    [SPECIES_TANGELA] = sTangelaEggMoveLearnset_Gen3,
#endif // P_FAMILY_TANGELA
#if P_FAMILY_KANGASKHAN
    [SPECIES_KANGASKHAN] = sKangaskhanEggMoveLearnset_Gen3,
#endif // P_FAMILY_KANGASKHAN
#if P_FAMILY_HORSEA
    [SPECIES_HORSEA] = sHorseaEggMoveLearnset_Gen3,
#endif // P_FAMILY_HORSEA
#if P_FAMILY_GOLDEEN
    [SPECIES_GOLDEEN] = sGoldeenEggMoveLearnset_Gen3,
#endif // P_FAMILY_GOLDEEN
#if P_FAMILY_MR_MIME
    [SPECIES_MR_MIME] = sMrMimeEggMoveLearnset_Gen3,
#endif // P_FAMILY_MR_MIME
#if P_FAMILY_SCYTHER
    [SPECIES_SCYTHER] = sScytherEggMoveLearnset_Gen3,
#endif // P_FAMILY_SCYTHER
#if P_FAMILY_PINSIR
    [SPECIES_PINSIR] = sPinsirEggMoveLearnset_Gen3,
#endif // P_FAMILY_PINSIR
#if P_FAMILY_LAPRAS
    [SPECIES_LAPRAS] = sLaprasEggMoveLearnset_Gen3,
#endif // P_FAMILY_LAPRAS
#if P_FAMILY_EEVEE
    [SPECIES_EEVEE] = sEeveeEggMoveLearnset_Gen3,
#endif // P_FAMILY_EEVEE
#if P_FAMILY_OMANYTE
    [SPECIES_OMANYTE] = sOmanyteEggMoveLearnset_Gen3,
#endif // P_FAMILY_OMANYTE
#if P_FAMILY_KABUTO
    [SPECIES_KABUTO] = sKabutoEggMoveLearnset_Gen3,
#endif // P_FAMILY_KABUTO
#if P_FAMILY_AERODACTYL
    [SPECIES_AERODACTYL] = sAerodactylEggMoveLearnset_Gen3,
#endif // P_FAMILY_AERODACTYL
#if P_FAMILY_SNORLAX
    [SPECIES_SNORLAX] = sSnorlaxEggMoveLearnset_Gen3,
#endif // P_FAMILY_SNORLAX
#if P_FAMILY_DRATINI
    [SPECIES_DRATINI] = sDratiniEggMoveLearnset_Gen3,
#endif // P_FAMILY_DRATINI
#if P_FAMILY_CHIKORITA
    [SPECIES_CHIKORITA] = sChikoritaEggMoveLearnset_Gen3,
#endif // P_FAMILY_CHIKORITA
#if P_FAMILY_CYNDAQUIL
    [SPECIES_CYNDAQUIL] = sCyndaquilEggMoveLearnset_Gen3,
#endif // P_FAMILY_CYNDAQUIL
#if P_FAMILY_TOTODILE
    [SPECIES_TOTODILE] = sTotodileEggMoveLearnset_Gen3,
#endif // P_FAMILY_TOTODILE
#if P_FAMILY_SENTRET
    [SPECIES_SENTRET] = sSentretEggMoveLearnset_Gen3,
#endif // P_FAMILY_SENTRET
#if P_FAMILY_HOOTHOOT
    [SPECIES_HOOTHOOT] = sHoothootEggMoveLearnset_Gen3,
#endif // P_FAMILY_HOOTHOOT
#if P_FAMILY_LEDYBA
    [SPECIES_LEDYBA] = sLedybaEggMoveLearnset_Gen3,
#endif // P_FAMILY_LEDYBA
#if P_FAMILY_SPINARAK
    [SPECIES_SPINARAK] = sSpinarakEggMoveLearnset_Gen3,
#endif // P_FAMILY_SPINARAK
#if P_FAMILY_CHINCHOU
    [SPECIES_CHINCHOU] = sChinchouEggMoveLearnset_Gen3,
#endif // P_FAMILY_CHINCHOU
#if P_FAMILY_PIKACHU
    [SPECIES_PICHU] = sPichuEggMoveLearnset_Gen3,
#endif // P_FAMILY_PIKACHU
#if P_FAMILY_CLEFAIRY
    [SPECIES_CLEFFA] = sCleffaEggMoveLearnset_Gen3,
#endif // P_FAMILY_CLEFAIRY
#if P_FAMILY_JIGGLYPUFF
    [SPECIES_IGGLYBUFF] = sIgglybuffEggMoveLearnset_Gen3,
#endif // P_FAMILY_JIGGLYPUFF
#if P_FAMILY_TOGEPI
    [SPECIES_TOGEPI] = sTogepiEggMoveLearnset_Gen3,
#endif // P_FAMILY_TOGEPI
#if P_FAMILY_NATU
    [SPECIES_NATU] = sNatuEggMoveLearnset_Gen3,
#endif // P_FAMILY_NATU
#if P_FAMILY_MAREEP
    [SPECIES_MAREEP] = sMareepEggMoveLearnset_Gen3,
#endif // P_FAMILY_MAREEP
#if P_FAMILY_MARILL
    [SPECIES_MARILL] = sMarillEggMoveLearnset_Gen3,
#endif // P_FAMILY_MARILL
#if P_FAMILY_SUDOWOODO
    [SPECIES_SUDOWOODO] = sSudowoodoEggMoveLearnset_Gen3,
#endif // P_FAMILY_SUDOWOODO
#if P_FAMILY_HOPPIP
    [SPECIES_HOPPIP] = sHoppipEggMoveLearnset_Gen3,
#endif // P_FAMILY_HOPPIP
#if P_FAMILY_AIPOM
    [SPECIES_AIPOM] = sAipomEggMoveLearnset_Gen3,
#endif // P_FAMILY_AIPOM
#if P_FAMILY_SUNKERN
    [SPECIES_SUNKERN] = sSunkernEggMoveLearnset_Gen3,
#endif // P_FAMILY_SUNKERN
#if P_FAMILY_YANMA
    [SPECIES_YANMA] = sYanmaEggMoveLearnset_Gen3,
#endif // P_FAMILY_YANMA
#if P_FAMILY_WOOPER
    [SPECIES_WOOPER] = sWooperEggMoveLearnset_Gen3,
#endif // P_FAMILY_WOOPER
#if P_FAMILY_MURKROW
    [SPECIES_MURKROW] = sMurkrowEggMoveLearnset_Gen3,
#endif // P_FAMILY_MURKROW
#if P_FAMILY_MISDREAVUS
    [SPECIES_MISDREAVUS] = sMisdreavusEggMoveLearnset_Gen3,
#endif // P_FAMILY_MISDREAVUS
#if P_FAMILY_GIRAFARIG
    [SPECIES_GIRAFARIG] = sGirafarigEggMoveLearnset_Gen3,
#endif // P_FAMILY_GIRAFARIG
#if P_FAMILY_PINECO
    [SPECIES_PINECO] = sPinecoEggMoveLearnset_Gen3,
#endif // P_FAMILY_PINECO
#if P_FAMILY_DUNSPARCE
    [SPECIES_DUNSPARCE] = sDunsparceEggMoveLearnset_Gen3,
#endif // P_FAMILY_DUNSPARCE
#if P_FAMILY_GLIGAR
    [SPECIES_GLIGAR] = sGligarEggMoveLearnset_Gen3,
#endif // P_FAMILY_GLIGAR
#if P_FAMILY_SNUBBULL
    [SPECIES_SNUBBULL] = sSnubbullEggMoveLearnset_Gen3,
#endif // P_FAMILY_SNUBBULL
#if P_FAMILY_QWILFISH
    [SPECIES_QWILFISH] = sQwilfishEggMoveLearnset_Gen3,
#endif // P_FAMILY_QWILFISH
#if P_FAMILY_SHUCKLE
    [SPECIES_SHUCKLE] = sShuckleEggMoveLearnset_Gen3,
#endif // P_FAMILY_SHUCKLE
#if P_FAMILY_HERACROSS
    [SPECIES_HERACROSS] = sHeracrossEggMoveLearnset_Gen3,
#endif // P_FAMILY_HERACROSS
#if P_FAMILY_SNEASEL
    [SPECIES_SNEASEL] = sSneaselEggMoveLearnset_Gen3,
#endif // P_FAMILY_SNEASEL
#if P_FAMILY_TEDDIURSA
    [SPECIES_TEDDIURSA] = sTeddiursaEggMoveLearnset_Gen3,
#endif // P_FAMILY_TEDDIURSA
#if P_FAMILY_SLUGMA
    [SPECIES_SLUGMA] = sSlugmaEggMoveLearnset_Gen3,
#endif // P_FAMILY_SLUGMA
#if P_FAMILY_SWINUB
    [SPECIES_SWINUB] = sSwinubEggMoveLearnset_Gen3,
#endif // P_FAMILY_SWINUB
#if P_FAMILY_CORSOLA
    [SPECIES_CORSOLA] = sCorsolaEggMoveLearnset_Gen3,
#endif // P_FAMILY_CORSOLA
#if P_FAMILY_REMORAID
    [SPECIES_REMORAID] = sRemoraidEggMoveLearnset_Gen3,
#endif // P_FAMILY_REMORAID
#if P_FAMILY_DELIBIRD
    [SPECIES_DELIBIRD] = sDelibirdEggMoveLearnset_Gen3,
#endif // P_FAMILY_DELIBIRD
#if P_FAMILY_MANTINE
    [SPECIES_MANTINE] = sMantineEggMoveLearnset_Gen3,
#endif // P_FAMILY_MANTINE
#if P_FAMILY_SKARMORY
    [SPECIES_SKARMORY] = sSkarmoryEggMoveLearnset_Gen3,
#endif // P_FAMILY_SKARMORY
#if P_FAMILY_HOUNDOUR
    [SPECIES_HOUNDOUR] = sHoundourEggMoveLearnset_Gen3,
#endif // P_FAMILY_HOUNDOUR
#if P_FAMILY_PHANPY
    [SPECIES_PHANPY] = sPhanpyEggMoveLearnset_Gen3,
#endif // P_FAMILY_PHANPY
#if P_FAMILY_STANTLER
    [SPECIES_STANTLER] = sStantlerEggMoveLearnset_Gen3,
#endif // P_FAMILY_STANTLER
#if P_FAMILY_HITMONS
    [SPECIES_TYROGUE] = sTyrogueEggMoveLearnset_Gen3,
#endif // P_FAMILY_HITMONS
#if P_FAMILY_JYNX
    [SPECIES_SMOOCHUM] = sSmoochumEggMoveLearnset_Gen3,
#endif // P_FAMILY_JYNX
#if P_FAMILY_ELECTABUZZ
    [SPECIES_ELEKID] = sElekidEggMoveLearnset_Gen3,
#endif // P_FAMILY_ELECTABUZZ
#if P_FAMILY_MAGMAR
    [SPECIES_MAGBY] = sMagbyEggMoveLearnset_Gen3,
#endif // P_FAMILY_MAGMAR
#if P_FAMILY_MILTANK
    [SPECIES_MILTANK] = sMiltankEggMoveLearnset_Gen3,
#endif // P_FAMILY_MILTANK
#if P_FAMILY_LARVITAR
    [SPECIES_LARVITAR] = sLarvitarEggMoveLearnset_Gen3,
#endif // P_FAMILY_LARVITAR
#if P_FAMILY_TREECKO
    [SPECIES_TREECKO] = sTreeckoEggMoveLearnset_Gen3,
#endif // P_FAMILY_TREECKO
#if P_FAMILY_TORCHIC
    [SPECIES_TORCHIC] = sTorchicEggMoveLearnset_Gen3,
#endif // P_FAMILY_TORCHIC
#if P_FAMILY_MUDKIP
    [SPECIES_MUDKIP] = sMudkipEggMoveLearnset_Gen3,
#endif // P_FAMILY_MUDKIP
#if P_FAMILY_POOCHYENA
    [SPECIES_POOCHYENA] = sPoochyenaEggMoveLearnset_Gen3,
#endif // P_FAMILY_POOCHYENA
#if P_FAMILY_ZIGZAGOON
    [SPECIES_ZIGZAGOON] = sZigzagoonEggMoveLearnset_Gen3,
#endif // P_FAMILY_ZIGZAGOON
#if P_FAMILY_LOTAD
    [SPECIES_LOTAD] = sLotadEggMoveLearnset_Gen3,
#endif // P_FAMILY_LOTAD
#if P_FAMILY_SEEDOT
    [SPECIES_SEEDOT] = sSeedotEggMoveLearnset_Gen3,
#endif // P_FAMILY_SEEDOT
#if P_FAMILY_NINCADA
    [SPECIES_NINCADA] = sNincadaEggMoveLearnset_Gen3,
#endif // P_FAMILY_NINCADA
#if P_FAMILY_TAILLOW
    [SPECIES_TAILLOW] = sTaillowEggMoveLearnset_Gen3,
#endif // P_FAMILY_TAILLOW
#if P_FAMILY_SHROOMISH
    [SPECIES_SHROOMISH] = sShroomishEggMoveLearnset_Gen3,
#endif // P_FAMILY_SHROOMISH
#if P_FAMILY_SPINDA
    [SPECIES_SPINDA] = sSpindaEggMoveLearnset_Gen3,
#endif // P_FAMILY_SPINDA
#if P_FAMILY_WINGULL
    [SPECIES_WINGULL] = sWingullEggMoveLearnset_Gen3,
#endif // P_FAMILY_WINGULL
#if P_FAMILY_SURSKIT
    [SPECIES_SURSKIT] = sSurskitEggMoveLearnset_Gen3,
#endif // P_FAMILY_SURSKIT
#if P_FAMILY_WAILMER
    [SPECIES_WAILMER] = sWailmerEggMoveLearnset_Gen3,
#endif // P_FAMILY_WAILMER
#if P_FAMILY_SKITTY
    [SPECIES_SKITTY] = sSkittyEggMoveLearnset_Gen3,
#endif // P_FAMILY_SKITTY
#if P_FAMILY_KECLEON
    [SPECIES_KECLEON] = sKecleonEggMoveLearnset_Gen3,
#endif // P_FAMILY_KECLEON
#if P_FAMILY_NOSEPASS
    [SPECIES_NOSEPASS] = sNosepassEggMoveLearnset_Gen3,
#endif // P_FAMILY_NOSEPASS
#if P_FAMILY_TORKOAL
    [SPECIES_TORKOAL] = sTorkoalEggMoveLearnset_Gen3,
#endif // P_FAMILY_TORKOAL
#if P_FAMILY_SABLEYE
    [SPECIES_SABLEYE] = sSableyeEggMoveLearnset_Gen3,
#endif // P_FAMILY_SABLEYE
#if P_FAMILY_BARBOACH
    [SPECIES_BARBOACH] = sBarboachEggMoveLearnset_Gen3,
#endif // P_FAMILY_BARBOACH
#if P_FAMILY_LUVDISC
    [SPECIES_LUVDISC] = sLuvdiscEggMoveLearnset_Gen3,
#endif // P_FAMILY_LUVDISC
#if P_FAMILY_CORPHISH
    [SPECIES_CORPHISH] = sCorphishEggMoveLearnset_Gen3,
#endif // P_FAMILY_CORPHISH
#if P_FAMILY_FEEBAS
    [SPECIES_FEEBAS] = sFeebasEggMoveLearnset_Gen3,
#endif // P_FAMILY_FEEBAS
#if P_FAMILY_CARVANHA
    [SPECIES_CARVANHA] = sCarvanhaEggMoveLearnset_Gen3,
#endif // P_FAMILY_CARVANHA
#if P_FAMILY_TRAPINCH
    [SPECIES_TRAPINCH] = sTrapinchEggMoveLearnset_Gen3,
#endif // P_FAMILY_TRAPINCH
#if P_FAMILY_MAKUHITA
    [SPECIES_MAKUHITA] = sMakuhitaEggMoveLearnset_Gen3,
#endif // P_FAMILY_MAKUHITA
#if P_FAMILY_ELECTRIKE
    [SPECIES_ELECTRIKE] = sElectrikeEggMoveLearnset_Gen3,
#endif // P_FAMILY_ELECTRIKE
#if P_FAMILY_NUMEL
    [SPECIES_NUMEL] = sNumelEggMoveLearnset_Gen3,
#endif // P_FAMILY_NUMEL
#if P_FAMILY_SPHEAL
    [SPECIES_SPHEAL] = sSphealEggMoveLearnset_Gen3,
#endif // P_FAMILY_SPHEAL
#if P_FAMILY_CACNEA
    [SPECIES_CACNEA] = sCacneaEggMoveLearnset_Gen3,
#endif // P_FAMILY_CACNEA
#if P_FAMILY_SNORUNT
    [SPECIES_SNORUNT] = sSnoruntEggMoveLearnset_Gen3,
#endif // P_FAMILY_SNORUNT
#if P_FAMILY_MARILL
    [SPECIES_AZURILL] = sAzurillEggMoveLearnset_Gen3,
#endif // P_FAMILY_MARILL
#if P_FAMILY_SPOINK
    [SPECIES_SPOINK] = sSpoinkEggMoveLearnset_Gen3,
#endif // P_FAMILY_SPOINK
#if P_FAMILY_PLUSLE
    [SPECIES_PLUSLE] = sPlusleEggMoveLearnset_Gen3,
#endif // P_FAMILY_PLUSLE
#if P_FAMILY_MINUN
    [SPECIES_MINUN] = sMinunEggMoveLearnset_Gen3,
#endif // P_FAMILY_MINUN
#if P_FAMILY_MAWILE
    [SPECIES_MAWILE] = sMawileEggMoveLearnset_Gen3,
#endif // P_FAMILY_MAWILE
#if P_FAMILY_MEDITITE
    [SPECIES_MEDITITE] = sMedititeEggMoveLearnset_Gen3,
#endif // P_FAMILY_MEDITITE
#if P_FAMILY_SWABLU
    [SPECIES_SWABLU] = sSwabluEggMoveLearnset_Gen3,
#endif // P_FAMILY_SWABLU
#if P_FAMILY_DUSKULL
    [SPECIES_DUSKULL] = sDuskullEggMoveLearnset_Gen3,
#endif // P_FAMILY_DUSKULL
#if P_FAMILY_ROSELIA
    [SPECIES_ROSELIA] = sRoseliaEggMoveLearnset_Gen3,
#endif // P_FAMILY_ROSELIA
#if P_FAMILY_SLAKOTH
    [SPECIES_SLAKOTH] = sSlakothEggMoveLearnset_Gen3,
#endif // P_FAMILY_SLAKOTH
#if P_FAMILY_GULPIN
    [SPECIES_GULPIN] = sGulpinEggMoveLearnset_Gen3,
#endif // P_FAMILY_GULPIN
#if P_FAMILY_TROPIUS
    [SPECIES_TROPIUS] = sTropiusEggMoveLearnset_Gen3,
#endif // P_FAMILY_TROPIUS
#if P_FAMILY_WHISMUR
    [SPECIES_WHISMUR] = sWhismurEggMoveLearnset_Gen3,
#endif // P_FAMILY_WHISMUR
#if P_FAMILY_CLAMPERL
    [SPECIES_CLAMPERL] = sClamperlEggMoveLearnset_Gen3,
#endif // P_FAMILY_CLAMPERL
#if P_FAMILY_ABSOL
    [SPECIES_ABSOL] = sAbsolEggMoveLearnset_Gen3,
#endif // P_FAMILY_ABSOL
#if P_FAMILY_SHUPPET
    [SPECIES_SHUPPET] = sShuppetEggMoveLearnset_Gen3,
#endif // P_FAMILY_SHUPPET
#if P_FAMILY_SEVIPER
    [SPECIES_SEVIPER] = sSeviperEggMoveLearnset_Gen3,
#endif // P_FAMILY_SEVIPER
#if P_FAMILY_ZANGOOSE
    [SPECIES_ZANGOOSE] = sZangooseEggMoveLearnset_Gen3,
#endif // P_FAMILY_ZANGOOSE
#if P_FAMILY_RELICANTH
    [SPECIES_RELICANTH] = sRelicanthEggMoveLearnset_Gen3,
#endif // P_FAMILY_RELICANTH
#if P_FAMILY_ARON
    [SPECIES_ARON] = sAronEggMoveLearnset_Gen3,
#endif // P_FAMILY_ARON
#if P_FAMILY_CASTFORM
    [SPECIES_CASTFORM] = sCastformEggMoveLearnset_Gen3,
#endif // P_FAMILY_CASTFORM
#if P_FAMILY_VOLBEAT_ILLUMISE
    [SPECIES_VOLBEAT] = sVolbeatEggMoveLearnset_Gen3,
    [SPECIES_ILLUMISE] = sIllumiseEggMoveLearnset_Gen3,
#endif // P_FAMILY_VOLBEAT_ILLUMISE
#if P_FAMILY_LILEEP
    [SPECIES_LILEEP] = sLileepEggMoveLearnset_Gen3,
#endif // P_FAMILY_LILEEP
#if P_FAMILY_ANORITH
    [SPECIES_ANORITH] = sAnorithEggMoveLearnset_Gen3,
#endif // P_FAMILY_ANORITH
#if P_FAMILY_RALTS
    [SPECIES_RALTS] = sRaltsEggMoveLearnset_Gen3,
#endif // P_FAMILY_RALTS
#if P_FAMILY_BAGON
    [SPECIES_BAGON] = sBagonEggMoveLearnset_Gen3,
#endif // P_FAMILY_BAGON
#if P_FAMILY_CHIMECHO
    [SPECIES_CHIMECHO] = sChimechoEggMoveLearnset_Gen3,
    [SPECIES_CHINGLING] = sChinglingEggMoveLearnset_Gen3,
#endif // P_FAMILY_CHIMECHO
#if P_FAMILY_ROSELIA
    [SPECIES_BUDEW] = sBudewEggMoveLearnset_Gen3,
#endif // P_FAMILY_ROSELIA
#if P_FAMILY_CHANSEY
    [SPECIES_HAPPINY] = sHappinyEggMoveLearnset_Gen3,
#endif // P_FAMILY_CHANSEY
#if P_FAMILY_MR_MIME
    [SPECIES_MIME_JR] = sMimeJrEggMoveLearnset_Gen3,
#endif // P_FAMILY_MR_MIME
#if P_FAMILY_SNORLAX
    [SPECIES_MUNCHLAX] = sMunchlaxEggMoveLearnset_Gen3,
#endif // P_FAMILY_SNORLAX
#if P_FAMILY_SUDOWOODO
    [SPECIES_BONSLY] = sBonslyEggMoveLearnset_Gen3,
#endif // P_FAMILY_SUDOWOODO
#if P_FAMILY_MANTINE
    [SPECIES_MANTYKE] = sMantykeEggMoveLearnset_Gen3,
#endif // P_FAMILY_MANTINE
};

