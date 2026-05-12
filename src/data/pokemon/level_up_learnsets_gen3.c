#include "global.h"
#include "pokemon.h"
#include "constants/species.h"

#include "level_up_learnsets/gen_3.h"

const struct LevelUpMove *const gLevelUpLearnsets_Gen3[NUM_SPECIES] = {
#if P_FAMILY_BULBASAUR
    [SPECIES_BULBASAUR] = sBulbasaurLevelUpLearnset,
    [SPECIES_IVYSAUR] = sIvysaurLevelUpLearnset,
    [SPECIES_VENUSAUR] = sVenusaurLevelUpLearnset,
    [SPECIES_VENUSAUR_MEGA] = sVenusaurLevelUpLearnset,
    [SPECIES_VENUSAUR_GMAX] = sVenusaurLevelUpLearnset,
#endif // P_FAMILY_BULBASAUR
#if P_FAMILY_CHARMANDER
    [SPECIES_CHARMANDER] = sCharmanderLevelUpLearnset,
    [SPECIES_CHARMELEON] = sCharmeleonLevelUpLearnset,
    [SPECIES_CHARIZARD] = sCharizardLevelUpLearnset,
    [SPECIES_CHARIZARD_MEGA_X] = sCharizardLevelUpLearnset,
    [SPECIES_CHARIZARD_MEGA_Y] = sCharizardLevelUpLearnset,
    [SPECIES_CHARIZARD_GMAX] = sCharizardLevelUpLearnset,
#endif // P_FAMILY_CHARMANDER
#if P_FAMILY_SQUIRTLE
    [SPECIES_SQUIRTLE] = sSquirtleLevelUpLearnset,
    [SPECIES_WARTORTLE] = sWartortleLevelUpLearnset,
    [SPECIES_BLASTOISE] = sBlastoiseLevelUpLearnset,
    [SPECIES_BLASTOISE_MEGA] = sBlastoiseLevelUpLearnset,
    [SPECIES_BLASTOISE_GMAX] = sBlastoiseLevelUpLearnset,
#endif // P_FAMILY_SQUIRTLE
#if P_FAMILY_CATERPIE
    [SPECIES_CATERPIE] = sCaterpieLevelUpLearnset,
    [SPECIES_METAPOD] = sMetapodLevelUpLearnset,
    [SPECIES_BUTTERFREE] = sButterfreeLevelUpLearnset,
    [SPECIES_BUTTERFREE_GMAX] = sButterfreeLevelUpLearnset,
#endif // P_FAMILY_CATERPIE
#if P_FAMILY_WEEDLE
    [SPECIES_WEEDLE] = sWeedleLevelUpLearnset,
    [SPECIES_KAKUNA] = sKakunaLevelUpLearnset,
    [SPECIES_BEEDRILL] = sBeedrillLevelUpLearnset,
    [SPECIES_BEEDRILL_MEGA] = sBeedrillLevelUpLearnset,
#endif // P_FAMILY_WEEDLE
#if P_FAMILY_PIDGEY
    [SPECIES_PIDGEY] = sPidgeyLevelUpLearnset,
    [SPECIES_PIDGEOTTO] = sPidgeottoLevelUpLearnset,
    [SPECIES_PIDGEOT] = sPidgeotLevelUpLearnset,
    [SPECIES_PIDGEOT_MEGA] = sPidgeotLevelUpLearnset,
#endif // P_FAMILY_PIDGEY
#if P_FAMILY_RATTATA
    [SPECIES_RATTATA] = sRattataLevelUpLearnset,
    [SPECIES_RATICATE] = sRaticateLevelUpLearnset,
    [SPECIES_RATTATA_ALOLA] = sRattataAlolaLevelUpLearnset,
    [SPECIES_RATICATE_ALOLA] = sRaticateAlolaLevelUpLearnset,
    [SPECIES_RATICATE_ALOLA_TOTEM] = sRaticateAlolaLevelUpLearnset,
#endif // P_FAMILY_RATTATA
#if P_FAMILY_SPEAROW
    [SPECIES_SPEAROW] = sSpearowLevelUpLearnset,
    [SPECIES_FEAROW] = sFearowLevelUpLearnset,
#endif // P_FAMILY_SPEAROW
#if P_FAMILY_EKANS
    [SPECIES_EKANS] = sEkansLevelUpLearnset,
    [SPECIES_ARBOK] = sArbokLevelUpLearnset,
#endif // P_FAMILY_EKANS
#if P_FAMILY_PIKACHU
    [SPECIES_PICHU] = sPichuLevelUpLearnset,
    [SPECIES_PICHU_SPIKY_EARED] = sPichuLevelUpLearnset,
    [SPECIES_PIKACHU] = sPikachuLevelUpLearnset,
    [SPECIES_PIKACHU_COSPLAY] = sPikachuLevelUpLearnset,
    [SPECIES_PIKACHU_ROCK_STAR] = sPikachuLevelUpLearnset,
    [SPECIES_PIKACHU_BELLE] = sPikachuLevelUpLearnset,
    [SPECIES_PIKACHU_POP_STAR] = sPikachuLevelUpLearnset,
    [SPECIES_PIKACHU_PHD] = sPikachuLevelUpLearnset,
    [SPECIES_PIKACHU_LIBRE] = sPikachuLevelUpLearnset,
    [SPECIES_PIKACHU_ORIGINAL] = sPikachuLevelUpLearnset,
    [SPECIES_PIKACHU_HOENN] = sPikachuLevelUpLearnset,
    [SPECIES_PIKACHU_SINNOH] = sPikachuLevelUpLearnset,
    [SPECIES_PIKACHU_UNOVA] = sPikachuLevelUpLearnset,
    [SPECIES_PIKACHU_KALOS] = sPikachuLevelUpLearnset,
    [SPECIES_PIKACHU_ALOLA] = sPikachuLevelUpLearnset,
    [SPECIES_PIKACHU_PARTNER] = sPikachuLevelUpLearnset,
    [SPECIES_PIKACHU_WORLD] = sPikachuLevelUpLearnset,
    [SPECIES_PIKACHU_GMAX] = sPikachuLevelUpLearnset,
    [SPECIES_PIKACHU_STARTER] = sPikachuLevelUpLearnset,
    [SPECIES_RAICHU] = sRaichuLevelUpLearnset,
    [SPECIES_RAICHU_ALOLA] = sRaichuAlolaLevelUpLearnset,
    [SPECIES_RAICHU_MEGA_X] = sRaichuLevelUpLearnset,
    [SPECIES_RAICHU_MEGA_Y] = sRaichuLevelUpLearnset,
#endif // P_FAMILY_PIKACHU
#if P_FAMILY_SANDSHREW
    [SPECIES_SANDSHREW] = sSandshrewLevelUpLearnset,
    [SPECIES_SANDSLASH] = sSandslashLevelUpLearnset,
    [SPECIES_SANDSHREW_ALOLA] = sSandshrewAlolaLevelUpLearnset,
    [SPECIES_SANDSLASH_ALOLA] = sSandslashAlolaLevelUpLearnset,
#endif // P_FAMILY_SANDSHREW
#if P_FAMILY_NIDORAN
    [SPECIES_NIDORAN_F] = sNidoranFLevelUpLearnset,
    [SPECIES_NIDORINA] = sNidorinaLevelUpLearnset,
    [SPECIES_NIDOQUEEN] = sNidoqueenLevelUpLearnset,
    [SPECIES_NIDORAN_M] = sNidoranMLevelUpLearnset,
    [SPECIES_NIDORINO] = sNidorinoLevelUpLearnset,
    [SPECIES_NIDOKING] = sNidokingLevelUpLearnset,
#endif // P_FAMILY_NIDORAN
#if P_FAMILY_CLEFAIRY
    [SPECIES_CLEFFA] = sCleffaLevelUpLearnset,
    [SPECIES_CLEFAIRY] = sClefairyLevelUpLearnset,
    [SPECIES_CLEFABLE] = sClefableLevelUpLearnset,
    [SPECIES_CLEFABLE_MEGA] = sClefableLevelUpLearnset,
#endif // P_FAMILY_CLEFAIRY
#if P_FAMILY_VULPIX
    [SPECIES_VULPIX] = sVulpixLevelUpLearnset,
    [SPECIES_NINETALES] = sNinetalesLevelUpLearnset,
    [SPECIES_VULPIX_ALOLA] = sVulpixAlolaLevelUpLearnset,
    [SPECIES_NINETALES_ALOLA] = sNinetalesAlolaLevelUpLearnset,
#endif // P_FAMILY_VULPIX
#if P_FAMILY_JIGGLYPUFF
    [SPECIES_IGGLYBUFF] = sIgglybuffLevelUpLearnset,
    [SPECIES_JIGGLYPUFF] = sJigglypuffLevelUpLearnset,
    [SPECIES_WIGGLYTUFF] = sWigglytuffLevelUpLearnset,
#endif // P_FAMILY_JIGGLYPUFF
#if P_FAMILY_ZUBAT
    [SPECIES_ZUBAT] = sZubatLevelUpLearnset,
    [SPECIES_GOLBAT] = sGolbatLevelUpLearnset,
    [SPECIES_CROBAT] = sCrobatLevelUpLearnset,
#endif // P_FAMILY_ZUBAT
#if P_FAMILY_ODDISH
    [SPECIES_ODDISH] = sOddishLevelUpLearnset,
    [SPECIES_GLOOM] = sGloomLevelUpLearnset,
    [SPECIES_VILEPLUME] = sVileplumeLevelUpLearnset,
    [SPECIES_BELLOSSOM] = sBellossomLevelUpLearnset,
#endif // P_FAMILY_ODDISH
#if P_FAMILY_PARAS
    [SPECIES_PARAS] = sParasLevelUpLearnset,
    [SPECIES_PARASECT] = sParasectLevelUpLearnset,
#endif // P_FAMILY_PARAS
#if P_FAMILY_VENONAT
    [SPECIES_VENONAT] = sVenonatLevelUpLearnset,
    [SPECIES_VENOMOTH] = sVenomothLevelUpLearnset,
#endif // P_FAMILY_VENONAT
#if P_FAMILY_DIGLETT
    [SPECIES_DIGLETT] = sDiglettLevelUpLearnset,
    [SPECIES_DUGTRIO] = sDugtrioLevelUpLearnset,
    [SPECIES_DIGLETT_ALOLA] = sDiglettAlolaLevelUpLearnset,
    [SPECIES_DUGTRIO_ALOLA] = sDugtrioAlolaLevelUpLearnset,
#endif // P_FAMILY_DIGLETT
#if P_FAMILY_MEOWTH
    [SPECIES_MEOWTH] = sMeowthLevelUpLearnset,
    [SPECIES_PERSIAN] = sPersianLevelUpLearnset,
    [SPECIES_MEOWTH_ALOLA] = sMeowthAlolaLevelUpLearnset,
    [SPECIES_PERSIAN_ALOLA] = sPersianAlolaLevelUpLearnset,
    [SPECIES_MEOWTH_GALAR] = sMeowthGalarLevelUpLearnset,
    [SPECIES_PERRSERKER] = sPerrserkerLevelUpLearnset,
    [SPECIES_MEOWTH_GMAX] = sMeowthLevelUpLearnset,
#endif // P_FAMILY_MEOWTH
#if P_FAMILY_PSYDUCK
    [SPECIES_PSYDUCK] = sPsyduckLevelUpLearnset,
    [SPECIES_GOLDUCK] = sGolduckLevelUpLearnset,
#endif // P_FAMILY_PSYDUCK
#if P_FAMILY_MANKEY
    [SPECIES_MANKEY] = sMankeyLevelUpLearnset,
    [SPECIES_PRIMEAPE] = sPrimeapeLevelUpLearnset,
    [SPECIES_ANNIHILAPE] = sAnnihilapeLevelUpLearnset,
#endif // P_FAMILY_MANKEY
#if P_FAMILY_GROWLITHE
    [SPECIES_GROWLITHE] = sGrowlitheLevelUpLearnset,
    [SPECIES_ARCANINE] = sArcanineLevelUpLearnset,
    [SPECIES_GROWLITHE_HISUI] = sGrowlitheHisuiLevelUpLearnset,
    [SPECIES_ARCANINE_HISUI] = sArcanineHisuiLevelUpLearnset,
#endif // P_FAMILY_GROWLITHE
#if P_FAMILY_POLIWAG
    [SPECIES_POLIWAG] = sPoliwagLevelUpLearnset,
    [SPECIES_POLIWHIRL] = sPoliwhirlLevelUpLearnset,
    [SPECIES_POLIWRATH] = sPoliwrathLevelUpLearnset,
    [SPECIES_POLITOED] = sPolitoedLevelUpLearnset,
#endif // P_FAMILY_POLIWAG
#if P_FAMILY_ABRA
    [SPECIES_ABRA] = sAbraLevelUpLearnset,
    [SPECIES_KADABRA] = sKadabraLevelUpLearnset,
    [SPECIES_ALAKAZAM] = sAlakazamLevelUpLearnset,
    [SPECIES_ALAKAZAM_MEGA] = sAlakazamLevelUpLearnset,
#endif // P_FAMILY_ABRA
#if P_FAMILY_MACHOP
    [SPECIES_MACHOP] = sMachopLevelUpLearnset,
    [SPECIES_MACHOKE] = sMachokeLevelUpLearnset,
    [SPECIES_MACHAMP] = sMachampLevelUpLearnset,
    [SPECIES_MACHAMP_GMAX] = sMachampLevelUpLearnset,
#endif // P_FAMILY_MACHOP
#if P_FAMILY_BELLSPROUT
    [SPECIES_BELLSPROUT] = sBellsproutLevelUpLearnset,
    [SPECIES_WEEPINBELL] = sWeepinbellLevelUpLearnset,
    [SPECIES_VICTREEBEL] = sVictreebelLevelUpLearnset,
    [SPECIES_VICTREEBEL_MEGA] = sVictreebelLevelUpLearnset,
#endif // P_FAMILY_BELLSPROUT
#if P_FAMILY_TENTACOOL
    [SPECIES_TENTACOOL] = sTentacoolLevelUpLearnset,
    [SPECIES_TENTACRUEL] = sTentacruelLevelUpLearnset,
#endif // P_FAMILY_TENTACOOL
#if P_FAMILY_GEODUDE
    [SPECIES_GEODUDE] = sGeodudeLevelUpLearnset,
    [SPECIES_GRAVELER] = sGravelerLevelUpLearnset,
    [SPECIES_GOLEM] = sGolemLevelUpLearnset,
    [SPECIES_GEODUDE_ALOLA] = sGeodudeAlolaLevelUpLearnset,
    [SPECIES_GRAVELER_ALOLA] = sGravelerAlolaLevelUpLearnset,
    [SPECIES_GOLEM_ALOLA] = sGolemAlolaLevelUpLearnset,
#endif // P_FAMILY_GEODUDE
#if P_FAMILY_PONYTA
    [SPECIES_PONYTA] = sPonytaLevelUpLearnset,
    [SPECIES_RAPIDASH] = sRapidashLevelUpLearnset,
    [SPECIES_PONYTA_GALAR] = sPonytaGalarLevelUpLearnset,
    [SPECIES_RAPIDASH_GALAR] = sRapidashGalarLevelUpLearnset,
#endif // P_FAMILY_PONYTA
#if P_FAMILY_SLOWPOKE
    [SPECIES_SLOWPOKE] = sSlowpokeLevelUpLearnset,
    [SPECIES_SLOWBRO] = sSlowbroLevelUpLearnset,
    [SPECIES_SLOWKING] = sSlowkingLevelUpLearnset,
    [SPECIES_SLOWBRO_MEGA] = sSlowbroLevelUpLearnset,
    [SPECIES_SLOWPOKE_GALAR] = sSlowpokeGalarLevelUpLearnset,
    [SPECIES_SLOWBRO_GALAR] = sSlowbroGalarLevelUpLearnset,
    [SPECIES_SLOWKING_GALAR] = sSlowkingGalarLevelUpLearnset,
#endif // P_FAMILY_SLOWPOKE
#if P_FAMILY_MAGNEMITE
    [SPECIES_MAGNEMITE] = sMagnemiteLevelUpLearnset,
    [SPECIES_MAGNETON] = sMagnetonLevelUpLearnset,
    [SPECIES_MAGNEZONE] = sMagnezoneLevelUpLearnset,
#endif // P_FAMILY_MAGNEMITE
#if P_FAMILY_FARFETCHD
    [SPECIES_FARFETCHD] = sFarfetchdLevelUpLearnset,
    [SPECIES_FARFETCHD_GALAR] = sFarfetchdGalarLevelUpLearnset,
    [SPECIES_SIRFETCHD] = sSirfetchdLevelUpLearnset,
#endif // P_FAMILY_FARFETCHD
#if P_FAMILY_DODUO
    [SPECIES_DODUO] = sDoduoLevelUpLearnset,
    [SPECIES_DODRIO] = sDodrioLevelUpLearnset,
#endif // P_FAMILY_DODUO
#if P_FAMILY_SEEL
    [SPECIES_SEEL] = sSeelLevelUpLearnset,
    [SPECIES_DEWGONG] = sDewgongLevelUpLearnset,
#endif // P_FAMILY_SEEL
#if P_FAMILY_GRIMER
    [SPECIES_GRIMER] = sGrimerLevelUpLearnset,
    [SPECIES_MUK] = sMukLevelUpLearnset,
    [SPECIES_GRIMER_ALOLA] = sGrimerAlolaLevelUpLearnset,
    [SPECIES_MUK_ALOLA] = sMukAlolaLevelUpLearnset,
#endif // P_FAMILY_GRIMER
#if P_FAMILY_SHELLDER
    [SPECIES_SHELLDER] = sShellderLevelUpLearnset,
    [SPECIES_CLOYSTER] = sCloysterLevelUpLearnset,
#endif // P_FAMILY_SHELLDER
#if P_FAMILY_GASTLY
    [SPECIES_GASTLY] = sGastlyLevelUpLearnset,
    [SPECIES_HAUNTER] = sHaunterLevelUpLearnset,
    [SPECIES_GENGAR] = sGengarLevelUpLearnset,
    [SPECIES_GENGAR_MEGA] = sGengarLevelUpLearnset,
    [SPECIES_GENGAR_GMAX] = sGengarLevelUpLearnset,
#endif // P_FAMILY_GASTLY
#if P_FAMILY_ONIX
    [SPECIES_ONIX] = sOnixLevelUpLearnset,
    [SPECIES_STEELIX] = sSteelixLevelUpLearnset,
    [SPECIES_STEELIX_MEGA] = sSteelixLevelUpLearnset,
#endif // P_FAMILY_ONIX
#if P_FAMILY_DROWZEE
    [SPECIES_DROWZEE] = sDrowzeeLevelUpLearnset,
    [SPECIES_HYPNO] = sHypnoLevelUpLearnset,
#endif // P_FAMILY_DROWZEE
#if P_FAMILY_KRABBY
    [SPECIES_KRABBY] = sKrabbyLevelUpLearnset,
    [SPECIES_KINGLER] = sKinglerLevelUpLearnset,
    [SPECIES_KINGLER_GMAX] = sKinglerLevelUpLearnset,
#endif // P_FAMILY_KRABBY
#if P_FAMILY_VOLTORB
    [SPECIES_VOLTORB] = sVoltorbLevelUpLearnset,
    [SPECIES_ELECTRODE] = sElectrodeLevelUpLearnset,
    [SPECIES_VOLTORB_HISUI] = sVoltorbHisuiLevelUpLearnset,
    [SPECIES_ELECTRODE_HISUI] = sElectrodeHisuiLevelUpLearnset,
#endif // P_FAMILY_VOLTORB
#if P_FAMILY_EXEGGCUTE
    [SPECIES_EXEGGCUTE] = sExeggcuteLevelUpLearnset,
    [SPECIES_EXEGGUTOR] = sExeggutorLevelUpLearnset,
    [SPECIES_EXEGGUTOR_ALOLA] = sExeggutorAlolaLevelUpLearnset,
#endif // P_FAMILY_EXEGGCUTE
#if P_FAMILY_CUBONE
    [SPECIES_CUBONE] = sCuboneLevelUpLearnset,
    [SPECIES_MAROWAK] = sMarowakLevelUpLearnset,
    [SPECIES_MAROWAK_ALOLA] = sMarowakAlolaLevelUpLearnset,
    [SPECIES_MAROWAK_ALOLA_TOTEM] = sMarowakAlolaLevelUpLearnset,
#endif // P_FAMILY_CUBONE
#if P_FAMILY_HITMONS
    [SPECIES_TYROGUE] = sTyrogueLevelUpLearnset,
    [SPECIES_HITMONLEE] = sHitmonleeLevelUpLearnset,
    [SPECIES_HITMONCHAN] = sHitmonchanLevelUpLearnset,
    [SPECIES_HITMONTOP] = sHitmontopLevelUpLearnset,
#endif // P_FAMILY_HITMONS
#if P_FAMILY_LICKITUNG
    [SPECIES_LICKITUNG] = sLickitungLevelUpLearnset,
    [SPECIES_LICKILICKY] = sLickilickyLevelUpLearnset,
#endif // P_FAMILY_LICKITUNG
#if P_FAMILY_KOFFING
    [SPECIES_KOFFING] = sKoffingLevelUpLearnset,
    [SPECIES_WEEZING] = sWeezingLevelUpLearnset,
    [SPECIES_WEEZING_GALAR] = sWeezingGalarLevelUpLearnset,
#endif // P_FAMILY_KOFFING
#if P_FAMILY_RHYHORN
    [SPECIES_RHYHORN] = sRhyhornLevelUpLearnset,
    [SPECIES_RHYDON] = sRhydonLevelUpLearnset,
    [SPECIES_RHYPERIOR] = sRhyperiorLevelUpLearnset,
#endif // P_FAMILY_RHYHORN
#if P_FAMILY_CHANSEY
    [SPECIES_HAPPINY] = sHappinyLevelUpLearnset,
    [SPECIES_CHANSEY] = sChanseyLevelUpLearnset,
    [SPECIES_BLISSEY] = sBlisseyLevelUpLearnset,
#endif // P_FAMILY_CHANSEY
#if P_FAMILY_TANGELA
    [SPECIES_TANGELA] = sTangelaLevelUpLearnset,
    [SPECIES_TANGROWTH] = sTangrowthLevelUpLearnset,
#endif // P_FAMILY_TANGELA
#if P_FAMILY_KANGASKHAN
    [SPECIES_KANGASKHAN] = sKangaskhanLevelUpLearnset,
    [SPECIES_KANGASKHAN_MEGA] = sKangaskhanLevelUpLearnset,
#endif // P_FAMILY_KANGASKHAN
#if P_FAMILY_HORSEA
    [SPECIES_HORSEA] = sHorseaLevelUpLearnset,
    [SPECIES_SEADRA] = sSeadraLevelUpLearnset,
    [SPECIES_KINGDRA] = sKingdraLevelUpLearnset,
#endif // P_FAMILY_HORSEA
#if P_FAMILY_GOLDEEN
    [SPECIES_GOLDEEN] = sGoldeenLevelUpLearnset,
    [SPECIES_SEAKING] = sSeakingLevelUpLearnset,
#endif // P_FAMILY_GOLDEEN
#if P_FAMILY_STARYU
    [SPECIES_STARYU] = sStaryuLevelUpLearnset,
    [SPECIES_STARMIE] = sStarmieLevelUpLearnset,
    [SPECIES_STARMIE_MEGA] = sStarmieLevelUpLearnset,
#endif // P_FAMILY_STARYU
#if P_FAMILY_MR_MIME
    [SPECIES_MIME_JR] = sMimeJrLevelUpLearnset,
    [SPECIES_MR_MIME] = sMrMimeLevelUpLearnset,
    [SPECIES_MR_MIME_GALAR] = sMrMimeGalarLevelUpLearnset,
    [SPECIES_MR_RIME] = sMrRimeLevelUpLearnset,
#endif // P_FAMILY_MR_MIME
#if P_FAMILY_SCYTHER
    [SPECIES_SCYTHER] = sScytherLevelUpLearnset,
    [SPECIES_SCIZOR] = sScizorLevelUpLearnset,
    [SPECIES_SCIZOR_MEGA] = sScizorLevelUpLearnset,
    [SPECIES_KLEAVOR] = sKleavorLevelUpLearnset,
#endif // P_FAMILY_SCYTHER
#if P_FAMILY_JYNX
    [SPECIES_SMOOCHUM] = sSmoochumLevelUpLearnset,
    [SPECIES_JYNX] = sJynxLevelUpLearnset,
#endif // P_FAMILY_JYNX
#if P_FAMILY_ELECTABUZZ
    [SPECIES_ELEKID] = sElekidLevelUpLearnset,
    [SPECIES_ELECTABUZZ] = sElectabuzzLevelUpLearnset,
    [SPECIES_ELECTIVIRE] = sElectivireLevelUpLearnset,
#endif // P_FAMILY_ELECTABUZZ
#if P_FAMILY_MAGMAR
    [SPECIES_MAGBY] = sMagbyLevelUpLearnset,
    [SPECIES_MAGMAR] = sMagmarLevelUpLearnset,
    [SPECIES_MAGMORTAR] = sMagmortarLevelUpLearnset,
#endif // P_FAMILY_MAGMAR
#if P_FAMILY_PINSIR
    [SPECIES_PINSIR] = sPinsirLevelUpLearnset,
    [SPECIES_PINSIR_MEGA] = sPinsirLevelUpLearnset,
#endif // P_FAMILY_PINSIR
#if P_FAMILY_TAUROS
    [SPECIES_TAUROS] = sTaurosLevelUpLearnset,
    [SPECIES_TAUROS_PALDEA_COMBAT] = sTaurosPaldeaCombatLevelUpLearnset,
    [SPECIES_TAUROS_PALDEA_BLAZE] = sTaurosPaldeaBlazeLevelUpLearnset,
    [SPECIES_TAUROS_PALDEA_AQUA] = sTaurosPaldeaAquaLevelUpLearnset,
#endif // P_FAMILY_TAUROS
#if P_FAMILY_MAGIKARP
    [SPECIES_MAGIKARP] = sMagikarpLevelUpLearnset,
    [SPECIES_GYARADOS] = sGyaradosLevelUpLearnset,
    [SPECIES_GYARADOS_MEGA] = sGyaradosLevelUpLearnset,
#endif // P_FAMILY_MAGIKARP
#if P_FAMILY_LAPRAS
    [SPECIES_LAPRAS] = sLaprasLevelUpLearnset,
    [SPECIES_LAPRAS_GMAX] = sLaprasLevelUpLearnset,
#endif // P_FAMILY_LAPRAS
#if P_FAMILY_DITTO
    [SPECIES_DITTO] = sDittoLevelUpLearnset,
#endif // P_FAMILY_DITTO
#if P_FAMILY_EEVEE
    [SPECIES_EEVEE] = sEeveeLevelUpLearnset,
    [SPECIES_EEVEE_GMAX] = sEeveeLevelUpLearnset,
    [SPECIES_EEVEE_STARTER] = sEeveeLevelUpLearnset,
    [SPECIES_VAPOREON] = sVaporeonLevelUpLearnset,
    [SPECIES_JOLTEON] = sJolteonLevelUpLearnset,
    [SPECIES_FLAREON] = sFlareonLevelUpLearnset,
    [SPECIES_ESPEON] = sEspeonLevelUpLearnset,
    [SPECIES_UMBREON] = sUmbreonLevelUpLearnset,
    [SPECIES_LEAFEON] = sLeafeonLevelUpLearnset,
    [SPECIES_GLACEON] = sGlaceonLevelUpLearnset,
    [SPECIES_SYLVEON] = sSylveonLevelUpLearnset,
#endif // P_FAMILY_EEVEE
#if P_FAMILY_PORYGON
    [SPECIES_PORYGON] = sPorygonLevelUpLearnset,
    [SPECIES_PORYGON2] = sPorygon2LevelUpLearnset,
    [SPECIES_PORYGON_Z] = sPorygonZLevelUpLearnset,
#endif // P_FAMILY_PORYGON
#if P_FAMILY_OMANYTE
    [SPECIES_OMANYTE] = sOmanyteLevelUpLearnset,
    [SPECIES_OMASTAR] = sOmastarLevelUpLearnset,
#endif // P_FAMILY_OMANYTE
#if P_FAMILY_KABUTO
    [SPECIES_KABUTO] = sKabutoLevelUpLearnset,
    [SPECIES_KABUTOPS] = sKabutopsLevelUpLearnset,
#endif // P_FAMILY_KABUTO
#if P_FAMILY_AERODACTYL
    [SPECIES_AERODACTYL] = sAerodactylLevelUpLearnset,
    [SPECIES_AERODACTYL_MEGA] = sAerodactylLevelUpLearnset,
#endif // P_FAMILY_AERODACTYL
#if P_FAMILY_SNORLAX
    [SPECIES_MUNCHLAX] = sMunchlaxLevelUpLearnset,
    [SPECIES_SNORLAX] = sSnorlaxLevelUpLearnset,
    [SPECIES_SNORLAX_GMAX] = sSnorlaxLevelUpLearnset,
#endif // P_FAMILY_SNORLAX
#if P_FAMILY_ARTICUNO
    [SPECIES_ARTICUNO] = sArticunoLevelUpLearnset,
    [SPECIES_ARTICUNO_GALAR] = sArticunoGalarLevelUpLearnset,
#endif // P_FAMILY_ARTICUNO
#if P_FAMILY_ZAPDOS
    [SPECIES_ZAPDOS] = sZapdosLevelUpLearnset,
    [SPECIES_ZAPDOS_GALAR] = sZapdosGalarLevelUpLearnset,
#endif // P_FAMILY_ZAPDOS
#if P_FAMILY_MOLTRES
    [SPECIES_MOLTRES] = sMoltresLevelUpLearnset,
    [SPECIES_MOLTRES_GALAR] = sMoltresGalarLevelUpLearnset,
#endif // P_FAMILY_MOLTRES
#if P_FAMILY_DRATINI
    [SPECIES_DRATINI] = sDratiniLevelUpLearnset,
    [SPECIES_DRAGONAIR] = sDragonairLevelUpLearnset,
    [SPECIES_DRAGONITE] = sDragoniteLevelUpLearnset,
    [SPECIES_DRAGONITE_MEGA] = sDragoniteLevelUpLearnset,
#endif // P_FAMILY_DRATINI
#if P_FAMILY_MEWTWO
    [SPECIES_MEWTWO] = sMewtwoLevelUpLearnset,
    [SPECIES_MEWTWO_MEGA_X] = sMewtwoLevelUpLearnset,
    [SPECIES_MEWTWO_MEGA_Y] = sMewtwoLevelUpLearnset,
#endif // P_FAMILY_MEWTWO
#if P_FAMILY_MEW
    [SPECIES_MEW] = sMewLevelUpLearnset,
#endif // P_FAMILY_MEW
#if P_FAMILY_CHIKORITA
    [SPECIES_CHIKORITA] = sChikoritaLevelUpLearnset,
    [SPECIES_BAYLEEF] = sBayleefLevelUpLearnset,
    [SPECIES_MEGANIUM] = sMeganiumLevelUpLearnset,
    [SPECIES_MEGANIUM_MEGA] = sMeganiumLevelUpLearnset,
#endif // P_FAMILY_CHIKORITA
#if P_FAMILY_CYNDAQUIL
    [SPECIES_CYNDAQUIL] = sCyndaquilLevelUpLearnset,
    [SPECIES_QUILAVA] = sQuilavaLevelUpLearnset,
    [SPECIES_TYPHLOSION] = sTyphlosionLevelUpLearnset,
    [SPECIES_TYPHLOSION_HISUI] = sTyphlosionHisuiLevelUpLearnset,
#endif // P_FAMILY_CYNDAQUIL
#if P_FAMILY_TOTODILE
    [SPECIES_TOTODILE] = sTotodileLevelUpLearnset,
    [SPECIES_CROCONAW] = sCroconawLevelUpLearnset,
    [SPECIES_FERALIGATR] = sFeraligatrLevelUpLearnset,
    [SPECIES_FERALIGATR_MEGA] = sFeraligatrLevelUpLearnset,
#endif // P_FAMILY_TOTODILE
#if P_FAMILY_SENTRET
    [SPECIES_SENTRET] = sSentretLevelUpLearnset,
    [SPECIES_FURRET] = sFurretLevelUpLearnset,
#endif // P_FAMILY_SENTRET
#if P_FAMILY_HOOTHOOT
    [SPECIES_HOOTHOOT] = sHoothootLevelUpLearnset,
    [SPECIES_NOCTOWL] = sNoctowlLevelUpLearnset,
#endif // P_FAMILY_HOOTHOOT
#if P_FAMILY_LEDYBA
    [SPECIES_LEDYBA] = sLedybaLevelUpLearnset,
    [SPECIES_LEDIAN] = sLedianLevelUpLearnset,
#endif // P_FAMILY_LEDYBA
#if P_FAMILY_SPINARAK
    [SPECIES_SPINARAK] = sSpinarakLevelUpLearnset,
    [SPECIES_ARIADOS] = sAriadosLevelUpLearnset,
#endif // P_FAMILY_SPINARAK
#if P_FAMILY_CHINCHOU
    [SPECIES_CHINCHOU] = sChinchouLevelUpLearnset,
    [SPECIES_LANTURN] = sLanturnLevelUpLearnset,
#endif // P_FAMILY_CHINCHOU
#if P_FAMILY_TOGEPI
    [SPECIES_TOGEPI] = sTogepiLevelUpLearnset,
    [SPECIES_TOGETIC] = sTogeticLevelUpLearnset,
    [SPECIES_TOGEKISS] = sTogekissLevelUpLearnset,
#endif // P_FAMILY_TOGEPI
#if P_FAMILY_NATU
    [SPECIES_NATU] = sNatuLevelUpLearnset,
    [SPECIES_XATU] = sXatuLevelUpLearnset,
#endif // P_FAMILY_NATU
#if P_FAMILY_MAREEP
    [SPECIES_MAREEP] = sMareepLevelUpLearnset,
    [SPECIES_FLAAFFY] = sFlaaffyLevelUpLearnset,
    [SPECIES_AMPHAROS] = sAmpharosLevelUpLearnset,
    [SPECIES_AMPHAROS_MEGA] = sAmpharosLevelUpLearnset,
#endif // P_FAMILY_MAREEP
#if P_FAMILY_MARILL
    [SPECIES_AZURILL] = sAzurillLevelUpLearnset,
    [SPECIES_MARILL] = sMarillLevelUpLearnset,
    [SPECIES_AZUMARILL] = sAzumarillLevelUpLearnset,
#endif // P_FAMILY_MARILL
#if P_FAMILY_SUDOWOODO
    [SPECIES_BONSLY] = sBonslyLevelUpLearnset,
    [SPECIES_SUDOWOODO] = sSudowoodoLevelUpLearnset,
#endif // P_FAMILY_SUDOWOODO
#if P_FAMILY_HOPPIP
    [SPECIES_HOPPIP] = sHoppipLevelUpLearnset,
    [SPECIES_SKIPLOOM] = sSkiploomLevelUpLearnset,
    [SPECIES_JUMPLUFF] = sJumpluffLevelUpLearnset,
#endif // P_FAMILY_HOPPIP
#if P_FAMILY_AIPOM
    [SPECIES_AIPOM] = sAipomLevelUpLearnset,
    [SPECIES_AMBIPOM] = sAmbipomLevelUpLearnset,
#endif // P_FAMILY_AIPOM
#if P_FAMILY_SUNKERN
    [SPECIES_SUNKERN] = sSunkernLevelUpLearnset,
    [SPECIES_SUNFLORA] = sSunfloraLevelUpLearnset,
#endif // P_FAMILY_SUNKERN
#if P_FAMILY_YANMA
    [SPECIES_YANMA] = sYanmaLevelUpLearnset,
    [SPECIES_YANMEGA] = sYanmegaLevelUpLearnset,
#endif // P_FAMILY_YANMA
#if P_FAMILY_WOOPER
    [SPECIES_WOOPER] = sWooperLevelUpLearnset,
    [SPECIES_QUAGSIRE] = sQuagsireLevelUpLearnset,
    [SPECIES_WOOPER_PALDEA] = sWooperPaldeaLevelUpLearnset,
    [SPECIES_CLODSIRE] = sClodsireLevelUpLearnset,
#endif // P_FAMILY_WOOPER
#if P_FAMILY_MURKROW
    [SPECIES_MURKROW] = sMurkrowLevelUpLearnset,
    [SPECIES_HONCHKROW] = sHonchkrowLevelUpLearnset,
#endif // P_FAMILY_MURKROW
#if P_FAMILY_MISDREAVUS
    [SPECIES_MISDREAVUS] = sMisdreavusLevelUpLearnset,
    [SPECIES_MISMAGIUS] = sMismagiusLevelUpLearnset,
#endif // P_FAMILY_MISDREAVUS
#if P_FAMILY_WOBBUFFET
    [SPECIES_WYNAUT] = sWynautLevelUpLearnset,
    [SPECIES_WOBBUFFET] = sWobbuffetLevelUpLearnset,
#endif // P_FAMILY_WOBBUFFET
#if P_FAMILY_GIRAFARIG
    [SPECIES_GIRAFARIG] = sGirafarigLevelUpLearnset,
    [SPECIES_FARIGIRAF] = sFarigirafLevelUpLearnset,
#endif // P_FAMILY_GIRAFARIG
#if P_FAMILY_PINECO
    [SPECIES_PINECO] = sPinecoLevelUpLearnset,
    [SPECIES_FORRETRESS] = sForretressLevelUpLearnset,
#endif // P_FAMILY_PINECO
#if P_FAMILY_DUNSPARCE
    [SPECIES_DUNSPARCE] = sDunsparceLevelUpLearnset,
    [SPECIES_DUDUNSPARCE_TWO_SEGMENT] = sDudunsparceLevelUpLearnset,
    [SPECIES_DUDUNSPARCE_THREE_SEGMENT] = sDudunsparceLevelUpLearnset,
#endif // P_FAMILY_DUNSPARCE
#if P_FAMILY_GLIGAR
    [SPECIES_GLIGAR] = sGligarLevelUpLearnset,
    [SPECIES_GLISCOR] = sGliscorLevelUpLearnset,
#endif // P_FAMILY_GLIGAR
#if P_FAMILY_SNUBBULL
    [SPECIES_SNUBBULL] = sSnubbullLevelUpLearnset,
    [SPECIES_GRANBULL] = sGranbullLevelUpLearnset,
#endif // P_FAMILY_SNUBBULL
#if P_FAMILY_QWILFISH
    [SPECIES_QWILFISH] = sQwilfishLevelUpLearnset,
    [SPECIES_QWILFISH_HISUI] = sQwilfishHisuiLevelUpLearnset,
    [SPECIES_OVERQWIL] = sOverqwilLevelUpLearnset,
#endif // P_FAMILY_QWILFISH
#if P_FAMILY_SHUCKLE
    [SPECIES_SHUCKLE] = sShuckleLevelUpLearnset,
#endif // P_FAMILY_SHUCKLE
#if P_FAMILY_HERACROSS
    [SPECIES_HERACROSS] = sHeracrossLevelUpLearnset,
    [SPECIES_HERACROSS_MEGA] = sHeracrossLevelUpLearnset,
#endif // P_FAMILY_HERACROSS
#if P_FAMILY_SNEASEL
    [SPECIES_SNEASEL] = sSneaselLevelUpLearnset,
    [SPECIES_WEAVILE] = sWeavileLevelUpLearnset,
    [SPECIES_SNEASEL_HISUI] = sSneaselHisuiLevelUpLearnset,
    [SPECIES_SNEASLER] = sSneaslerLevelUpLearnset,
#endif // P_FAMILY_SNEASEL
#if P_FAMILY_TEDDIURSA
    [SPECIES_TEDDIURSA] = sTeddiursaLevelUpLearnset,
    [SPECIES_URSARING] = sUrsaringLevelUpLearnset,
    [SPECIES_URSALUNA] = sUrsalunaLevelUpLearnset,
    [SPECIES_URSALUNA_BLOODMOON] = sUrsalunaBloodmoonLevelUpLearnset,
#endif // P_FAMILY_TEDDIURSA
#if P_FAMILY_SLUGMA
    [SPECIES_SLUGMA] = sSlugmaLevelUpLearnset,
    [SPECIES_MAGCARGO] = sMagcargoLevelUpLearnset,
#endif // P_FAMILY_SLUGMA
#if P_FAMILY_SWINUB
    [SPECIES_SWINUB] = sSwinubLevelUpLearnset,
    [SPECIES_PILOSWINE] = sPiloswineLevelUpLearnset,
    [SPECIES_MAMOSWINE] = sMamoswineLevelUpLearnset,
#endif // P_FAMILY_SWINUB
#if P_FAMILY_CORSOLA
    [SPECIES_CORSOLA] = sCorsolaLevelUpLearnset,
    [SPECIES_CORSOLA_GALAR] = sCorsolaGalarLevelUpLearnset,
    [SPECIES_CURSOLA] = sCursolaLevelUpLearnset,
#endif // P_FAMILY_CORSOLA
#if P_FAMILY_REMORAID
    [SPECIES_REMORAID] = sRemoraidLevelUpLearnset,
    [SPECIES_OCTILLERY] = sOctilleryLevelUpLearnset,
#endif // P_FAMILY_REMORAID
#if P_FAMILY_DELIBIRD
    [SPECIES_DELIBIRD] = sDelibirdLevelUpLearnset,
#endif // P_FAMILY_DELIBIRD
#if P_FAMILY_MANTINE
    [SPECIES_MANTYKE] = sMantykeLevelUpLearnset,
    [SPECIES_MANTINE] = sMantineLevelUpLearnset,
#endif // P_FAMILY_MANTINE
#if P_FAMILY_SKARMORY
    [SPECIES_SKARMORY] = sSkarmoryLevelUpLearnset,
    [SPECIES_SKARMORY_MEGA] = sSkarmoryLevelUpLearnset,
#endif // P_FAMILY_SKARMORY
#if P_FAMILY_HOUNDOUR
    [SPECIES_HOUNDOUR] = sHoundourLevelUpLearnset,
    [SPECIES_HOUNDOOM] = sHoundoomLevelUpLearnset,
    [SPECIES_HOUNDOOM_MEGA] = sHoundoomLevelUpLearnset,
#endif // P_FAMILY_HOUNDOUR
#if P_FAMILY_PHANPY
    [SPECIES_PHANPY] = sPhanpyLevelUpLearnset,
    [SPECIES_DONPHAN] = sDonphanLevelUpLearnset,
#endif // P_FAMILY_PHANPY
#if P_FAMILY_STANTLER
    [SPECIES_STANTLER] = sStantlerLevelUpLearnset,
    [SPECIES_WYRDEER] = sWyrdeerLevelUpLearnset,
#endif // P_FAMILY_STANTLER
#if P_FAMILY_SMEARGLE
    [SPECIES_SMEARGLE] = sSmeargleLevelUpLearnset,
#endif // P_FAMILY_SMEARGLE
#if P_FAMILY_MILTANK
    [SPECIES_MILTANK] = sMiltankLevelUpLearnset,
#endif // P_FAMILY_MILTANK
#if P_FAMILY_RAIKOU
    [SPECIES_RAIKOU] = sRaikouLevelUpLearnset,
#endif // P_FAMILY_RAIKOU
#if P_FAMILY_ENTEI
    [SPECIES_ENTEI] = sEnteiLevelUpLearnset,
#endif // P_FAMILY_ENTEI
#if P_FAMILY_SUICUNE
    [SPECIES_SUICUNE] = sSuicuneLevelUpLearnset,
#endif // P_FAMILY_SUICUNE
#if P_FAMILY_LARVITAR
    [SPECIES_LARVITAR] = sLarvitarLevelUpLearnset,
    [SPECIES_PUPITAR] = sPupitarLevelUpLearnset,
    [SPECIES_TYRANITAR] = sTyranitarLevelUpLearnset,
    [SPECIES_TYRANITAR_MEGA] = sTyranitarLevelUpLearnset,
#endif // P_FAMILY_LARVITAR
#if P_FAMILY_LUGIA
    [SPECIES_LUGIA] = sLugiaLevelUpLearnset,
#endif // P_FAMILY_LUGIA
#if P_FAMILY_HO_OH
    [SPECIES_HO_OH] = sHoOhLevelUpLearnset,
#endif // P_FAMILY_HO_OH
#if P_FAMILY_CELEBI
    [SPECIES_CELEBI] = sCelebiLevelUpLearnset,
#endif // P_FAMILY_CELEBI
#if P_FAMILY_TREECKO
    [SPECIES_TREECKO] = sTreeckoLevelUpLearnset,
    [SPECIES_GROVYLE] = sGrovyleLevelUpLearnset,
    [SPECIES_SCEPTILE] = sSceptileLevelUpLearnset,
    [SPECIES_SCEPTILE_MEGA] = sSceptileLevelUpLearnset,
#endif // P_FAMILY_TREECKO
#if P_FAMILY_TORCHIC
    [SPECIES_TORCHIC] = sTorchicLevelUpLearnset,
    [SPECIES_COMBUSKEN] = sCombuskenLevelUpLearnset,
    [SPECIES_BLAZIKEN] = sBlazikenLevelUpLearnset,
    [SPECIES_BLAZIKEN_MEGA] = sBlazikenLevelUpLearnset,
#endif // P_FAMILY_TORCHIC
#if P_FAMILY_MUDKIP
    [SPECIES_MUDKIP] = sMudkipLevelUpLearnset,
    [SPECIES_MARSHTOMP] = sMarshtompLevelUpLearnset,
    [SPECIES_SWAMPERT] = sSwampertLevelUpLearnset,
    [SPECIES_SWAMPERT_MEGA] = sSwampertLevelUpLearnset,
#endif // P_FAMILY_MUDKIP
#if P_FAMILY_POOCHYENA
    [SPECIES_POOCHYENA] = sPoochyenaLevelUpLearnset,
    [SPECIES_MIGHTYENA] = sMightyenaLevelUpLearnset,
#endif // P_FAMILY_POOCHYENA
#if P_FAMILY_ZIGZAGOON
    [SPECIES_ZIGZAGOON] = sZigzagoonLevelUpLearnset,
    [SPECIES_LINOONE] = sLinooneLevelUpLearnset,
    [SPECIES_ZIGZAGOON_GALAR] = sZigzagoonGalarLevelUpLearnset,
    [SPECIES_LINOONE_GALAR] = sLinooneGalarLevelUpLearnset,
    [SPECIES_OBSTAGOON] = sObstagoonLevelUpLearnset,
#endif // P_FAMILY_ZIGZAGOON
#if P_FAMILY_WURMPLE
    [SPECIES_WURMPLE] = sWurmpleLevelUpLearnset,
    [SPECIES_SILCOON] = sSilcoonLevelUpLearnset,
    [SPECIES_BEAUTIFLY] = sBeautiflyLevelUpLearnset,
    [SPECIES_CASCOON] = sCascoonLevelUpLearnset,
    [SPECIES_DUSTOX] = sDustoxLevelUpLearnset,
#endif // P_FAMILY_WURMPLE
#if P_FAMILY_LOTAD
    [SPECIES_LOTAD] = sLotadLevelUpLearnset,
    [SPECIES_LOMBRE] = sLombreLevelUpLearnset,
    [SPECIES_LUDICOLO] = sLudicoloLevelUpLearnset,
#endif // P_FAMILY_LOTAD
#if P_FAMILY_SEEDOT
    [SPECIES_SEEDOT] = sSeedotLevelUpLearnset,
    [SPECIES_NUZLEAF] = sNuzleafLevelUpLearnset,
    [SPECIES_SHIFTRY] = sShiftryLevelUpLearnset,
#endif // P_FAMILY_SEEDOT
#if P_FAMILY_TAILLOW
    [SPECIES_TAILLOW] = sTaillowLevelUpLearnset,
    [SPECIES_SWELLOW] = sSwellowLevelUpLearnset,
#endif // P_FAMILY_TAILLOW
#if P_FAMILY_WINGULL
    [SPECIES_WINGULL] = sWingullLevelUpLearnset,
    [SPECIES_PELIPPER] = sPelipperLevelUpLearnset,
#endif // P_FAMILY_WINGULL
#if P_FAMILY_RALTS
    [SPECIES_RALTS] = sRaltsLevelUpLearnset,
    [SPECIES_KIRLIA] = sKirliaLevelUpLearnset,
    [SPECIES_GARDEVOIR] = sGardevoirLevelUpLearnset,
    [SPECIES_GARDEVOIR_MEGA] = sGardevoirLevelUpLearnset,
    [SPECIES_GALLADE] = sGalladeLevelUpLearnset,
    [SPECIES_GALLADE_MEGA] = sGalladeLevelUpLearnset,
#endif // P_FAMILY_RALTS
#if P_FAMILY_SURSKIT
    [SPECIES_SURSKIT] = sSurskitLevelUpLearnset,
    [SPECIES_MASQUERAIN] = sMasquerainLevelUpLearnset,
#endif // P_FAMILY_SURSKIT
#if P_FAMILY_SHROOMISH
    [SPECIES_SHROOMISH] = sShroomishLevelUpLearnset,
    [SPECIES_BRELOOM] = sBreloomLevelUpLearnset,
#endif // P_FAMILY_SHROOMISH
#if P_FAMILY_SLAKOTH
    [SPECIES_SLAKOTH] = sSlakothLevelUpLearnset,
    [SPECIES_VIGOROTH] = sVigorothLevelUpLearnset,
    [SPECIES_SLAKING] = sSlakingLevelUpLearnset,
#endif // P_FAMILY_SLAKOTH
#if P_FAMILY_NINCADA
    [SPECIES_NINCADA] = sNincadaLevelUpLearnset,
    [SPECIES_NINJASK] = sNinjaskLevelUpLearnset,
    [SPECIES_SHEDINJA] = sShedinjaLevelUpLearnset,
#endif // P_FAMILY_NINCADA
#if P_FAMILY_WHISMUR
    [SPECIES_WHISMUR] = sWhismurLevelUpLearnset,
    [SPECIES_LOUDRED] = sLoudredLevelUpLearnset,
    [SPECIES_EXPLOUD] = sExploudLevelUpLearnset,
#endif // P_FAMILY_WHISMUR
#if P_FAMILY_MAKUHITA
    [SPECIES_MAKUHITA] = sMakuhitaLevelUpLearnset,
    [SPECIES_HARIYAMA] = sHariyamaLevelUpLearnset,
#endif // P_FAMILY_MAKUHITA
#if P_FAMILY_NOSEPASS
    [SPECIES_NOSEPASS] = sNosepassLevelUpLearnset,
    [SPECIES_PROBOPASS] = sProbopassLevelUpLearnset,
#endif // P_FAMILY_NOSEPASS
#if P_FAMILY_SKITTY
    [SPECIES_SKITTY] = sSkittyLevelUpLearnset,
    [SPECIES_DELCATTY] = sDelcattyLevelUpLearnset,
#endif // P_FAMILY_SKITTY
#if P_FAMILY_SABLEYE
    [SPECIES_SABLEYE] = sSableyeLevelUpLearnset,
    [SPECIES_SABLEYE_MEGA] = sSableyeLevelUpLearnset,
#endif // P_FAMILY_SABLEYE
#if P_FAMILY_MAWILE
    [SPECIES_MAWILE] = sMawileLevelUpLearnset,
    [SPECIES_MAWILE_MEGA] = sMawileLevelUpLearnset,
#endif // P_FAMILY_MAWILE
#if P_FAMILY_ARON
    [SPECIES_ARON] = sAronLevelUpLearnset,
    [SPECIES_LAIRON] = sLaironLevelUpLearnset,
    [SPECIES_AGGRON] = sAggronLevelUpLearnset,
    [SPECIES_AGGRON_MEGA] = sAggronLevelUpLearnset,
#endif // P_FAMILY_ARON
#if P_FAMILY_MEDITITE
    [SPECIES_MEDITITE] = sMedititeLevelUpLearnset,
    [SPECIES_MEDICHAM] = sMedichamLevelUpLearnset,
    [SPECIES_MEDICHAM_MEGA] = sMedichamLevelUpLearnset,
#endif // P_FAMILY_MEDITITE
#if P_FAMILY_ELECTRIKE
    [SPECIES_ELECTRIKE] = sElectrikeLevelUpLearnset,
    [SPECIES_MANECTRIC] = sManectricLevelUpLearnset,
    [SPECIES_MANECTRIC_MEGA] = sManectricLevelUpLearnset,
#endif // P_FAMILY_ELECTRIKE
#if P_FAMILY_PLUSLE
    [SPECIES_PLUSLE] = sPlusleLevelUpLearnset,
#endif // P_FAMILY_PLUSLE
#if P_FAMILY_MINUN
    [SPECIES_MINUN] = sMinunLevelUpLearnset,
#endif // P_FAMILY_MINUN
#if P_FAMILY_VOLBEAT_ILLUMISE
    [SPECIES_VOLBEAT] = sVolbeatLevelUpLearnset,
    [SPECIES_ILLUMISE] = sIllumiseLevelUpLearnset,
#endif // P_FAMILY_VOLBEAT_ILLUMISE
#if P_FAMILY_ROSELIA
    [SPECIES_BUDEW] = sBudewLevelUpLearnset,
    [SPECIES_ROSELIA] = sRoseliaLevelUpLearnset,
    [SPECIES_ROSERADE] = sRoseradeLevelUpLearnset,
#endif // P_FAMILY_ROSELIA
#if P_FAMILY_GULPIN
    [SPECIES_GULPIN] = sGulpinLevelUpLearnset,
    [SPECIES_SWALOT] = sSwalotLevelUpLearnset,
#endif // P_FAMILY_GULPIN
#if P_FAMILY_CARVANHA
    [SPECIES_CARVANHA] = sCarvanhaLevelUpLearnset,
    [SPECIES_SHARPEDO] = sSharpedoLevelUpLearnset,
    [SPECIES_SHARPEDO_MEGA] = sSharpedoLevelUpLearnset,
#endif // P_FAMILY_CARVANHA
#if P_FAMILY_WAILMER
    [SPECIES_WAILMER] = sWailmerLevelUpLearnset,
    [SPECIES_WAILORD] = sWailordLevelUpLearnset,
#endif // P_FAMILY_WAILMER
#if P_FAMILY_NUMEL
    [SPECIES_NUMEL] = sNumelLevelUpLearnset,
    [SPECIES_CAMERUPT] = sCameruptLevelUpLearnset,
    [SPECIES_CAMERUPT_MEGA] = sCameruptLevelUpLearnset,
#endif // P_FAMILY_NUMEL
#if P_FAMILY_TORKOAL
    [SPECIES_TORKOAL] = sTorkoalLevelUpLearnset,
#endif // P_FAMILY_TORKOAL
#if P_FAMILY_SPOINK
    [SPECIES_SPOINK] = sSpoinkLevelUpLearnset,
    [SPECIES_GRUMPIG] = sGrumpigLevelUpLearnset,
#endif // P_FAMILY_SPOINK
#if P_FAMILY_SPINDA
    [SPECIES_SPINDA] = sSpindaLevelUpLearnset,
#endif // P_FAMILY_SPINDA
#if P_FAMILY_TRAPINCH
    [SPECIES_TRAPINCH] = sTrapinchLevelUpLearnset,
    [SPECIES_VIBRAVA] = sVibravaLevelUpLearnset,
    [SPECIES_FLYGON] = sFlygonLevelUpLearnset,
#endif // P_FAMILY_TRAPINCH
#if P_FAMILY_CACNEA
    [SPECIES_CACNEA] = sCacneaLevelUpLearnset,
    [SPECIES_CACTURNE] = sCacturneLevelUpLearnset,
#endif // P_FAMILY_CACNEA
#if P_FAMILY_SWABLU
    [SPECIES_SWABLU] = sSwabluLevelUpLearnset,
    [SPECIES_ALTARIA] = sAltariaLevelUpLearnset,
    [SPECIES_ALTARIA_MEGA] = sAltariaLevelUpLearnset,
#endif // P_FAMILY_SWABLU
#if P_FAMILY_ZANGOOSE
    [SPECIES_ZANGOOSE] = sZangooseLevelUpLearnset,
#endif // P_FAMILY_ZANGOOSE
#if P_FAMILY_SEVIPER
    [SPECIES_SEVIPER] = sSeviperLevelUpLearnset,
#endif // P_FAMILY_SEVIPER
#if P_FAMILY_LUNATONE
    [SPECIES_LUNATONE] = sLunatoneLevelUpLearnset,
#endif // P_FAMILY_LUNATONE
#if P_FAMILY_SOLROCK
    [SPECIES_SOLROCK] = sSolrockLevelUpLearnset,
#endif // P_FAMILY_SOLROCK
#if P_FAMILY_BARBOACH
    [SPECIES_BARBOACH] = sBarboachLevelUpLearnset,
    [SPECIES_WHISCASH] = sWhiscashLevelUpLearnset,
#endif // P_FAMILY_BARBOACH
#if P_FAMILY_CORPHISH
    [SPECIES_CORPHISH] = sCorphishLevelUpLearnset,
    [SPECIES_CRAWDAUNT] = sCrawdauntLevelUpLearnset,
#endif // P_FAMILY_CORPHISH
#if P_FAMILY_BALTOY
    [SPECIES_BALTOY] = sBaltoyLevelUpLearnset,
    [SPECIES_CLAYDOL] = sClaydolLevelUpLearnset,
#endif // P_FAMILY_BALTOY
#if P_FAMILY_LILEEP
    [SPECIES_LILEEP] = sLileepLevelUpLearnset,
    [SPECIES_CRADILY] = sCradilyLevelUpLearnset,
#endif // P_FAMILY_LILEEP
#if P_FAMILY_ANORITH
    [SPECIES_ANORITH] = sAnorithLevelUpLearnset,
    [SPECIES_ARMALDO] = sArmaldoLevelUpLearnset,
#endif // P_FAMILY_ANORITH
#if P_FAMILY_FEEBAS
    [SPECIES_FEEBAS] = sFeebasLevelUpLearnset,
    [SPECIES_MILOTIC] = sMiloticLevelUpLearnset,
#endif // P_FAMILY_FEEBAS
#if P_FAMILY_CASTFORM
    [SPECIES_CASTFORM_NORMAL] = sCastformLevelUpLearnset,
    [SPECIES_CASTFORM_SUNNY] = sCastformLevelUpLearnset,
    [SPECIES_CASTFORM_RAINY] = sCastformLevelUpLearnset,
    [SPECIES_CASTFORM_SNOWY] = sCastformLevelUpLearnset,
#endif // P_FAMILY_CASTFORM
#if P_FAMILY_KECLEON
    [SPECIES_KECLEON] = sKecleonLevelUpLearnset,
#endif // P_FAMILY_KECLEON
#if P_FAMILY_SHUPPET
    [SPECIES_SHUPPET] = sShuppetLevelUpLearnset,
    [SPECIES_BANETTE] = sBanetteLevelUpLearnset,
    [SPECIES_BANETTE_MEGA] = sBanetteLevelUpLearnset,
#endif // P_FAMILY_SHUPPET
#if P_FAMILY_DUSKULL
    [SPECIES_DUSKULL] = sDuskullLevelUpLearnset,
    [SPECIES_DUSCLOPS] = sDusclopsLevelUpLearnset,
    [SPECIES_DUSKNOIR] = sDusknoirLevelUpLearnset,
#endif // P_FAMILY_DUSKULL
#if P_FAMILY_TROPIUS
    [SPECIES_TROPIUS] = sTropiusLevelUpLearnset,
#endif // P_FAMILY_TROPIUS
#if P_FAMILY_CHIMECHO
    [SPECIES_CHINGLING] = sChinglingLevelUpLearnset,
    [SPECIES_CHIMECHO] = sChimechoLevelUpLearnset,
    [SPECIES_CHIMECHO_MEGA] = sChimechoLevelUpLearnset,
#endif // P_FAMILY_CHIMECHO
#if P_FAMILY_ABSOL
    [SPECIES_ABSOL] = sAbsolLevelUpLearnset,
    [SPECIES_ABSOL_MEGA] = sAbsolLevelUpLearnset,
    [SPECIES_ABSOL_MEGA_Z] = sAbsolLevelUpLearnset,
#endif // P_FAMILY_ABSOL
#if P_FAMILY_SNORUNT
    [SPECIES_SNORUNT] = sSnoruntLevelUpLearnset,
    [SPECIES_GLALIE] = sGlalieLevelUpLearnset,
    [SPECIES_GLALIE_MEGA] = sGlalieLevelUpLearnset,
    [SPECIES_FROSLASS] = sFroslassLevelUpLearnset,
    [SPECIES_FROSLASS_MEGA] = sFroslassLevelUpLearnset,
#endif // P_FAMILY_SNORUNT
#if P_FAMILY_SPHEAL
    [SPECIES_SPHEAL] = sSphealLevelUpLearnset,
    [SPECIES_SEALEO] = sSealeoLevelUpLearnset,
    [SPECIES_WALREIN] = sWalreinLevelUpLearnset,
#endif // P_FAMILY_SPHEAL
#if P_FAMILY_CLAMPERL
    [SPECIES_CLAMPERL] = sClamperlLevelUpLearnset,
    [SPECIES_HUNTAIL] = sHuntailLevelUpLearnset,
    [SPECIES_GOREBYSS] = sGorebyssLevelUpLearnset,
#endif // P_FAMILY_CLAMPERL
#if P_FAMILY_RELICANTH
    [SPECIES_RELICANTH] = sRelicanthLevelUpLearnset,
#endif // P_FAMILY_RELICANTH
#if P_FAMILY_LUVDISC
    [SPECIES_LUVDISC] = sLuvdiscLevelUpLearnset,
#endif // P_FAMILY_LUVDISC
#if P_FAMILY_BAGON
    [SPECIES_BAGON] = sBagonLevelUpLearnset,
    [SPECIES_SHELGON] = sShelgonLevelUpLearnset,
    [SPECIES_SALAMENCE] = sSalamenceLevelUpLearnset,
    [SPECIES_SALAMENCE_MEGA] = sSalamenceLevelUpLearnset,
#endif // P_FAMILY_BAGON
#if P_FAMILY_BELDUM
    [SPECIES_BELDUM] = sBeldumLevelUpLearnset,
    [SPECIES_METANG] = sMetangLevelUpLearnset,
    [SPECIES_METAGROSS] = sMetagrossLevelUpLearnset,
    [SPECIES_METAGROSS_MEGA] = sMetagrossLevelUpLearnset,
#endif // P_FAMILY_BELDUM
#if P_FAMILY_REGIROCK
    [SPECIES_REGIROCK] = sRegirockLevelUpLearnset,
#endif // P_FAMILY_REGIROCK
#if P_FAMILY_REGICE
    [SPECIES_REGICE] = sRegiceLevelUpLearnset,
#endif // P_FAMILY_REGICE
#if P_FAMILY_REGISTEEL
    [SPECIES_REGISTEEL] = sRegisteelLevelUpLearnset,
#endif // P_FAMILY_REGISTEEL
#if P_FAMILY_LATIAS
    [SPECIES_LATIAS] = sLatiasLevelUpLearnset,
    [SPECIES_LATIAS_MEGA] = sLatiasLevelUpLearnset,
#endif // P_FAMILY_LATIAS
#if P_FAMILY_LATIOS
    [SPECIES_LATIOS] = sLatiosLevelUpLearnset,
    [SPECIES_LATIOS_MEGA] = sLatiosLevelUpLearnset,
#endif // P_FAMILY_LATIOS
#if P_FAMILY_KYOGRE
    [SPECIES_KYOGRE] = sKyogreLevelUpLearnset,
    [SPECIES_KYOGRE_PRIMAL] = sKyogreLevelUpLearnset,
#endif // P_FAMILY_KYOGRE
#if P_FAMILY_GROUDON
    [SPECIES_GROUDON] = sGroudonLevelUpLearnset,
    [SPECIES_GROUDON_PRIMAL] = sGroudonLevelUpLearnset,
#endif // P_FAMILY_GROUDON
#if P_FAMILY_RAYQUAZA
    [SPECIES_RAYQUAZA] = sRayquazaLevelUpLearnset,
    [SPECIES_RAYQUAZA_MEGA] = sRayquazaLevelUpLearnset,
#endif // P_FAMILY_RAYQUAZA
#if P_FAMILY_JIRACHI
    [SPECIES_JIRACHI] = sJirachiLevelUpLearnset,
#endif // P_FAMILY_JIRACHI
#if P_FAMILY_DEOXYS
    [SPECIES_DEOXYS_NORMAL] = sDeoxysNormalLevelUpLearnset,
    [SPECIES_DEOXYS_ATTACK] = sDeoxysAttackLevelUpLearnset,
    [SPECIES_DEOXYS_DEFENSE] = sDeoxysDefenseLevelUpLearnset,
    [SPECIES_DEOXYS_SPEED] = sDeoxysSpeedLevelUpLearnset,
#endif // P_FAMILY_DEOXYS
#if P_FAMILY_TURTWIG
    [SPECIES_TURTWIG] = sTurtwigLevelUpLearnset,
    [SPECIES_GROTLE] = sGrotleLevelUpLearnset,
    [SPECIES_TORTERRA] = sTorterraLevelUpLearnset,
#endif // P_FAMILY_TURTWIG
#if P_FAMILY_CHIMCHAR
    [SPECIES_CHIMCHAR] = sChimcharLevelUpLearnset,
    [SPECIES_MONFERNO] = sMonfernoLevelUpLearnset,
    [SPECIES_INFERNAPE] = sInfernapeLevelUpLearnset,
#endif // P_FAMILY_CHIMCHAR
#if P_FAMILY_PIPLUP
    [SPECIES_PIPLUP] = sPiplupLevelUpLearnset,
    [SPECIES_PRINPLUP] = sPrinplupLevelUpLearnset,
    [SPECIES_EMPOLEON] = sEmpoleonLevelUpLearnset,
#endif // P_FAMILY_PIPLUP
#if P_FAMILY_STARLY
    [SPECIES_STARLY] = sStarlyLevelUpLearnset,
    [SPECIES_STARAVIA] = sStaraviaLevelUpLearnset,
    [SPECIES_STARAPTOR] = sStaraptorLevelUpLearnset,
    [SPECIES_STARAPTOR_MEGA] = sStaraptorLevelUpLearnset,
#endif // P_FAMILY_STARLY
#if P_FAMILY_BIDOOF
    [SPECIES_BIDOOF] = sBidoofLevelUpLearnset,
    [SPECIES_BIBAREL] = sBibarelLevelUpLearnset,
#endif // P_FAMILY_BIDOOF
#if P_FAMILY_KRICKETOT
    [SPECIES_KRICKETOT] = sKricketotLevelUpLearnset,
    [SPECIES_KRICKETUNE] = sKricketuneLevelUpLearnset,
#endif // P_FAMILY_KRICKETOT
#if P_FAMILY_SHINX
    [SPECIES_SHINX] = sShinxLevelUpLearnset,
    [SPECIES_LUXIO] = sLuxioLevelUpLearnset,
    [SPECIES_LUXRAY] = sLuxrayLevelUpLearnset,
#endif // P_FAMILY_SHINX
#if P_FAMILY_CRANIDOS
    [SPECIES_CRANIDOS] = sCranidosLevelUpLearnset,
    [SPECIES_RAMPARDOS] = sRampardosLevelUpLearnset,
#endif // P_FAMILY_CRANIDOS
#if P_FAMILY_SHIELDON
    [SPECIES_SHIELDON] = sShieldonLevelUpLearnset,
    [SPECIES_BASTIODON] = sBastiodonLevelUpLearnset,
#endif // P_FAMILY_SHIELDON
#if P_FAMILY_BURMY
    [SPECIES_BURMY_PLANT] = sBurmyLevelUpLearnset,
    [SPECIES_BURMY_SANDY] = sBurmyLevelUpLearnset,
    [SPECIES_BURMY_TRASH] = sBurmyLevelUpLearnset,
    [SPECIES_WORMADAM_PLANT] = sWormadamPlantLevelUpLearnset,
    [SPECIES_WORMADAM_SANDY] = sWormadamSandyLevelUpLearnset,
    [SPECIES_WORMADAM_TRASH] = sWormadamTrashLevelUpLearnset,
#endif // P_FAMILY_BURMY
#if P_FAMILY_COMBEE
    [SPECIES_COMBEE] = sCombeeLevelUpLearnset,
    [SPECIES_VESPIQUEN] = sVespiquenLevelUpLearnset,
#endif // P_FAMILY_COMBEE
#if P_FAMILY_PACHIRISU
    [SPECIES_PACHIRISU] = sPachirisuLevelUpLearnset,
#endif // P_FAMILY_PACHIRISU
#if P_FAMILY_BUIZEL
    [SPECIES_BUIZEL] = sBuizelLevelUpLearnset,
    [SPECIES_FLOATZEL] = sFloatzelLevelUpLearnset,
#endif // P_FAMILY_BUIZEL
#if P_FAMILY_CHERUBI
    [SPECIES_CHERUBI] = sCherubiLevelUpLearnset,
    [SPECIES_CHERRIM_OVERCAST] = sCherrimLevelUpLearnset,
    [SPECIES_CHERRIM_SUNSHINE] = sCherrimLevelUpLearnset,
#endif // P_FAMILY_CHERUBI
#if P_FAMILY_SHELLOS
    [SPECIES_SHELLOS_WEST] = sShellosLevelUpLearnset,
    [SPECIES_SHELLOS_EAST] = sShellosLevelUpLearnset,
    [SPECIES_GASTRODON_WEST] = sGastrodonLevelUpLearnset,
    [SPECIES_GASTRODON_EAST] = sGastrodonLevelUpLearnset,
#endif // P_FAMILY_SHELLOS
#if P_FAMILY_DRIFLOON
    [SPECIES_DRIFLOON] = sDrifloonLevelUpLearnset,
    [SPECIES_DRIFBLIM] = sDrifblimLevelUpLearnset,
#endif // P_FAMILY_DRIFLOON
#if P_FAMILY_BUNEARY
    [SPECIES_BUNEARY] = sBunearyLevelUpLearnset,
    [SPECIES_LOPUNNY] = sLopunnyLevelUpLearnset,
    [SPECIES_LOPUNNY_MEGA] = sLopunnyLevelUpLearnset,
#endif // P_FAMILY_BUNEARY
#if P_FAMILY_GLAMEOW
    [SPECIES_GLAMEOW] = sGlameowLevelUpLearnset,
    [SPECIES_PURUGLY] = sPuruglyLevelUpLearnset,
#endif // P_FAMILY_GLAMEOW
#if P_FAMILY_STUNKY
    [SPECIES_STUNKY] = sStunkyLevelUpLearnset,
    [SPECIES_SKUNTANK] = sSkuntankLevelUpLearnset,
#endif // P_FAMILY_STUNKY
#if P_FAMILY_BRONZOR
    [SPECIES_BRONZOR] = sBronzorLevelUpLearnset,
    [SPECIES_BRONZONG] = sBronzongLevelUpLearnset,
#endif // P_FAMILY_BRONZOR
#if P_FAMILY_CHATOT
    [SPECIES_CHATOT] = sChatotLevelUpLearnset,
#endif // P_FAMILY_CHATOT
#if P_FAMILY_SPIRITOMB
    [SPECIES_SPIRITOMB] = sSpiritombLevelUpLearnset,
#endif // P_FAMILY_SPIRITOMB
#if P_FAMILY_GIBLE
    [SPECIES_GIBLE] = sGibleLevelUpLearnset,
    [SPECIES_GABITE] = sGabiteLevelUpLearnset,
    [SPECIES_GARCHOMP] = sGarchompLevelUpLearnset,
    [SPECIES_GARCHOMP_MEGA] = sGarchompLevelUpLearnset,
    [SPECIES_GARCHOMP_MEGA_Z] = sGarchompLevelUpLearnset,
#endif // P_FAMILY_GIBLE
#if P_FAMILY_RIOLU
    [SPECIES_RIOLU] = sRioluLevelUpLearnset,
    [SPECIES_LUCARIO] = sLucarioLevelUpLearnset,
    [SPECIES_LUCARIO_MEGA] = sLucarioLevelUpLearnset,
    [SPECIES_LUCARIO_MEGA_Z] = sLucarioLevelUpLearnset,
#endif // P_FAMILY_RIOLU
#if P_FAMILY_HIPPOPOTAS
    [SPECIES_HIPPOPOTAS] = sHippopotasLevelUpLearnset,
    [SPECIES_HIPPOWDON] = sHippowdonLevelUpLearnset,
#endif // P_FAMILY_HIPPOPOTAS
#if P_FAMILY_SKORUPI
    [SPECIES_SKORUPI] = sSkorupiLevelUpLearnset,
    [SPECIES_DRAPION] = sDrapionLevelUpLearnset,
#endif // P_FAMILY_SKORUPI
#if P_FAMILY_CROAGUNK
    [SPECIES_CROAGUNK] = sCroagunkLevelUpLearnset,
    [SPECIES_TOXICROAK] = sToxicroakLevelUpLearnset,
#endif // P_FAMILY_CROAGUNK
#if P_FAMILY_CARNIVINE
    [SPECIES_CARNIVINE] = sCarnivineLevelUpLearnset,
#endif // P_FAMILY_CARNIVINE
#if P_FAMILY_FINNEON
    [SPECIES_FINNEON] = sFinneonLevelUpLearnset,
    [SPECIES_LUMINEON] = sLumineonLevelUpLearnset,
#endif // P_FAMILY_FINNEON
#if P_FAMILY_SNOVER
    [SPECIES_SNOVER] = sSnoverLevelUpLearnset,
    [SPECIES_ABOMASNOW] = sAbomasnowLevelUpLearnset,
    [SPECIES_ABOMASNOW_MEGA] = sAbomasnowLevelUpLearnset,
#endif // P_FAMILY_SNOVER
#if P_FAMILY_ROTOM
    [SPECIES_ROTOM] = sRotomLevelUpLearnset,
    [SPECIES_ROTOM_HEAT] = sRotomLevelUpLearnset,
    [SPECIES_ROTOM_WASH] = sRotomLevelUpLearnset,
    [SPECIES_ROTOM_FROST] = sRotomLevelUpLearnset,
    [SPECIES_ROTOM_FAN] = sRotomLevelUpLearnset,
    [SPECIES_ROTOM_MOW] = sRotomLevelUpLearnset,
#endif // P_FAMILY_ROTOM
#if P_FAMILY_UXIE
    [SPECIES_UXIE] = sUxieLevelUpLearnset,
#endif // P_FAMILY_UXIE
#if P_FAMILY_MESPRIT
    [SPECIES_MESPRIT] = sMespritLevelUpLearnset,
#endif // P_FAMILY_MESPRIT
#if P_FAMILY_AZELF
    [SPECIES_AZELF] = sAzelfLevelUpLearnset,
#endif // P_FAMILY_AZELF
#if P_FAMILY_DIALGA
    [SPECIES_DIALGA] = sDialgaLevelUpLearnset,
    [SPECIES_DIALGA_ORIGIN] = sDialgaLevelUpLearnset,
#endif // P_FAMILY_DIALGA
#if P_FAMILY_PALKIA
    [SPECIES_PALKIA] = sPalkiaLevelUpLearnset,
    [SPECIES_PALKIA_ORIGIN] = sPalkiaLevelUpLearnset,
#endif // P_FAMILY_PALKIA
#if P_FAMILY_HEATRAN
    [SPECIES_HEATRAN] = sHeatranLevelUpLearnset,
    [SPECIES_HEATRAN_MEGA] = sHeatranLevelUpLearnset,
#endif // P_FAMILY_HEATRAN
#if P_FAMILY_REGIGIGAS
    [SPECIES_REGIGIGAS] = sRegigigasLevelUpLearnset,
#endif // P_FAMILY_REGIGIGAS
#if P_FAMILY_GIRATINA
    [SPECIES_GIRATINA_ALTERED] = sGiratinaLevelUpLearnset,
    [SPECIES_GIRATINA_ORIGIN] = sGiratinaLevelUpLearnset,
#endif // P_FAMILY_GIRATINA
#if P_FAMILY_CRESSELIA
    [SPECIES_CRESSELIA] = sCresseliaLevelUpLearnset,
#endif // P_FAMILY_CRESSELIA
#if P_FAMILY_MANAPHY
    [SPECIES_PHIONE] = sPhioneLevelUpLearnset,
    [SPECIES_MANAPHY] = sManaphyLevelUpLearnset,
#endif // P_FAMILY_MANAPHY
#if P_FAMILY_DARKRAI
    [SPECIES_DARKRAI] = sDarkraiLevelUpLearnset,
    [SPECIES_DARKRAI_MEGA] = sDarkraiLevelUpLearnset,
#endif // P_FAMILY_DARKRAI
#if P_FAMILY_SHAYMIN
    [SPECIES_SHAYMIN_LAND] = sShayminLandLevelUpLearnset,
    [SPECIES_SHAYMIN_SKY] = sShayminSkyLevelUpLearnset,
#endif // P_FAMILY_SHAYMIN
#if P_FAMILY_VICTINI
    [SPECIES_VICTINI] = sVictiniLevelUpLearnset,
#endif // P_FAMILY_VICTINI
#if P_FAMILY_SNIVY
    [SPECIES_SNIVY] = sSnivyLevelUpLearnset,
    [SPECIES_SERVINE] = sServineLevelUpLearnset,
    [SPECIES_SERPERIOR] = sSerperiorLevelUpLearnset,
#endif // P_FAMILY_SNIVY
#if P_FAMILY_TEPIG
    [SPECIES_TEPIG] = sTepigLevelUpLearnset,
    [SPECIES_PIGNITE] = sPigniteLevelUpLearnset,
    [SPECIES_EMBOAR] = sEmboarLevelUpLearnset,
    [SPECIES_EMBOAR_MEGA] = sEmboarLevelUpLearnset,
#endif // P_FAMILY_TEPIG
#if P_FAMILY_OSHAWOTT
    [SPECIES_OSHAWOTT] = sOshawottLevelUpLearnset,
    [SPECIES_DEWOTT] = sDewottLevelUpLearnset,
    [SPECIES_SAMUROTT] = sSamurottLevelUpLearnset,
    [SPECIES_SAMUROTT_HISUI] = sSamurottHisuiLevelUpLearnset,
#endif // P_FAMILY_OSHAWOTT
#if P_FAMILY_PATRAT
    [SPECIES_PATRAT] = sPatratLevelUpLearnset,
    [SPECIES_WATCHOG] = sWatchogLevelUpLearnset,
#endif // P_FAMILY_PATRAT
#if P_FAMILY_LILLIPUP
    [SPECIES_LILLIPUP] = sLillipupLevelUpLearnset,
    [SPECIES_HERDIER] = sHerdierLevelUpLearnset,
    [SPECIES_STOUTLAND] = sStoutlandLevelUpLearnset,
#endif // P_FAMILY_LILLIPUP
#if P_FAMILY_PURRLOIN
    [SPECIES_PURRLOIN] = sPurrloinLevelUpLearnset,
    [SPECIES_LIEPARD] = sLiepardLevelUpLearnset,
#endif // P_FAMILY_PURRLOIN
#if P_FAMILY_PANSAGE
    [SPECIES_PANSAGE] = sPansageLevelUpLearnset,
    [SPECIES_SIMISAGE] = sSimisageLevelUpLearnset,
#endif // P_FAMILY_PANSAGE
#if P_FAMILY_PANSEAR
    [SPECIES_PANSEAR] = sPansearLevelUpLearnset,
    [SPECIES_SIMISEAR] = sSimisearLevelUpLearnset,
#endif // P_FAMILY_PANSEAR
#if P_FAMILY_PANPOUR
    [SPECIES_PANPOUR] = sPanpourLevelUpLearnset,
    [SPECIES_SIMIPOUR] = sSimipourLevelUpLearnset,
#endif // P_FAMILY_PANPOUR
#if P_FAMILY_MUNNA
    [SPECIES_MUNNA] = sMunnaLevelUpLearnset,
    [SPECIES_MUSHARNA] = sMusharnaLevelUpLearnset,
#endif // P_FAMILY_MUNNA
#if P_FAMILY_PIDOVE
    [SPECIES_PIDOVE] = sPidoveLevelUpLearnset,
    [SPECIES_TRANQUILL] = sTranquillLevelUpLearnset,
    [SPECIES_UNFEZANT] = sUnfezantLevelUpLearnset,
#endif // P_FAMILY_PIDOVE
#if P_FAMILY_BLITZLE
    [SPECIES_BLITZLE] = sBlitzleLevelUpLearnset,
    [SPECIES_ZEBSTRIKA] = sZebstrikaLevelUpLearnset,
#endif // P_FAMILY_BLITZLE
#if P_FAMILY_ROGGENROLA
    [SPECIES_ROGGENROLA] = sRoggenrolaLevelUpLearnset,
    [SPECIES_BOLDORE] = sBoldoreLevelUpLearnset,
    [SPECIES_GIGALITH] = sGigalithLevelUpLearnset,
#endif // P_FAMILY_ROGGENROLA
#if P_FAMILY_WOOBAT
    [SPECIES_WOOBAT] = sWoobatLevelUpLearnset,
    [SPECIES_SWOOBAT] = sSwoobatLevelUpLearnset,
#endif // P_FAMILY_WOOBAT
#if P_FAMILY_DRILBUR
    [SPECIES_DRILBUR] = sDrilburLevelUpLearnset,
    [SPECIES_EXCADRILL] = sExcadrillLevelUpLearnset,
    [SPECIES_EXCADRILL_MEGA] = sExcadrillLevelUpLearnset,
#endif // P_FAMILY_DRILBUR
#if P_FAMILY_AUDINO
    [SPECIES_AUDINO] = sAudinoLevelUpLearnset,
    [SPECIES_AUDINO_MEGA] = sAudinoLevelUpLearnset,
#endif // P_FAMILY_AUDINO
#if P_FAMILY_TIMBURR
    [SPECIES_TIMBURR] = sTimburrLevelUpLearnset,
    [SPECIES_GURDURR] = sGurdurrLevelUpLearnset,
    [SPECIES_CONKELDURR] = sConkeldurrLevelUpLearnset,
#endif // P_FAMILY_TIMBURR
#if P_FAMILY_TYMPOLE
    [SPECIES_TYMPOLE] = sTympoleLevelUpLearnset,
    [SPECIES_PALPITOAD] = sPalpitoadLevelUpLearnset,
    [SPECIES_SEISMITOAD] = sSeismitoadLevelUpLearnset,
#endif // P_FAMILY_TYMPOLE
#if P_FAMILY_THROH
    [SPECIES_THROH] = sThrohLevelUpLearnset,
#endif // P_FAMILY_THROH
#if P_FAMILY_SAWK
    [SPECIES_SAWK] = sSawkLevelUpLearnset,
#endif // P_FAMILY_SAWK
#if P_FAMILY_SEWADDLE
    [SPECIES_SEWADDLE] = sSewaddleLevelUpLearnset,
    [SPECIES_SWADLOON] = sSwadloonLevelUpLearnset,
    [SPECIES_LEAVANNY] = sLeavannyLevelUpLearnset,
#endif // P_FAMILY_SEWADDLE
#if P_FAMILY_VENIPEDE
    [SPECIES_VENIPEDE] = sVenipedeLevelUpLearnset,
    [SPECIES_WHIRLIPEDE] = sWhirlipedeLevelUpLearnset,
    [SPECIES_SCOLIPEDE] = sScolipedeLevelUpLearnset,
    [SPECIES_SCOLIPEDE_MEGA] = sScolipedeLevelUpLearnset,
#endif // P_FAMILY_VENIPEDE
#if P_FAMILY_COTTONEE
    [SPECIES_COTTONEE] = sCottoneeLevelUpLearnset,
    [SPECIES_WHIMSICOTT] = sWhimsicottLevelUpLearnset,
#endif // P_FAMILY_COTTONEE
#if P_FAMILY_PETILIL
    [SPECIES_PETILIL] = sPetililLevelUpLearnset,
    [SPECIES_LILLIGANT] = sLilligantLevelUpLearnset,
    [SPECIES_LILLIGANT_HISUI] = sLilligantHisuiLevelUpLearnset,
#endif // P_FAMILY_PETILIL
#if P_FAMILY_BASCULIN
    [SPECIES_BASCULIN_RED_STRIPED] = sBasculinLevelUpLearnset,
    [SPECIES_BASCULIN_BLUE_STRIPED] = sBasculinLevelUpLearnset,
    [SPECIES_BASCULIN_WHITE_STRIPED] = sBasculinWhiteStripedLevelUpLearnset,
    [SPECIES_BASCULEGION_M] = sBasculegionLevelUpLearnset,
    [SPECIES_BASCULEGION_F] = sBasculegionLevelUpLearnset,
#endif // P_FAMILY_BASCULIN
#if P_FAMILY_SANDILE
    [SPECIES_SANDILE] = sSandileLevelUpLearnset,
    [SPECIES_KROKOROK] = sKrokorokLevelUpLearnset,
    [SPECIES_KROOKODILE] = sKrookodileLevelUpLearnset,
#endif // P_FAMILY_SANDILE
#if P_FAMILY_DARUMAKA
    [SPECIES_DARUMAKA] = sDarumakaLevelUpLearnset,
    [SPECIES_DARMANITAN_STANDARD] = sDarmanitanLevelUpLearnset,
    [SPECIES_DARMANITAN_ZEN] = sDarmanitanLevelUpLearnset,
    [SPECIES_DARUMAKA_GALAR] = sDarumakaGalarLevelUpLearnset,
    [SPECIES_DARMANITAN_GALAR_STANDARD] = sDarmanitanGalarLevelUpLearnset,
    [SPECIES_DARMANITAN_GALAR_ZEN] = sDarmanitanGalarLevelUpLearnset,
#endif // P_FAMILY_DARUMAKA
#if P_FAMILY_MARACTUS
    [SPECIES_MARACTUS] = sMaractusLevelUpLearnset,
#endif // P_FAMILY_MARACTUS
#if P_FAMILY_DWEBBLE
    [SPECIES_DWEBBLE] = sDwebbleLevelUpLearnset,
    [SPECIES_CRUSTLE] = sCrustleLevelUpLearnset,
#endif // P_FAMILY_DWEBBLE
#if P_FAMILY_SCRAGGY
    [SPECIES_SCRAGGY] = sScraggyLevelUpLearnset,
    [SPECIES_SCRAFTY] = sScraftyLevelUpLearnset,
    [SPECIES_SCRAFTY_MEGA] = sScraftyLevelUpLearnset,
#endif // P_FAMILY_SCRAGGY
#if P_FAMILY_SIGILYPH
    [SPECIES_SIGILYPH] = sSigilyphLevelUpLearnset,
#endif // P_FAMILY_SIGILYPH
#if P_FAMILY_YAMASK
    [SPECIES_YAMASK] = sYamaskLevelUpLearnset,
    [SPECIES_COFAGRIGUS] = sCofagrigusLevelUpLearnset,
    [SPECIES_YAMASK_GALAR] = sYamaskGalarLevelUpLearnset,
    [SPECIES_RUNERIGUS] = sRunerigusLevelUpLearnset,
#endif // P_FAMILY_YAMASK
#if P_FAMILY_TIRTOUGA
    [SPECIES_TIRTOUGA] = sTirtougaLevelUpLearnset,
    [SPECIES_CARRACOSTA] = sCarracostaLevelUpLearnset,
#endif // P_FAMILY_TIRTOUGA
#if P_FAMILY_ARCHEN
    [SPECIES_ARCHEN] = sArchenLevelUpLearnset,
    [SPECIES_ARCHEOPS] = sArcheopsLevelUpLearnset,
#endif // P_FAMILY_ARCHEN
#if P_FAMILY_TRUBBISH
    [SPECIES_TRUBBISH] = sTrubbishLevelUpLearnset,
    [SPECIES_GARBODOR] = sGarbodorLevelUpLearnset,
    [SPECIES_GARBODOR_GMAX] = sGarbodorLevelUpLearnset,
#endif // P_FAMILY_TRUBBISH
#if P_FAMILY_ZORUA
    [SPECIES_ZORUA] = sZoruaLevelUpLearnset,
    [SPECIES_ZOROARK] = sZoroarkLevelUpLearnset,
    [SPECIES_ZORUA_HISUI] = sZoruaHisuiLevelUpLearnset,
    [SPECIES_ZOROARK_HISUI] = sZoroarkHisuiLevelUpLearnset,
#endif // P_FAMILY_ZORUA
#if P_FAMILY_MINCCINO
    [SPECIES_MINCCINO] = sMinccinoLevelUpLearnset,
    [SPECIES_CINCCINO] = sCinccinoLevelUpLearnset,
#endif // P_FAMILY_MINCCINO
#if P_FAMILY_GOTHITA
    [SPECIES_GOTHITA] = sGothitaLevelUpLearnset,
    [SPECIES_GOTHORITA] = sGothoritaLevelUpLearnset,
    [SPECIES_GOTHITELLE] = sGothitelleLevelUpLearnset,
#endif // P_FAMILY_GOTHITA
#if P_FAMILY_SOLOSIS
    [SPECIES_SOLOSIS] = sSolosisLevelUpLearnset,
    [SPECIES_DUOSION] = sDuosionLevelUpLearnset,
    [SPECIES_REUNICLUS] = sReuniclusLevelUpLearnset,
#endif // P_FAMILY_SOLOSIS
#if P_FAMILY_DUCKLETT
    [SPECIES_DUCKLETT] = sDucklettLevelUpLearnset,
    [SPECIES_SWANNA] = sSwannaLevelUpLearnset,
#endif // P_FAMILY_DUCKLETT
#if P_FAMILY_VANILLITE
    [SPECIES_VANILLITE] = sVanilliteLevelUpLearnset,
    [SPECIES_VANILLISH] = sVanillishLevelUpLearnset,
    [SPECIES_VANILLUXE] = sVanilluxeLevelUpLearnset,
#endif // P_FAMILY_VANILLITE
#if P_FAMILY_DEERLING
    [SPECIES_DEERLING_SPRING] = sDeerlingLevelUpLearnset,
    [SPECIES_DEERLING_SUMMER] = sDeerlingLevelUpLearnset,
    [SPECIES_DEERLING_AUTUMN] = sDeerlingLevelUpLearnset,
    [SPECIES_DEERLING_WINTER] = sDeerlingLevelUpLearnset,
    [SPECIES_SAWSBUCK_SPRING] = sSawsbuckLevelUpLearnset,
    [SPECIES_SAWSBUCK_SUMMER] = sSawsbuckLevelUpLearnset,
    [SPECIES_SAWSBUCK_AUTUMN] = sSawsbuckLevelUpLearnset,
    [SPECIES_SAWSBUCK_WINTER] = sSawsbuckLevelUpLearnset,
#endif // P_FAMILY_DEERLING
#if P_FAMILY_EMOLGA
    [SPECIES_EMOLGA] = sEmolgaLevelUpLearnset,
#endif // P_FAMILY_EMOLGA
#if P_FAMILY_KARRABLAST
    [SPECIES_KARRABLAST] = sKarrablastLevelUpLearnset,
    [SPECIES_ESCAVALIER] = sEscavalierLevelUpLearnset,
#endif // P_FAMILY_KARRABLAST
#if P_FAMILY_FOONGUS
    [SPECIES_FOONGUS] = sFoongusLevelUpLearnset,
    [SPECIES_AMOONGUSS] = sAmoongussLevelUpLearnset,
#endif // P_FAMILY_FOONGUS
#if P_FAMILY_FRILLISH
    [SPECIES_FRILLISH] = sFrillishLevelUpLearnset,
    [SPECIES_JELLICENT] = sJellicentLevelUpLearnset,
#endif // P_FAMILY_FRILLISH
#if P_FAMILY_ALOMOMOLA
    [SPECIES_ALOMOMOLA] = sAlomomolaLevelUpLearnset,
#endif // P_FAMILY_ALOMOMOLA
#if P_FAMILY_JOLTIK
    [SPECIES_JOLTIK] = sJoltikLevelUpLearnset,
    [SPECIES_GALVANTULA] = sGalvantulaLevelUpLearnset,
#endif // P_FAMILY_JOLTIK
#if P_FAMILY_FERROSEED
    [SPECIES_FERROSEED] = sFerroseedLevelUpLearnset,
    [SPECIES_FERROTHORN] = sFerrothornLevelUpLearnset,
#endif // P_FAMILY_FERROSEED
#if P_FAMILY_KLINK
    [SPECIES_KLINK] = sKlinkLevelUpLearnset,
    [SPECIES_KLANG] = sKlangLevelUpLearnset,
    [SPECIES_KLINKLANG] = sKlinklangLevelUpLearnset,
#endif // P_FAMILY_KLINK
#if P_FAMILY_TYNAMO
    [SPECIES_TYNAMO] = sTynamoLevelUpLearnset,
    [SPECIES_EELEKTRIK] = sEelektrikLevelUpLearnset,
    [SPECIES_EELEKTROSS] = sEelektrossLevelUpLearnset,
    [SPECIES_EELEKTROSS_MEGA] = sEelektrossLevelUpLearnset,
#endif // P_FAMILY_TYNAMO
#if P_FAMILY_ELGYEM
    [SPECIES_ELGYEM] = sElgyemLevelUpLearnset,
    [SPECIES_BEHEEYEM] = sBeheeyemLevelUpLearnset,
#endif // P_FAMILY_ELGYEM
#if P_FAMILY_LITWICK
    [SPECIES_LITWICK] = sLitwickLevelUpLearnset,
    [SPECIES_LAMPENT] = sLampentLevelUpLearnset,
    [SPECIES_CHANDELURE] = sChandelureLevelUpLearnset,
    [SPECIES_CHANDELURE_MEGA] = sChandelureLevelUpLearnset,
#endif // P_FAMILY_LITWICK
#if P_FAMILY_AXEW
    [SPECIES_AXEW] = sAxewLevelUpLearnset,
    [SPECIES_FRAXURE] = sFraxureLevelUpLearnset,
    [SPECIES_HAXORUS] = sHaxorusLevelUpLearnset,
#endif // P_FAMILY_AXEW
#if P_FAMILY_CUBCHOO
    [SPECIES_CUBCHOO] = sCubchooLevelUpLearnset,
    [SPECIES_BEARTIC] = sBearticLevelUpLearnset,
#endif // P_FAMILY_CUBCHOO
#if P_FAMILY_CRYOGONAL
    [SPECIES_CRYOGONAL] = sCryogonalLevelUpLearnset,
#endif // P_FAMILY_CRYOGONAL
#if P_FAMILY_SHELMET
    [SPECIES_SHELMET] = sShelmetLevelUpLearnset,
    [SPECIES_ACCELGOR] = sAccelgorLevelUpLearnset,
#endif // P_FAMILY_SHELMET
#if P_FAMILY_STUNFISK
    [SPECIES_STUNFISK] = sStunfiskLevelUpLearnset,
    [SPECIES_STUNFISK_GALAR] = sStunfiskGalarLevelUpLearnset,
#endif // P_FAMILY_STUNFISK
#if P_FAMILY_MIENFOO
    [SPECIES_MIENFOO] = sMienfooLevelUpLearnset,
    [SPECIES_MIENSHAO] = sMienshaoLevelUpLearnset,
#endif // P_FAMILY_MIENFOO
#if P_FAMILY_DRUDDIGON
    [SPECIES_DRUDDIGON] = sDruddigonLevelUpLearnset,
#endif // P_FAMILY_DRUDDIGON
#if P_FAMILY_GOLETT
    [SPECIES_GOLETT] = sGolettLevelUpLearnset,
    [SPECIES_GOLURK] = sGolurkLevelUpLearnset,
    [SPECIES_GOLURK_MEGA] = sGolurkLevelUpLearnset,
#endif // P_FAMILY_GOLETT
#if P_FAMILY_PAWNIARD
    [SPECIES_PAWNIARD] = sPawniardLevelUpLearnset,
    [SPECIES_BISHARP] = sBisharpLevelUpLearnset,
    [SPECIES_KINGAMBIT] = sKingambitLevelUpLearnset,
#endif // P_FAMILY_PAWNIARD
#if P_FAMILY_BOUFFALANT
    [SPECIES_BOUFFALANT] = sBouffalantLevelUpLearnset,
#endif // P_FAMILY_BOUFFALANT
#if P_FAMILY_RUFFLET
    [SPECIES_RUFFLET] = sRuffletLevelUpLearnset,
    [SPECIES_BRAVIARY] = sBraviaryLevelUpLearnset,
    [SPECIES_BRAVIARY_HISUI] = sBraviaryHisuiLevelUpLearnset,
#endif // P_FAMILY_RUFFLET
#if P_FAMILY_VULLABY
    [SPECIES_VULLABY] = sVullabyLevelUpLearnset,
    [SPECIES_MANDIBUZZ] = sMandibuzzLevelUpLearnset,
#endif // P_FAMILY_VULLABY
#if P_FAMILY_HEATMOR
    [SPECIES_HEATMOR] = sHeatmorLevelUpLearnset,
#endif // P_FAMILY_HEATMOR
#if P_FAMILY_DURANT
    [SPECIES_DURANT] = sDurantLevelUpLearnset,
#endif // P_FAMILY_DURANT
#if P_FAMILY_DEINO
    [SPECIES_DEINO] = sDeinoLevelUpLearnset,
    [SPECIES_ZWEILOUS] = sZweilousLevelUpLearnset,
    [SPECIES_HYDREIGON] = sHydreigonLevelUpLearnset,
#endif // P_FAMILY_DEINO
#if P_FAMILY_LARVESTA
    [SPECIES_LARVESTA] = sLarvestaLevelUpLearnset,
    [SPECIES_VOLCARONA] = sVolcaronaLevelUpLearnset,
#endif // P_FAMILY_LARVESTA
#if P_FAMILY_COBALION
    [SPECIES_COBALION] = sCobalionLevelUpLearnset,
#endif // P_FAMILY_COBALION
#if P_FAMILY_TERRAKION
    [SPECIES_TERRAKION] = sTerrakionLevelUpLearnset,
#endif // P_FAMILY_TERRAKION
#if P_FAMILY_VIRIZION
    [SPECIES_VIRIZION] = sVirizionLevelUpLearnset,
#endif // P_FAMILY_VIRIZION
#if P_FAMILY_TORNADUS
    [SPECIES_TORNADUS_INCARNATE] = sTornadusLevelUpLearnset,
    [SPECIES_TORNADUS_THERIAN] = sTornadusLevelUpLearnset,
#endif // P_FAMILY_TORNADUS
#if P_FAMILY_THUNDURUS
    [SPECIES_THUNDURUS_INCARNATE] = sThundurusLevelUpLearnset,
    [SPECIES_THUNDURUS_THERIAN] = sThundurusLevelUpLearnset,
#endif // P_FAMILY_THUNDURUS
#if P_FAMILY_RESHIRAM
    [SPECIES_RESHIRAM] = sReshiramLevelUpLearnset,
#endif // P_FAMILY_RESHIRAM
#if P_FAMILY_ZEKROM
    [SPECIES_ZEKROM] = sZekromLevelUpLearnset,
#endif // P_FAMILY_ZEKROM
#if P_FAMILY_LANDORUS
    [SPECIES_LANDORUS_INCARNATE] = sLandorusLevelUpLearnset,
    [SPECIES_LANDORUS_THERIAN] = sLandorusLevelUpLearnset,
#endif // P_FAMILY_LANDORUS
#if P_FAMILY_KYUREM
    [SPECIES_KYUREM] = sKyuremLevelUpLearnset,
    [SPECIES_KYUREM_WHITE] = sKyuremWhiteLevelUpLearnset,
    [SPECIES_KYUREM_BLACK] = sKyuremBlackLevelUpLearnset,
#endif // P_FAMILY_KYUREM
#if P_FAMILY_KELDEO
    [SPECIES_KELDEO_ORDINARY] = sKeldeoLevelUpLearnset,
    [SPECIES_KELDEO_RESOLUTE] = sKeldeoLevelUpLearnset,
#endif // P_FAMILY_KELDEO
#if P_FAMILY_MELOETTA
    [SPECIES_MELOETTA_ARIA] = sMeloettaLevelUpLearnset,
    [SPECIES_MELOETTA_PIROUETTE] = sMeloettaLevelUpLearnset,
#endif // P_FAMILY_MELOETTA
#if P_FAMILY_CHESPIN
    [SPECIES_CHESPIN] = sChespinLevelUpLearnset,
    [SPECIES_QUILLADIN] = sQuilladinLevelUpLearnset,
    [SPECIES_CHESNAUGHT] = sChesnaughtLevelUpLearnset,
    [SPECIES_CHESNAUGHT_MEGA] = sChesnaughtLevelUpLearnset,
#endif // P_FAMILY_CHESPIN
#if P_FAMILY_FENNEKIN
    [SPECIES_FENNEKIN] = sFennekinLevelUpLearnset,
    [SPECIES_BRAIXEN] = sBraixenLevelUpLearnset,
    [SPECIES_DELPHOX] = sDelphoxLevelUpLearnset,
    [SPECIES_DELPHOX_MEGA] = sDelphoxLevelUpLearnset,
#endif // P_FAMILY_FENNEKIN
#if P_FAMILY_FROAKIE
    [SPECIES_FROAKIE] = sFroakieLevelUpLearnset,
    [SPECIES_FROGADIER] = sFrogadierLevelUpLearnset,
    [SPECIES_GRENINJA] = sGreninjaLevelUpLearnset,
    [SPECIES_GRENINJA_BATTLE_BOND] = sGreninjaLevelUpLearnset,
    [SPECIES_GRENINJA_ASH] = sGreninjaLevelUpLearnset,
    [SPECIES_GRENINJA_MEGA] = sGreninjaLevelUpLearnset,
#endif // P_FAMILY_FROAKIE
#if P_FAMILY_BUNNELBY
    [SPECIES_BUNNELBY] = sBunnelbyLevelUpLearnset,
    [SPECIES_DIGGERSBY] = sDiggersbyLevelUpLearnset,
#endif // P_FAMILY_BUNNELBY
#if P_FAMILY_FLETCHLING
    [SPECIES_FLETCHLING] = sFletchlingLevelUpLearnset,
    [SPECIES_FLETCHINDER] = sFletchinderLevelUpLearnset,
    [SPECIES_TALONFLAME] = sTalonflameLevelUpLearnset,
#endif // P_FAMILY_FLETCHLING
#if P_FAMILY_SCATTERBUG
    [SPECIES_SCATTERBUG_POKEBALL] = sSpewpaLevelUpLearnset,
    [SPECIES_SPEWPA_POKEBALL] = sVivillonLevelUpLearnset,
#endif // P_FAMILY_SCATTERBUG
#if P_FAMILY_LITLEO
    [SPECIES_LITLEO] = sLitleoLevelUpLearnset,
    [SPECIES_PYROAR] = sPyroarLevelUpLearnset,
    [SPECIES_PYROAR_MEGA] = sPyroarLevelUpLearnset,
#endif // P_FAMILY_LITLEO
#if P_FAMILY_FLABEBE
    [SPECIES_FLABEBE_WHITE] = sFloetteLevelUpLearnset,
    [SPECIES_FLOETTE_ETERNAL] = sFloetteEternalLevelUpLearnset,
    [SPECIES_FLOETTE_MEGA] = sFloetteEternalLevelUpLearnset,
#endif // P_FAMILY_FLABEBE
#if P_FAMILY_SKIDDO
    [SPECIES_SKIDDO] = sSkiddoLevelUpLearnset,
    [SPECIES_GOGOAT] = sGogoatLevelUpLearnset,
#endif // P_FAMILY_SKIDDO
#if P_FAMILY_PANCHAM
    [SPECIES_PANCHAM] = sPanchamLevelUpLearnset,
    [SPECIES_PANGORO] = sPangoroLevelUpLearnset,
#endif // P_FAMILY_PANCHAM
#if P_FAMILY_ESPURR
    [SPECIES_ESPURR] = sEspurrLevelUpLearnset,
    [SPECIES_MEOWSTIC_M] = sMeowsticMLevelUpLearnset,
    [SPECIES_MEOWSTIC_F] = sMeowsticFLevelUpLearnset,
    [SPECIES_MEOWSTIC_M_MEGA] = sMeowsticMLevelUpLearnset,
    [SPECIES_MEOWSTIC_F_MEGA] = sMeowsticFLevelUpLearnset,
#endif // P_FAMILY_ESPURR
#if P_FAMILY_HONEDGE
    [SPECIES_HONEDGE] = sHonedgeLevelUpLearnset,
    [SPECIES_DOUBLADE] = sDoubladeLevelUpLearnset,
    [SPECIES_AEGISLASH_SHIELD] = sAegislashLevelUpLearnset,
    [SPECIES_AEGISLASH_BLADE] = sAegislashLevelUpLearnset,
#endif // P_FAMILY_HONEDGE
#if P_FAMILY_SPRITZEE
    [SPECIES_SPRITZEE] = sSpritzeeLevelUpLearnset,
    [SPECIES_AROMATISSE] = sAromatisseLevelUpLearnset,
#endif // P_FAMILY_SPRITZEE
#if P_FAMILY_SWIRLIX
    [SPECIES_SWIRLIX] = sSwirlixLevelUpLearnset,
    [SPECIES_SLURPUFF] = sSlurpuffLevelUpLearnset,
#endif // P_FAMILY_SWIRLIX
#if P_FAMILY_INKAY
    [SPECIES_INKAY] = sInkayLevelUpLearnset,
    [SPECIES_MALAMAR] = sMalamarLevelUpLearnset,
    [SPECIES_MALAMAR_MEGA] = sMalamarLevelUpLearnset,
#endif // P_FAMILY_INKAY
#if P_FAMILY_BINACLE
    [SPECIES_BINACLE] = sBinacleLevelUpLearnset,
    [SPECIES_BARBARACLE] = sBarbaracleLevelUpLearnset,
    [SPECIES_BARBARACLE_MEGA] = sBarbaracleLevelUpLearnset,
#endif // P_FAMILY_BINACLE
#if P_FAMILY_SKRELP
    [SPECIES_SKRELP] = sSkrelpLevelUpLearnset,
    [SPECIES_DRAGALGE] = sDragalgeLevelUpLearnset,
    [SPECIES_DRAGALGE_MEGA] = sDragalgeLevelUpLearnset,
#endif // P_FAMILY_SKRELP
#if P_FAMILY_CLAUNCHER
    [SPECIES_CLAUNCHER] = sClauncherLevelUpLearnset,
    [SPECIES_CLAWITZER] = sClawitzerLevelUpLearnset,
#endif // P_FAMILY_CLAUNCHER
#if P_FAMILY_HELIOPTILE
    [SPECIES_HELIOPTILE] = sHelioptileLevelUpLearnset,
    [SPECIES_HELIOLISK] = sHelioliskLevelUpLearnset,
#endif // P_FAMILY_HELIOPTILE
#if P_FAMILY_TYRUNT
    [SPECIES_TYRUNT] = sTyruntLevelUpLearnset,
    [SPECIES_TYRANTRUM] = sTyrantrumLevelUpLearnset,
#endif // P_FAMILY_TYRUNT
#if P_FAMILY_AMAURA
    [SPECIES_AMAURA] = sAmauraLevelUpLearnset,
    [SPECIES_AURORUS] = sAurorusLevelUpLearnset,
#endif // P_FAMILY_AMAURA
#if P_FAMILY_HAWLUCHA
    [SPECIES_HAWLUCHA] = sHawluchaLevelUpLearnset,
    [SPECIES_HAWLUCHA_MEGA] = sHawluchaLevelUpLearnset,
#endif // P_FAMILY_HAWLUCHA
#if P_FAMILY_DEDENNE
    [SPECIES_DEDENNE] = sDedenneLevelUpLearnset,
#endif // P_FAMILY_DEDENNE
#if P_FAMILY_CARBINK
    [SPECIES_CARBINK] = sCarbinkLevelUpLearnset,
#endif // P_FAMILY_CARBINK
#if P_FAMILY_GOOMY
    [SPECIES_GOOMY] = sGoomyLevelUpLearnset,
    [SPECIES_SLIGGOO] = sSliggooLevelUpLearnset,
    [SPECIES_GOODRA] = sGoodraLevelUpLearnset,
    [SPECIES_SLIGGOO_HISUI] = sSliggooHisuiLevelUpLearnset,
    [SPECIES_GOODRA_HISUI] = sGoodraHisuiLevelUpLearnset,
#endif // P_FAMILY_GOOMY
#if P_FAMILY_KLEFKI
    [SPECIES_KLEFKI] = sKlefkiLevelUpLearnset,
#endif // P_FAMILY_KLEFKI
#if P_FAMILY_PHANTUMP
    [SPECIES_PHANTUMP] = sPhantumpLevelUpLearnset,
    [SPECIES_TREVENANT] = sTrevenantLevelUpLearnset,
#endif // P_FAMILY_PHANTUMP
#if P_FAMILY_PUMPKABOO
    [SPECIES_PUMPKABOO_AVERAGE] = sPumpkabooLevelUpLearnset,
    [SPECIES_PUMPKABOO_SMALL] = sPumpkabooLevelUpLearnset,
    [SPECIES_PUMPKABOO_LARGE] = sPumpkabooLevelUpLearnset,
    [SPECIES_PUMPKABOO_SUPER] = sPumpkabooLevelUpLearnset,
    [SPECIES_GOURGEIST_AVERAGE] = sGourgeistLevelUpLearnset,
    [SPECIES_GOURGEIST_SMALL] = sGourgeistLevelUpLearnset,
    [SPECIES_GOURGEIST_LARGE] = sGourgeistLevelUpLearnset,
    [SPECIES_GOURGEIST_SUPER] = sGourgeistLevelUpLearnset,
#endif // P_FAMILY_PUMPKABOO
#if P_FAMILY_BERGMITE
    [SPECIES_BERGMITE] = sBergmiteLevelUpLearnset,
    [SPECIES_AVALUGG] = sAvaluggLevelUpLearnset,
    [SPECIES_AVALUGG_HISUI] = sAvaluggHisuiLevelUpLearnset,
#endif // P_FAMILY_BERGMITE
#if P_FAMILY_NOIBAT
    [SPECIES_NOIBAT] = sNoibatLevelUpLearnset,
    [SPECIES_NOIVERN] = sNoivernLevelUpLearnset,
#endif // P_FAMILY_NOIBAT
#if P_FAMILY_XERNEAS
    [SPECIES_XERNEAS_NEUTRAL] = sXerneasLevelUpLearnset,
    [SPECIES_XERNEAS_ACTIVE] = sXerneasLevelUpLearnset,
#endif // P_FAMILY_XERNEAS
#if P_FAMILY_YVELTAL
    [SPECIES_YVELTAL] = sYveltalLevelUpLearnset,
#endif // P_FAMILY_YVELTAL
#if P_FAMILY_ZYGARDE
    [SPECIES_ZYGARDE_50] = sZygardeLevelUpLearnset,
    [SPECIES_ZYGARDE_50_POWER_CONSTRUCT] = sZygardeLevelUpLearnset,
    [SPECIES_ZYGARDE_10_AURA_BREAK] = sZygardeLevelUpLearnset,
    [SPECIES_ZYGARDE_10_POWER_CONSTRUCT] = sZygardeLevelUpLearnset,
    [SPECIES_ZYGARDE_COMPLETE] = sZygardeLevelUpLearnset,
    [SPECIES_ZYGARDE_MEGA] = sZygardeLevelUpLearnset,
#endif // P_FAMILY_ZYGARDE
#if P_FAMILY_DIANCIE
    [SPECIES_DIANCIE] = sDiancieLevelUpLearnset,
    [SPECIES_DIANCIE_MEGA] = sDiancieLevelUpLearnset,
#endif // P_FAMILY_DIANCIE
#if P_FAMILY_HOOPA
    [SPECIES_HOOPA_CONFINED] = sHoopaConfinedLevelUpLearnset,
    [SPECIES_HOOPA_UNBOUND] = sHoopaUnboundLevelUpLearnset,
#endif // P_FAMILY_HOOPA
#if P_FAMILY_VOLCANION
    [SPECIES_VOLCANION] = sVolcanionLevelUpLearnset,
#endif // P_FAMILY_VOLCANION
#if P_FAMILY_ROWLET
    [SPECIES_ROWLET] = sRowletLevelUpLearnset,
    [SPECIES_DARTRIX] = sDartrixLevelUpLearnset,
    [SPECIES_DECIDUEYE] = sDecidueyeLevelUpLearnset,
    [SPECIES_DECIDUEYE_HISUI] = sDecidueyeHisuiLevelUpLearnset,
#endif // P_FAMILY_ROWLET
#if P_FAMILY_LITTEN
    [SPECIES_LITTEN] = sLittenLevelUpLearnset,
    [SPECIES_TORRACAT] = sTorracatLevelUpLearnset,
    [SPECIES_INCINEROAR] = sIncineroarLevelUpLearnset,
#endif // P_FAMILY_LITTEN
#if P_FAMILY_POPPLIO
    [SPECIES_POPPLIO] = sPopplioLevelUpLearnset,
    [SPECIES_BRIONNE] = sBrionneLevelUpLearnset,
    [SPECIES_PRIMARINA] = sPrimarinaLevelUpLearnset,
#endif // P_FAMILY_POPPLIO
#if P_FAMILY_PIKIPEK
    [SPECIES_PIKIPEK] = sPikipekLevelUpLearnset,
    [SPECIES_TRUMBEAK] = sTrumbeakLevelUpLearnset,
    [SPECIES_TOUCANNON] = sToucannonLevelUpLearnset,
#endif // P_FAMILY_PIKIPEK
#if P_FAMILY_YUNGOOS
    [SPECIES_YUNGOOS] = sYungoosLevelUpLearnset,
    [SPECIES_GUMSHOOS] = sGumshoosLevelUpLearnset,
    [SPECIES_GUMSHOOS_TOTEM] = sGumshoosLevelUpLearnset,
#endif // P_FAMILY_YUNGOOS
#if P_FAMILY_GRUBBIN
    [SPECIES_GRUBBIN] = sGrubbinLevelUpLearnset,
    [SPECIES_CHARJABUG] = sCharjabugLevelUpLearnset,
    [SPECIES_VIKAVOLT] = sVikavoltLevelUpLearnset,
    [SPECIES_VIKAVOLT_TOTEM] = sVikavoltLevelUpLearnset,
#endif // P_FAMILY_GRUBBIN
#if P_FAMILY_CRABRAWLER
    [SPECIES_CRABRAWLER] = sCrabrawlerLevelUpLearnset,
    [SPECIES_CRABOMINABLE] = sCrabominableLevelUpLearnset,
    [SPECIES_CRABOMINABLE_MEGA] = sCrabominableLevelUpLearnset,
#endif // P_FAMILY_CRABRAWLER
#if P_FAMILY_ORICORIO
    [SPECIES_ORICORIO_BAILE] = sOricorioLevelUpLearnset,
    [SPECIES_ORICORIO_POM_POM] = sOricorioLevelUpLearnset,
    [SPECIES_ORICORIO_PAU] = sOricorioLevelUpLearnset,
    [SPECIES_ORICORIO_SENSU] = sOricorioLevelUpLearnset,
#endif // P_FAMILY_ORICORIO
#if P_FAMILY_CUTIEFLY
    [SPECIES_CUTIEFLY] = sCutieflyLevelUpLearnset,
    [SPECIES_RIBOMBEE] = sRibombeeLevelUpLearnset,
    [SPECIES_RIBOMBEE_TOTEM] = sRibombeeLevelUpLearnset,
#endif // P_FAMILY_CUTIEFLY
#if P_FAMILY_ROCKRUFF
    [SPECIES_ROCKRUFF] = sRockruffLevelUpLearnset,
    [SPECIES_ROCKRUFF_OWN_TEMPO] = sRockruffLevelUpLearnset,
    [SPECIES_LYCANROC_MIDDAY] = sLycanrocMiddayLevelUpLearnset,
    [SPECIES_LYCANROC_MIDNIGHT] = sLycanrocMidnightLevelUpLearnset,
    [SPECIES_LYCANROC_DUSK] = sLycanrocDuskLevelUpLearnset,
#endif // P_FAMILY_ROCKRUFF
#if P_FAMILY_WISHIWASHI
    [SPECIES_WISHIWASHI_SOLO] = sWishiwashiLevelUpLearnset,
    [SPECIES_WISHIWASHI_SCHOOL] = sWishiwashiLevelUpLearnset,
#endif // P_FAMILY_WISHIWASHI
#if P_FAMILY_MAREANIE
    [SPECIES_MAREANIE] = sMareanieLevelUpLearnset,
    [SPECIES_TOXAPEX] = sToxapexLevelUpLearnset,
#endif // P_FAMILY_MAREANIE
#if P_FAMILY_MUDBRAY
    [SPECIES_MUDBRAY] = sMudbrayLevelUpLearnset,
    [SPECIES_MUDSDALE] = sMudsdaleLevelUpLearnset,
#endif // P_FAMILY_MUDBRAY
#if P_FAMILY_DEWPIDER
    [SPECIES_DEWPIDER] = sDewpiderLevelUpLearnset,
    [SPECIES_ARAQUANID] = sAraquanidLevelUpLearnset,
    [SPECIES_ARAQUANID_TOTEM] = sAraquanidLevelUpLearnset,
#endif // P_FAMILY_DEWPIDER
#if P_FAMILY_FOMANTIS
    [SPECIES_FOMANTIS] = sFomantisLevelUpLearnset,
    [SPECIES_LURANTIS] = sLurantisLevelUpLearnset,
    [SPECIES_LURANTIS_TOTEM] = sLurantisLevelUpLearnset,
#endif // P_FAMILY_FOMANTIS
#if P_FAMILY_MORELULL
    [SPECIES_MORELULL] = sMorelullLevelUpLearnset,
    [SPECIES_SHIINOTIC] = sShiinoticLevelUpLearnset,
#endif // P_FAMILY_MORELULL
#if P_FAMILY_SALANDIT
    [SPECIES_SALANDIT] = sSalanditLevelUpLearnset,
    [SPECIES_SALAZZLE] = sSalazzleLevelUpLearnset,
    [SPECIES_SALAZZLE_TOTEM] = sSalazzleLevelUpLearnset,
#endif // P_FAMILY_SALANDIT
#if P_FAMILY_STUFFUL
    [SPECIES_STUFFUL] = sStuffulLevelUpLearnset,
    [SPECIES_BEWEAR] = sBewearLevelUpLearnset,
#endif // P_FAMILY_STUFFUL
#if P_FAMILY_BOUNSWEET
    [SPECIES_BOUNSWEET] = sBounsweetLevelUpLearnset,
    [SPECIES_STEENEE] = sSteeneeLevelUpLearnset,
    [SPECIES_TSAREENA] = sTsareenaLevelUpLearnset,
#endif // P_FAMILY_BOUNSWEET
#if P_FAMILY_COMFEY
    [SPECIES_COMFEY] = sComfeyLevelUpLearnset,
#endif // P_FAMILY_COMFEY
#if P_FAMILY_ORANGURU
    [SPECIES_ORANGURU] = sOranguruLevelUpLearnset,
#endif // P_FAMILY_ORANGURU
#if P_FAMILY_PASSIMIAN
    [SPECIES_PASSIMIAN] = sPassimianLevelUpLearnset,
#endif // P_FAMILY_PASSIMIAN
#if P_FAMILY_WIMPOD
    [SPECIES_WIMPOD] = sWimpodLevelUpLearnset,
    [SPECIES_GOLISOPOD] = sGolisopodLevelUpLearnset,
    [SPECIES_GOLISOPOD_MEGA] = sGolisopodLevelUpLearnset,
#endif // P_FAMILY_WIMPOD
#if P_FAMILY_SANDYGAST
    [SPECIES_SANDYGAST] = sSandygastLevelUpLearnset,
    [SPECIES_PALOSSAND] = sPalossandLevelUpLearnset,
#endif // P_FAMILY_SANDYGAST
#if P_FAMILY_PYUKUMUKU
    [SPECIES_PYUKUMUKU] = sPyukumukuLevelUpLearnset,
#endif // P_FAMILY_PYUKUMUKU
#if P_FAMILY_TYPE_NULL
    [SPECIES_TYPE_NULL] = sTypeNullLevelUpLearnset,
#endif // P_FAMILY_TYPE_NULL
#if P_FAMILY_MINIOR
    [SPECIES_SILVALLY_FAIRY] = sMiniorLevelUpLearnset,
#endif // P_FAMILY_MINIOR
#if P_FAMILY_KOMALA
    [SPECIES_KOMALA] = sKomalaLevelUpLearnset,
#endif // P_FAMILY_KOMALA
#if P_FAMILY_TURTONATOR
    [SPECIES_TURTONATOR] = sTurtonatorLevelUpLearnset,
#endif // P_FAMILY_TURTONATOR
#if P_FAMILY_TOGEDEMARU
    [SPECIES_TOGEDEMARU] = sTogedemaruLevelUpLearnset,
    [SPECIES_TOGEDEMARU_TOTEM] = sTogedemaruLevelUpLearnset,
#endif // P_FAMILY_TOGEDEMARU
#if P_FAMILY_MIMIKYU
    [SPECIES_MIMIKYU_DISGUISED] = sMimikyuLevelUpLearnset,
    [SPECIES_MIMIKYU_BUSTED] = sMimikyuLevelUpLearnset,
    [SPECIES_MIMIKYU_TOTEM_DISGUISED] = sMimikyuLevelUpLearnset,
    [SPECIES_MIMIKYU_BUSTED_TOTEM] = sMimikyuLevelUpLearnset,
#endif // P_FAMILY_MIMIKYU
#if P_FAMILY_BRUXISH
    [SPECIES_BRUXISH] = sBruxishLevelUpLearnset,
#endif // P_FAMILY_BRUXISH
#if P_FAMILY_DRAMPA
    [SPECIES_DRAMPA] = sDrampaLevelUpLearnset,
    [SPECIES_DRAMPA_MEGA] = sDrampaLevelUpLearnset,
#endif // P_FAMILY_DRAMPA
#if P_FAMILY_DHELMISE
    [SPECIES_DHELMISE] = sDhelmiseLevelUpLearnset,
#endif // P_FAMILY_DHELMISE
#if P_FAMILY_JANGMO_O
    [SPECIES_JANGMO_O] = sJangmoOLevelUpLearnset,
    [SPECIES_HAKAMO_O] = sHakamoOLevelUpLearnset,
    [SPECIES_KOMMO_O] = sKommoOLevelUpLearnset,
    [SPECIES_KOMMO_O_TOTEM] = sKommoOLevelUpLearnset,
#endif // P_FAMILY_JANGMO_O
#if P_FAMILY_TAPU_KOKO
    [SPECIES_TAPU_KOKO] = sTapuKokoLevelUpLearnset,
#endif // P_FAMILY_TAPU_KOKO
#if P_FAMILY_TAPU_LELE
    [SPECIES_TAPU_LELE] = sTapuLeleLevelUpLearnset,
#endif // P_FAMILY_TAPU_LELE
#if P_FAMILY_TAPU_BULU
    [SPECIES_TAPU_BULU] = sTapuBuluLevelUpLearnset,
#endif // P_FAMILY_TAPU_BULU
#if P_FAMILY_TAPU_FINI
    [SPECIES_TAPU_FINI] = sTapuFiniLevelUpLearnset,
#endif // P_FAMILY_TAPU_FINI
#if P_FAMILY_COSMOG
    [SPECIES_COSMOG] = sCosmogLevelUpLearnset,
    [SPECIES_COSMOEM] = sCosmoemLevelUpLearnset,
    [SPECIES_SOLGALEO] = sSolgaleoLevelUpLearnset,
    [SPECIES_LUNALA] = sLunalaLevelUpLearnset,
#endif // P_FAMILY_COSMOG
#if P_FAMILY_NIHILEGO
    [SPECIES_NIHILEGO] = sNihilegoLevelUpLearnset,
#endif // P_FAMILY_NIHILEGO
#if P_FAMILY_BUZZWOLE
    [SPECIES_BUZZWOLE] = sBuzzwoleLevelUpLearnset,
#endif // P_FAMILY_BUZZWOLE
#if P_FAMILY_PHEROMOSA
    [SPECIES_PHEROMOSA] = sPheromosaLevelUpLearnset,
#endif // P_FAMILY_PHEROMOSA
#if P_FAMILY_XURKITREE
    [SPECIES_XURKITREE] = sXurkitreeLevelUpLearnset,
#endif // P_FAMILY_XURKITREE
#if P_FAMILY_CELESTEELA
    [SPECIES_CELESTEELA] = sCelesteelaLevelUpLearnset,
#endif // P_FAMILY_CELESTEELA
#if P_FAMILY_KARTANA
    [SPECIES_KARTANA] = sKartanaLevelUpLearnset,
#endif // P_FAMILY_KARTANA
#if P_FAMILY_GUZZLORD
    [SPECIES_GUZZLORD] = sGuzzlordLevelUpLearnset,
#endif // P_FAMILY_GUZZLORD
#if P_FAMILY_NECROZMA
    [SPECIES_NECROZMA] = sNecrozmaLevelUpLearnset,
    [SPECIES_NECROZMA_DUSK_MANE] = sNecrozmaLevelUpLearnset,
    [SPECIES_NECROZMA_DAWN_WINGS] = sNecrozmaLevelUpLearnset,
    [SPECIES_NECROZMA_ULTRA] = sNecrozmaLevelUpLearnset,
#endif // P_FAMILY_NECROZMA
#if P_FAMILY_MAGEARNA
    [SPECIES_MAGEARNA] = sMagearnaLevelUpLearnset,
    [SPECIES_MAGEARNA_ORIGINAL] = sMagearnaLevelUpLearnset,
    [SPECIES_MAGEARNA_MEGA] = sMagearnaLevelUpLearnset,
    [SPECIES_MAGEARNA_ORIGINAL_MEGA] = sMagearnaLevelUpLearnset,
#endif // P_FAMILY_MAGEARNA
#if P_FAMILY_MARSHADOW
    [SPECIES_MARSHADOW] = sMarshadowLevelUpLearnset,
#endif // P_FAMILY_MARSHADOW
#if P_FAMILY_POIPOLE
    [SPECIES_POIPOLE] = sPoipoleLevelUpLearnset,
    [SPECIES_NAGANADEL] = sNaganadelLevelUpLearnset,
#endif // P_FAMILY_POIPOLE
#if P_FAMILY_STAKATAKA
    [SPECIES_STAKATAKA] = sStakatakaLevelUpLearnset,
#endif // P_FAMILY_STAKATAKA
#if P_FAMILY_BLACEPHALON
    [SPECIES_BLACEPHALON] = sBlacephalonLevelUpLearnset,
#endif // P_FAMILY_BLACEPHALON
#if P_FAMILY_ZERAORA
    [SPECIES_ZERAORA] = sZeraoraLevelUpLearnset,
    [SPECIES_ZERAORA_MEGA] = sZeraoraLevelUpLearnset,
#endif // P_FAMILY_ZERAORA
#if P_FAMILY_MELTAN
    [SPECIES_MELTAN] = sMeltanLevelUpLearnset,
    [SPECIES_MELMETAL] = sMelmetalLevelUpLearnset,
    [SPECIES_MELMETAL_GMAX] = sMelmetalLevelUpLearnset,
#endif // P_FAMILY_MELTAN
#if P_FAMILY_GROOKEY
    [SPECIES_GROOKEY] = sGrookeyLevelUpLearnset,
    [SPECIES_THWACKEY] = sThwackeyLevelUpLearnset,
    [SPECIES_RILLABOOM] = sRillaboomLevelUpLearnset,
    [SPECIES_RILLABOOM_GMAX] = sRillaboomLevelUpLearnset,
#endif // P_FAMILY_GROOKEY
#if P_FAMILY_SCORBUNNY
    [SPECIES_SCORBUNNY] = sScorbunnyLevelUpLearnset,
    [SPECIES_RABOOT] = sRabootLevelUpLearnset,
    [SPECIES_CINDERACE] = sCinderaceLevelUpLearnset,
    [SPECIES_CINDERACE_GMAX] = sCinderaceLevelUpLearnset,
#endif // P_FAMILY_SCORBUNNY
#if P_FAMILY_SOBBLE
    [SPECIES_SOBBLE] = sSobbleLevelUpLearnset,
    [SPECIES_DRIZZILE] = sDrizzileLevelUpLearnset,
    [SPECIES_INTELEON] = sInteleonLevelUpLearnset,
    [SPECIES_INTELEON_GMAX] = sInteleonLevelUpLearnset,
#endif // P_FAMILY_SOBBLE
#if P_FAMILY_SKWOVET
    [SPECIES_SKWOVET] = sSkwovetLevelUpLearnset,
    [SPECIES_GREEDENT] = sGreedentLevelUpLearnset,
#endif // P_FAMILY_SKWOVET
#if P_FAMILY_ROOKIDEE
    [SPECIES_ROOKIDEE] = sRookideeLevelUpLearnset,
    [SPECIES_CORVISQUIRE] = sCorvisquireLevelUpLearnset,
    [SPECIES_CORVIKNIGHT] = sCorviknightLevelUpLearnset,
    [SPECIES_CORVIKNIGHT_GMAX] = sCorviknightLevelUpLearnset,
#endif // P_FAMILY_ROOKIDEE
#if P_FAMILY_BLIPBUG
    [SPECIES_BLIPBUG] = sBlipbugLevelUpLearnset,
    [SPECIES_DOTTLER] = sDottlerLevelUpLearnset,
    [SPECIES_ORBEETLE] = sOrbeetleLevelUpLearnset,
    [SPECIES_ORBEETLE_GMAX] = sOrbeetleLevelUpLearnset,
#endif // P_FAMILY_BLIPBUG
#if P_FAMILY_NICKIT
    [SPECIES_NICKIT] = sNickitLevelUpLearnset,
    [SPECIES_THIEVUL] = sThievulLevelUpLearnset,
#endif // P_FAMILY_NICKIT
#if P_FAMILY_GOSSIFLEUR
    [SPECIES_GOSSIFLEUR] = sGossifleurLevelUpLearnset,
    [SPECIES_ELDEGOSS] = sEldegossLevelUpLearnset,
#endif // P_FAMILY_GOSSIFLEUR
#if P_FAMILY_WOOLOO
    [SPECIES_WOOLOO] = sWoolooLevelUpLearnset,
    [SPECIES_DUBWOOL] = sDubwoolLevelUpLearnset,
#endif // P_FAMILY_WOOLOO
#if P_FAMILY_CHEWTLE
    [SPECIES_CHEWTLE] = sChewtleLevelUpLearnset,
    [SPECIES_DREDNAW] = sDrednawLevelUpLearnset,
    [SPECIES_DREDNAW_GMAX] = sDrednawLevelUpLearnset,
#endif // P_FAMILY_CHEWTLE
#if P_FAMILY_YAMPER
    [SPECIES_YAMPER] = sYamperLevelUpLearnset,
    [SPECIES_BOLTUND] = sBoltundLevelUpLearnset,
#endif // P_FAMILY_YAMPER
#if P_FAMILY_ROLYCOLY
    [SPECIES_ROLYCOLY] = sRolycolyLevelUpLearnset,
    [SPECIES_CARKOL] = sCarkolLevelUpLearnset,
    [SPECIES_COALOSSAL] = sCoalossalLevelUpLearnset,
    [SPECIES_COALOSSAL_GMAX] = sCoalossalLevelUpLearnset,
#endif // P_FAMILY_ROLYCOLY
#if P_FAMILY_APPLIN
    [SPECIES_APPLIN] = sApplinLevelUpLearnset,
    [SPECIES_FLAPPLE] = sFlappleLevelUpLearnset,
    [SPECIES_FLAPPLE_GMAX] = sFlappleLevelUpLearnset,
    [SPECIES_APPLETUN] = sAppletunLevelUpLearnset,
    [SPECIES_APPLETUN_GMAX] = sAppletunLevelUpLearnset,
    [SPECIES_DIPPLIN] = sDipplinLevelUpLearnset,
    [SPECIES_HYDRAPPLE] = sHydrappleLevelUpLearnset,
#endif // P_FAMILY_APPLIN
#if P_FAMILY_SILICOBRA
    [SPECIES_SILICOBRA] = sSilicobraLevelUpLearnset,
    [SPECIES_SANDACONDA] = sSandacondaLevelUpLearnset,
    [SPECIES_SANDACONDA_GMAX] = sSandacondaLevelUpLearnset,
#endif // P_FAMILY_SILICOBRA
#if P_FAMILY_CRAMORANT
    [SPECIES_CRAMORANT] = sCramorantLevelUpLearnset,
    [SPECIES_CRAMORANT_GULPING] = sCramorantLevelUpLearnset,
    [SPECIES_CRAMORANT_GORGING] = sCramorantLevelUpLearnset,
#endif // P_FAMILY_CRAMORANT
#if P_FAMILY_ARROKUDA
    [SPECIES_ARROKUDA] = sArrokudaLevelUpLearnset,
    [SPECIES_BARRASKEWDA] = sBarraskewdaLevelUpLearnset,
#endif // P_FAMILY_ARROKUDA
#if P_FAMILY_TOXEL
    [SPECIES_TOXEL] = sToxelLevelUpLearnset,
    [SPECIES_TOXTRICITY_AMPED] = sToxtricityAmpedLevelUpLearnset,
    [SPECIES_TOXTRICITY_AMPED_GMAX] = sToxtricityAmpedLevelUpLearnset,
    [SPECIES_TOXTRICITY_LOW_KEY] = sToxtricityLowKeyLevelUpLearnset,
    [SPECIES_TOXTRICITY_LOW_KEY_GMAX] = sToxtricityLowKeyLevelUpLearnset,
#endif // P_FAMILY_TOXEL
#if P_FAMILY_SIZZLIPEDE
    [SPECIES_SIZZLIPEDE] = sSizzlipedeLevelUpLearnset,
    [SPECIES_CENTISKORCH] = sCentiskorchLevelUpLearnset,
    [SPECIES_CENTISKORCH_GMAX] = sCentiskorchLevelUpLearnset,
#endif // P_FAMILY_SIZZLIPEDE
#if P_FAMILY_CLOBBOPUS
    [SPECIES_CLOBBOPUS] = sClobbopusLevelUpLearnset,
    [SPECIES_GRAPPLOCT] = sGrapploctLevelUpLearnset,
#endif // P_FAMILY_CLOBBOPUS
#if P_FAMILY_SINISTEA
    [SPECIES_SINISTEA_PHONY] = sSinisteaLevelUpLearnset,
    [SPECIES_SINISTEA_ANTIQUE] = sSinisteaLevelUpLearnset,
    [SPECIES_POLTEAGEIST_PHONY] = sPolteageistLevelUpLearnset,
    [SPECIES_POLTEAGEIST_ANTIQUE] = sPolteageistLevelUpLearnset,
#endif // P_FAMILY_SINISTEA
#if P_FAMILY_HATENNA
    [SPECIES_HATENNA] = sHatennaLevelUpLearnset,
    [SPECIES_HATTREM] = sHattremLevelUpLearnset,
    [SPECIES_HATTERENE] = sHattereneLevelUpLearnset,
    [SPECIES_HATTERENE_GMAX] = sHattereneLevelUpLearnset,
#endif // P_FAMILY_HATENNA
#if P_FAMILY_IMPIDIMP
    [SPECIES_IMPIDIMP] = sImpidimpLevelUpLearnset,
    [SPECIES_MORGREM] = sMorgremLevelUpLearnset,
    [SPECIES_GRIMMSNARL] = sGrimmsnarlLevelUpLearnset,
    [SPECIES_GRIMMSNARL_GMAX] = sGrimmsnarlLevelUpLearnset,
#endif // P_FAMILY_IMPIDIMP
#if P_FAMILY_MILCERY
    [SPECIES_MILCERY] = sMilceryLevelUpLearnset,
    [SPECIES_ALCREMIE_GMAX] = sAlcremieLevelUpLearnset,
#endif // P_FAMILY_MILCERY
#if P_FAMILY_FALINKS
    [SPECIES_FALINKS] = sFalinksLevelUpLearnset,
    [SPECIES_FALINKS_MEGA] = sFalinksLevelUpLearnset,
#endif // P_FAMILY_FALINKS
#if P_FAMILY_PINCURCHIN
    [SPECIES_PINCURCHIN] = sPincurchinLevelUpLearnset,
#endif // P_FAMILY_PINCURCHIN
#if P_FAMILY_SNOM
    [SPECIES_SNOM] = sSnomLevelUpLearnset,
    [SPECIES_FROSMOTH] = sFrosmothLevelUpLearnset,
#endif // P_FAMILY_SNOM
#if P_FAMILY_STONJOURNER
    [SPECIES_STONJOURNER] = sStonjournerLevelUpLearnset,
#endif // P_FAMILY_STONJOURNER
#if P_FAMILY_EISCUE
    [SPECIES_EISCUE_ICE] = sEiscueLevelUpLearnset,
    [SPECIES_EISCUE_NOICE] = sEiscueLevelUpLearnset,
#endif // P_FAMILY_EISCUE
#if P_FAMILY_INDEEDEE
    [SPECIES_INDEEDEE_M] = sIndeedeeMLevelUpLearnset,
    [SPECIES_INDEEDEE_F] = sIndeedeeFLevelUpLearnset,
#endif // P_FAMILY_INDEEDEE
#if P_FAMILY_MORPEKO
    [SPECIES_MORPEKO_FULL_BELLY] = sMorpekoLevelUpLearnset,
    [SPECIES_MORPEKO_HANGRY] = sMorpekoLevelUpLearnset,
#endif // P_FAMILY_MORPEKO
#if P_FAMILY_CUFANT
    [SPECIES_CUFANT] = sCufantLevelUpLearnset,
    [SPECIES_COPPERAJAH] = sCopperajahLevelUpLearnset,
    [SPECIES_COPPERAJAH_GMAX] = sCopperajahLevelUpLearnset,
#endif // P_FAMILY_CUFANT
#if P_FAMILY_DRACOZOLT
    [SPECIES_DRACOZOLT] = sDracozoltLevelUpLearnset,
#endif // P_FAMILY_DRACOZOLT
#if P_FAMILY_ARCTOZOLT
    [SPECIES_ARCTOZOLT] = sArctozoltLevelUpLearnset,
#endif // P_FAMILY_ARCTOZOLT
#if P_FAMILY_DRACOVISH
    [SPECIES_DRACOVISH] = sDracovishLevelUpLearnset,
#endif // P_FAMILY_DRACOVISH
#if P_FAMILY_ARCTOVISH
    [SPECIES_ARCTOVISH] = sArctovishLevelUpLearnset,
#endif // P_FAMILY_ARCTOVISH
#if P_FAMILY_DURALUDON
    [SPECIES_DURALUDON] = sDuraludonLevelUpLearnset,
    [SPECIES_DURALUDON_GMAX] = sDuraludonLevelUpLearnset,
    [SPECIES_ARCHALUDON] = sArchaludonLevelUpLearnset,
#endif // P_FAMILY_DURALUDON
#if P_FAMILY_DREEPY
    [SPECIES_DREEPY] = sDreepyLevelUpLearnset,
    [SPECIES_DRAKLOAK] = sDrakloakLevelUpLearnset,
    [SPECIES_DRAGAPULT] = sDragapultLevelUpLearnset,
#endif // P_FAMILY_DREEPY
#if P_FAMILY_ZACIAN
    [SPECIES_ZACIAN_HERO] = sZacianLevelUpLearnset,
    [SPECIES_ZACIAN_CROWNED] = sZacianLevelUpLearnset,
#endif // P_FAMILY_ZACIAN
#if P_FAMILY_ZAMAZENTA
    [SPECIES_ZAMAZENTA_HERO] = sZamazentaLevelUpLearnset,
    [SPECIES_ZAMAZENTA_CROWNED] = sZamazentaLevelUpLearnset,
#endif // P_FAMILY_ZAMAZENTA
#if P_FAMILY_ETERNATUS
    [SPECIES_ETERNATUS] = sEternatusLevelUpLearnset,
    [SPECIES_ETERNATUS_ETERNAMAX] = sEternatusLevelUpLearnset,
#endif // P_FAMILY_ETERNATUS
#if P_FAMILY_KUBFU
    [SPECIES_KUBFU] = sKubfuLevelUpLearnset,
    [SPECIES_URSHIFU_SINGLE_STRIKE] = sUrshifuSingleStrikeLevelUpLearnset,
    [SPECIES_URSHIFU_SINGLE_STRIKE_GMAX] = sUrshifuSingleStrikeLevelUpLearnset,
    [SPECIES_URSHIFU_RAPID_STRIKE] = sUrshifuRapidStrikeLevelUpLearnset,
    [SPECIES_URSHIFU_RAPID_STRIKE_GMAX] = sUrshifuRapidStrikeLevelUpLearnset,
#endif // P_FAMILY_KUBFU
#if P_FAMILY_ZARUDE
    [SPECIES_ZARUDE] = sZarudeLevelUpLearnset,
    [SPECIES_ZARUDE_DADA] = sZarudeLevelUpLearnset,
#endif // P_FAMILY_ZARUDE
#if P_FAMILY_REGIELEKI
    [SPECIES_REGIELEKI] = sRegielekiLevelUpLearnset,
#endif // P_FAMILY_REGIELEKI
#if P_FAMILY_REGIDRAGO
    [SPECIES_REGIDRAGO] = sRegidragoLevelUpLearnset,
#endif // P_FAMILY_REGIDRAGO
#if P_FAMILY_GLASTRIER
    [SPECIES_GLASTRIER] = sGlastrierLevelUpLearnset,
#endif // P_FAMILY_GLASTRIER
#if P_FAMILY_SPECTRIER
    [SPECIES_SPECTRIER] = sSpectrierLevelUpLearnset,
#endif // P_FAMILY_SPECTRIER
#if P_FAMILY_CALYREX
    [SPECIES_CALYREX] = sCalyrexLevelUpLearnset,
    [SPECIES_CALYREX_ICE] = sCalyrexIceLevelUpLearnset,
    [SPECIES_CALYREX_SHADOW] = sCalyrexShadowLevelUpLearnset,
#endif // P_FAMILY_CALYREX
#if P_FAMILY_ENAMORUS
    [SPECIES_ENAMORUS_INCARNATE] = sEnamorusLevelUpLearnset,
    [SPECIES_ENAMORUS_THERIAN] = sEnamorusLevelUpLearnset,
#endif // P_FAMILY_ENAMORUS
#if P_FAMILY_SPRIGATITO
    [SPECIES_SPRIGATITO] = sSprigatitoLevelUpLearnset,
    [SPECIES_FLORAGATO] = sFloragatoLevelUpLearnset,
    [SPECIES_MEOWSCARADA] = sMeowscaradaLevelUpLearnset,
#endif // P_FAMILY_SPRIGATITO
#if P_FAMILY_FUECOCO
    [SPECIES_FUECOCO] = sFuecocoLevelUpLearnset,
    [SPECIES_CROCALOR] = sCrocalorLevelUpLearnset,
    [SPECIES_SKELEDIRGE] = sSkeledirgeLevelUpLearnset,
#endif // P_FAMILY_FUECOCO
#if P_FAMILY_QUAXLY
    [SPECIES_QUAXLY] = sQuaxlyLevelUpLearnset,
    [SPECIES_QUAXWELL] = sQuaxwellLevelUpLearnset,
    [SPECIES_QUAQUAVAL] = sQuaquavalLevelUpLearnset,
#endif // P_FAMILY_QUAXLY
#if P_FAMILY_LECHONK
    [SPECIES_LECHONK] = sLechonkLevelUpLearnset,
    [SPECIES_OINKOLOGNE_M] = sOinkologneMLevelUpLearnset,
    [SPECIES_OINKOLOGNE_F] = sOinkologneFLevelUpLearnset,
#endif // P_FAMILY_LECHONK
#if P_FAMILY_TAROUNTULA
    [SPECIES_TAROUNTULA] = sTarountulaLevelUpLearnset,
    [SPECIES_SPIDOPS] = sSpidopsLevelUpLearnset,
#endif // P_FAMILY_TAROUNTULA
#if P_FAMILY_NYMBLE
    [SPECIES_NYMBLE] = sNymbleLevelUpLearnset,
    [SPECIES_LOKIX] = sLokixLevelUpLearnset,
#endif // P_FAMILY_NYMBLE
#if P_FAMILY_PAWMI
    [SPECIES_PAWMI] = sPawmiLevelUpLearnset,
    [SPECIES_PAWMO] = sPawmoLevelUpLearnset,
    [SPECIES_PAWMOT] = sPawmotLevelUpLearnset,
#endif // P_FAMILY_PAWMI
#if P_FAMILY_TANDEMAUS
    [SPECIES_TANDEMAUS] = sTandemausLevelUpLearnset,
    [SPECIES_MAUSHOLD_THREE] = sMausholdLevelUpLearnset,
    [SPECIES_MAUSHOLD_FOUR] = sMausholdLevelUpLearnset,
#endif // P_FAMILY_TANDEMAUS
#if P_FAMILY_FIDOUGH
    [SPECIES_FIDOUGH] = sFidoughLevelUpLearnset,
    [SPECIES_DACHSBUN] = sDachsbunLevelUpLearnset,
#endif // P_FAMILY_FIDOUGH
#if P_FAMILY_SMOLIV
    [SPECIES_SMOLIV] = sSmolivLevelUpLearnset,
    [SPECIES_DOLLIV] = sDollivLevelUpLearnset,
    [SPECIES_ARBOLIVA] = sArbolivaLevelUpLearnset,
#endif // P_FAMILY_SMOLIV
#if P_FAMILY_SQUAWKABILLY
    [SPECIES_SQUAWKABILLY_GREEN] = sSquawkabillyLevelUpLearnset,
    [SPECIES_SQUAWKABILLY_BLUE] = sSquawkabillyLevelUpLearnset,
    [SPECIES_SQUAWKABILLY_YELLOW] = sSquawkabillyLevelUpLearnset,
    [SPECIES_SQUAWKABILLY_WHITE] = sSquawkabillyLevelUpLearnset,
#endif // P_FAMILY_SQUAWKABILLY
#if P_FAMILY_NACLI
    [SPECIES_NACLI] = sNacliLevelUpLearnset,
    [SPECIES_NACLSTACK] = sNaclstackLevelUpLearnset,
    [SPECIES_GARGANACL] = sGarganaclLevelUpLearnset,
#endif // P_FAMILY_NACLI
#if P_FAMILY_CHARCADET
    [SPECIES_CHARCADET] = sCharcadetLevelUpLearnset,
    [SPECIES_ARMAROUGE] = sArmarougeLevelUpLearnset,
    [SPECIES_CERULEDGE] = sCeruledgeLevelUpLearnset,
#endif // P_FAMILY_CHARCADET
#if P_FAMILY_TADBULB
    [SPECIES_TADBULB] = sTadbulbLevelUpLearnset,
    [SPECIES_BELLIBOLT] = sBelliboltLevelUpLearnset,
#endif // P_FAMILY_TADBULB
#if P_FAMILY_WATTREL
    [SPECIES_WATTREL] = sWattrelLevelUpLearnset,
    [SPECIES_KILOWATTREL] = sKilowattrelLevelUpLearnset,
#endif // P_FAMILY_WATTREL
#if P_FAMILY_MASCHIFF
    [SPECIES_MASCHIFF] = sMaschiffLevelUpLearnset,
    [SPECIES_MABOSSTIFF] = sMabosstiffLevelUpLearnset,
#endif // P_FAMILY_MASCHIFF
#if P_FAMILY_SHROODLE
    [SPECIES_SHROODLE] = sShroodleLevelUpLearnset,
    [SPECIES_GRAFAIAI] = sGrafaiaiLevelUpLearnset,
#endif // P_FAMILY_SHROODLE
#if P_FAMILY_BRAMBLIN
    [SPECIES_BRAMBLIN] = sBramblinLevelUpLearnset,
    [SPECIES_BRAMBLEGHAST] = sBrambleghastLevelUpLearnset,
#endif // P_FAMILY_BRAMBLIN
#if P_FAMILY_TOEDSCOOL
    [SPECIES_TOEDSCOOL] = sToedscoolLevelUpLearnset,
    [SPECIES_TOEDSCRUEL] = sToedscruelLevelUpLearnset,
#endif // P_FAMILY_TOEDSCOOL
#if P_FAMILY_KLAWF
    [SPECIES_KLAWF] = sKlawfLevelUpLearnset,
#endif // P_FAMILY_KLAWF
#if P_FAMILY_CAPSAKID
    [SPECIES_CAPSAKID] = sCapsakidLevelUpLearnset,
    [SPECIES_SCOVILLAIN] = sScovillainLevelUpLearnset,
    [SPECIES_SCOVILLAIN_MEGA] = sScovillainLevelUpLearnset,
#endif // P_FAMILY_CAPSAKID
#if P_FAMILY_RELLOR
    [SPECIES_RELLOR] = sRellorLevelUpLearnset,
    [SPECIES_RABSCA] = sRabscaLevelUpLearnset,
#endif // P_FAMILY_RELLOR
#if P_FAMILY_FLITTLE
    [SPECIES_FLITTLE] = sFlittleLevelUpLearnset,
    [SPECIES_ESPATHRA] = sEspathraLevelUpLearnset,
#endif // P_FAMILY_FLITTLE
#if P_FAMILY_TINKATINK
    [SPECIES_TINKATINK] = sTinkatinkLevelUpLearnset,
    [SPECIES_TINKATUFF] = sTinkatuffLevelUpLearnset,
    [SPECIES_TINKATON] = sTinkatonLevelUpLearnset,
#endif // P_FAMILY_TINKATINK
#if P_FAMILY_WIGLETT
    [SPECIES_WIGLETT] = sWiglettLevelUpLearnset,
    [SPECIES_WUGTRIO] = sWugtrioLevelUpLearnset,
#endif // P_FAMILY_WIGLETT
#if P_FAMILY_BOMBIRDIER
    [SPECIES_BOMBIRDIER] = sBombirdierLevelUpLearnset,
#endif // P_FAMILY_BOMBIRDIER
#if P_FAMILY_FINIZEN
    [SPECIES_FINIZEN] = sFinizenLevelUpLearnset,
    [SPECIES_PALAFIN_ZERO] = sPalafinLevelUpLearnset,
    [SPECIES_PALAFIN_HERO] = sPalafinLevelUpLearnset,
#endif // P_FAMILY_FINIZEN
#if P_FAMILY_VAROOM
    [SPECIES_VAROOM] = sVaroomLevelUpLearnset,
    [SPECIES_REVAVROOM] = sRevavroomLevelUpLearnset,
#endif // P_FAMILY_VAROOM
#if P_FAMILY_CYCLIZAR
    [SPECIES_CYCLIZAR] = sCyclizarLevelUpLearnset,
#endif // P_FAMILY_CYCLIZAR
#if P_FAMILY_ORTHWORM
    [SPECIES_ORTHWORM] = sOrthwormLevelUpLearnset,
#endif // P_FAMILY_ORTHWORM
#if P_FAMILY_GLIMMET
    [SPECIES_GLIMMET] = sGlimmetLevelUpLearnset,
    [SPECIES_GLIMMORA] = sGlimmoraLevelUpLearnset,
    [SPECIES_GLIMMORA_MEGA] = sGlimmoraLevelUpLearnset,
#endif // P_FAMILY_GLIMMET
#if P_FAMILY_GREAVARD
    [SPECIES_GREAVARD] = sGreavardLevelUpLearnset,
    [SPECIES_HOUNDSTONE] = sHoundstoneLevelUpLearnset,
#endif // P_FAMILY_GREAVARD
#if P_FAMILY_FLAMIGO
    [SPECIES_FLAMIGO] = sFlamigoLevelUpLearnset,
#endif // P_FAMILY_FLAMIGO
#if P_FAMILY_CETODDLE
    [SPECIES_CETODDLE] = sCetoddleLevelUpLearnset,
    [SPECIES_CETITAN] = sCetitanLevelUpLearnset,
#endif // P_FAMILY_CETODDLE
#if P_FAMILY_VELUZA
    [SPECIES_VELUZA] = sVeluzaLevelUpLearnset,
#endif // P_FAMILY_VELUZA
#if P_FAMILY_DONDOZO
    [SPECIES_DONDOZO] = sDondozoLevelUpLearnset,
#endif // P_FAMILY_DONDOZO
#if P_FAMILY_TATSUGIRI
    [SPECIES_TATSUGIRI_CURLY] = sTatsugiriLevelUpLearnset,
    [SPECIES_TATSUGIRI_DROOPY] = sTatsugiriLevelUpLearnset,
    [SPECIES_TATSUGIRI_STRETCHY] = sTatsugiriLevelUpLearnset,
    [SPECIES_TATSUGIRI_CURLY_MEGA] = sTatsugiriLevelUpLearnset,
    [SPECIES_TATSUGIRI_DROOPY_MEGA] = sTatsugiriLevelUpLearnset,
    [SPECIES_TATSUGIRI_STRETCHY_MEGA] = sTatsugiriLevelUpLearnset,
#endif // P_FAMILY_TATSUGIRI
#if P_FAMILY_GREAT_TUSK
    [SPECIES_GREAT_TUSK] = sGreatTuskLevelUpLearnset,
#endif // P_FAMILY_GREAT_TUSK
#if P_FAMILY_SCREAM_TAIL
    [SPECIES_SCREAM_TAIL] = sScreamTailLevelUpLearnset,
#endif // P_FAMILY_SCREAM_TAIL
#if P_FAMILY_BRUTE_BONNET
    [SPECIES_BRUTE_BONNET] = sBruteBonnetLevelUpLearnset,
#endif // P_FAMILY_BRUTE_BONNET
#if P_FAMILY_FLUTTER_MANE
    [SPECIES_FLUTTER_MANE] = sFlutterManeLevelUpLearnset,
#endif // P_FAMILY_FLUTTER_MANE
#if P_FAMILY_SLITHER_WING
    [SPECIES_SLITHER_WING] = sSlitherWingLevelUpLearnset,
#endif // P_FAMILY_SLITHER_WING
#if P_FAMILY_SANDY_SHOCKS
    [SPECIES_SANDY_SHOCKS] = sSandyShocksLevelUpLearnset,
#endif // P_FAMILY_SANDY_SHOCKS
#if P_FAMILY_IRON_TREADS
    [SPECIES_IRON_TREADS] = sIronTreadsLevelUpLearnset,
#endif // P_FAMILY_IRON_TREADS
#if P_FAMILY_IRON_BUNDLE
    [SPECIES_IRON_BUNDLE] = sIronBundleLevelUpLearnset,
#endif // P_FAMILY_IRON_BUNDLE
#if P_FAMILY_IRON_HANDS
    [SPECIES_IRON_HANDS] = sIronHandsLevelUpLearnset,
#endif // P_FAMILY_IRON_HANDS
#if P_FAMILY_IRON_JUGULIS
    [SPECIES_IRON_JUGULIS] = sIronJugulisLevelUpLearnset,
#endif // P_FAMILY_IRON_JUGULIS
#if P_FAMILY_IRON_MOTH
    [SPECIES_IRON_MOTH] = sIronMothLevelUpLearnset,
#endif // P_FAMILY_IRON_MOTH
#if P_FAMILY_IRON_THORNS
    [SPECIES_IRON_THORNS] = sIronThornsLevelUpLearnset,
#endif // P_FAMILY_IRON_THORNS
#if P_FAMILY_FRIGIBAX
    [SPECIES_FRIGIBAX] = sFrigibaxLevelUpLearnset,
    [SPECIES_ARCTIBAX] = sArctibaxLevelUpLearnset,
    [SPECIES_BAXCALIBUR] = sBaxcaliburLevelUpLearnset,
    [SPECIES_BAXCALIBUR_MEGA] = sBaxcaliburLevelUpLearnset,
#endif // P_FAMILY_FRIGIBAX
#if P_FAMILY_GIMMIGHOUL
    [SPECIES_GIMMIGHOUL_CHEST] = sGimmighoulLevelUpLearnset,
    [SPECIES_GIMMIGHOUL_ROAMING] = sGimmighoulLevelUpLearnset,
    [SPECIES_GHOLDENGO] = sGholdengoLevelUpLearnset,
#endif // P_FAMILY_GIMMIGHOUL
#if P_FAMILY_WO_CHIEN
    [SPECIES_WO_CHIEN] = sWoChienLevelUpLearnset,
#endif // P_FAMILY_WO_CHIEN
#if P_FAMILY_CHIEN_PAO
    [SPECIES_CHIEN_PAO] = sChienPaoLevelUpLearnset,
#endif // P_FAMILY_CHIEN_PAO
#if P_FAMILY_TING_LU
    [SPECIES_TING_LU] = sTingLuLevelUpLearnset,
#endif // P_FAMILY_TING_LU
#if P_FAMILY_CHI_YU
    [SPECIES_CHI_YU] = sChiYuLevelUpLearnset,
#endif // P_FAMILY_CHI_YU
#if P_FAMILY_ROARING_MOON
    [SPECIES_ROARING_MOON] = sRoaringMoonLevelUpLearnset,
#endif // P_FAMILY_ROARING_MOON
#if P_FAMILY_IRON_VALIANT
    [SPECIES_IRON_VALIANT] = sIronValiantLevelUpLearnset,
#endif // P_FAMILY_IRON_VALIANT
#if P_FAMILY_KORAIDON
    [SPECIES_KORAIDON] = sKoraidonLevelUpLearnset,
#endif // P_FAMILY_KORAIDON
#if P_FAMILY_MIRAIDON
    [SPECIES_MIRAIDON] = sMiraidonLevelUpLearnset,
#endif // P_FAMILY_MIRAIDON
#if P_FAMILY_WALKING_WAKE
    [SPECIES_WALKING_WAKE] = sWalkingWakeLevelUpLearnset,
#endif // P_FAMILY_WALKING_WAKE
#if P_FAMILY_IRON_LEAVES
    [SPECIES_IRON_LEAVES] = sIronLeavesLevelUpLearnset,
#endif // P_FAMILY_IRON_LEAVES
#if P_FAMILY_POLTCHAGEIST
    [SPECIES_POLTCHAGEIST_COUNTERFEIT] = sPoltchageistLevelUpLearnset,
    [SPECIES_POLTCHAGEIST_ARTISAN] = sPoltchageistLevelUpLearnset,
    [SPECIES_SINISTCHA_UNREMARKABLE] = sSinistchaLevelUpLearnset,
    [SPECIES_SINISTCHA_MASTERPIECE] = sSinistchaLevelUpLearnset,
#endif // P_FAMILY_POLTCHAGEIST
#if P_FAMILY_OKIDOGI
    [SPECIES_OKIDOGI] = sOkidogiLevelUpLearnset,
#endif // P_FAMILY_OKIDOGI
#if P_FAMILY_MUNKIDORI
    [SPECIES_MUNKIDORI] = sMunkidoriLevelUpLearnset,
#endif // P_FAMILY_MUNKIDORI
#if P_FAMILY_FEZANDIPITI
    [SPECIES_FEZANDIPITI] = sFezandipitiLevelUpLearnset,
#endif // P_FAMILY_FEZANDIPITI
#if P_FAMILY_GOUGING_FIRE
    [SPECIES_GOUGING_FIRE] = sGougingFireLevelUpLearnset,
#endif // P_FAMILY_GOUGING_FIRE
#if P_FAMILY_RAGING_BOLT
    [SPECIES_RAGING_BOLT] = sRagingBoltLevelUpLearnset,
#endif // P_FAMILY_RAGING_BOLT
#if P_FAMILY_IRON_BOULDER
    [SPECIES_IRON_BOULDER] = sIronBoulderLevelUpLearnset,
#endif // P_FAMILY_IRON_BOULDER
#if P_FAMILY_IRON_CROWN
    [SPECIES_IRON_CROWN] = sIronCrownLevelUpLearnset,
#endif // P_FAMILY_IRON_CROWN
#if P_FAMILY_TERAPAGOS
    [SPECIES_TERAPAGOS_NORMAL] = sTerapagosLevelUpLearnset,
    [SPECIES_TERAPAGOS_TERASTAL] = sTerapagosLevelUpLearnset,
    [SPECIES_TERAPAGOS_STELLAR] = sTerapagosLevelUpLearnset,
#endif // P_FAMILY_TERAPAGOS
#if P_FAMILY_PECHARUNT
    [SPECIES_PECHARUNT] = sPecharuntLevelUpLearnset,
#endif // P_FAMILY_PECHARUNT
};
