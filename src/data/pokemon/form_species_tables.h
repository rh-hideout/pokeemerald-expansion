#if P_FAMILY_BULBASAUR
static const enum Species sVenusaurFormSpeciesIdTable[] = {
    SPECIES_VENUSAUR,
#if P_MEGA_EVOLUTIONS
    SPECIES_VENUSAUR_MEGA,
#endif
#if P_GIGANTAMAX_FORMS
    SPECIES_VENUSAUR_GMAX,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_BULBASAUR

#if P_FAMILY_CHARMANDER
static const enum Species sCharizardFormSpeciesIdTable[] = {
    SPECIES_CHARIZARD,
#if P_MEGA_EVOLUTIONS
    SPECIES_CHARIZARD_MEGA_X,
    SPECIES_CHARIZARD_MEGA_Y,
#endif
#if P_GIGANTAMAX_FORMS
    SPECIES_CHARIZARD_GMAX,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_CHARMANDER

#if P_FAMILY_SQUIRTLE
static const enum Species sBlastoiseFormSpeciesIdTable[] = {
    SPECIES_BLASTOISE,
#if P_MEGA_EVOLUTIONS
    SPECIES_BLASTOISE_MEGA,
#endif
#if P_GIGANTAMAX_FORMS
    SPECIES_BLASTOISE_GMAX,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_SQUIRTLE

#if P_FAMILY_CATERPIE
static const enum Species sButterfreeFormSpeciesIdTable[] = {
    SPECIES_BUTTERFREE,
#if P_GIGANTAMAX_FORMS
    SPECIES_BUTTERFREE_GMAX,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_CATERPIE

#if P_FAMILY_WEEDLE
static const enum Species sBeedrillFormSpeciesIdTable[] = {
    SPECIES_BEEDRILL,
#if P_MEGA_EVOLUTIONS
    SPECIES_BEEDRILL_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_WEEDLE

#if P_FAMILY_PIDGEY
static const enum Species sPidgeotFormSpeciesIdTable[] = {
    SPECIES_PIDGEOT,
#if P_MEGA_EVOLUTIONS
    SPECIES_PIDGEOT_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_PIDGEY

#if P_FAMILY_RATTATA
static const enum Species sRattataFormSpeciesIdTable[] = {
    SPECIES_RATTATA,
#if P_ALOLAN_FORMS
    SPECIES_RATTATA_ALOLA,
#endif
    FORM_SPECIES_END,
};

static const enum Species sRaticateFormSpeciesIdTable[] = {
    SPECIES_RATICATE,
#if P_ALOLAN_FORMS
    SPECIES_RATICATE_ALOLA,
    SPECIES_RATICATE_ALOLA_TOTEM,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_RATTATA

#if P_FAMILY_PIKACHU
#if P_GEN_2_CROSS_EVOS
static const enum Species sPichuFormSpeciesIdTable[] = {
    SPECIES_PICHU,
    SPECIES_PICHU_SPIKY_EARED,
    FORM_SPECIES_END,
};
#endif //P_GEN_2_CROSS_EVOS

static const enum Species sPikachuFormSpeciesIdTable[] = {
    SPECIES_PIKACHU,
#if P_COSPLAY_PIKACHU_FORMS
    SPECIES_PIKACHU_COSPLAY,
    SPECIES_PIKACHU_ROCK_STAR,
    SPECIES_PIKACHU_BELLE,
    SPECIES_PIKACHU_POP_STAR,
    SPECIES_PIKACHU_PHD,
    SPECIES_PIKACHU_LIBRE,
#endif
#if P_CAP_PIKACHU_FORMS
    SPECIES_PIKACHU_ORIGINAL,
    SPECIES_PIKACHU_HOENN,
    SPECIES_PIKACHU_SINNOH,
    SPECIES_PIKACHU_UNOVA,
    SPECIES_PIKACHU_KALOS,
    SPECIES_PIKACHU_ALOLA,
    SPECIES_PIKACHU_PARTNER,
    SPECIES_PIKACHU_WORLD,
#endif
#if P_GIGANTAMAX_FORMS
    SPECIES_PIKACHU_GMAX,
#endif
    SPECIES_PIKACHU_STARTER,
    FORM_SPECIES_END,
};

static const enum Species sRaichuFormSpeciesIdTable[] = {
    SPECIES_RAICHU,
#if P_ALOLAN_FORMS
    SPECIES_RAICHU_ALOLA,
#endif
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_RAICHU_MEGA_X,
    SPECIES_RAICHU_MEGA_Y,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_PIKACHU

#if P_FAMILY_SANDSHREW
static const enum Species sSandshrewFormSpeciesIdTable[] = {
    SPECIES_SANDSHREW,
#if P_ALOLAN_FORMS
    SPECIES_SANDSHREW_ALOLA,
#endif
    FORM_SPECIES_END,
};

static const enum Species sSandslashFormSpeciesIdTable[] = {
    SPECIES_SANDSLASH,
#if P_ALOLAN_FORMS
    SPECIES_SANDSLASH_ALOLA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_SANDSHREW

#if P_FAMILY_CLEFAIRY
static const enum Species sClefableFormSpeciesIdTable[] = {
    SPECIES_CLEFABLE,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_CLEFABLE_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_CLEFAIRY

#if P_FAMILY_VULPIX
static const enum Species sVulpixFormSpeciesIdTable[] = {
    SPECIES_VULPIX,
#if P_ALOLAN_FORMS
    SPECIES_VULPIX_ALOLA,
#endif
    FORM_SPECIES_END,
};

static const enum Species sNinetalesFormSpeciesIdTable[] = {
    SPECIES_NINETALES,
#if P_ALOLAN_FORMS
    SPECIES_NINETALES_ALOLA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_VULPIX

#if P_FAMILY_DIGLETT
static const enum Species sDiglettFormSpeciesIdTable[] = {
    SPECIES_DIGLETT,
#if P_ALOLAN_FORMS
    SPECIES_DIGLETT_ALOLA,
#endif
    FORM_SPECIES_END,
};

static const enum Species sDugtrioFormSpeciesIdTable[] = {
    SPECIES_DUGTRIO,
#if P_ALOLAN_FORMS
    SPECIES_DUGTRIO_ALOLA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_DIGLETT

#if P_FAMILY_MEOWTH
static const enum Species sMeowthFormSpeciesIdTable[] = {
    SPECIES_MEOWTH,
#if P_ALOLAN_FORMS
    SPECIES_MEOWTH_ALOLA,
#endif
#if P_GALARIAN_FORMS
    SPECIES_MEOWTH_GALAR,
#endif
#if P_GIGANTAMAX_FORMS
    SPECIES_MEOWTH_GMAX,
#endif
    FORM_SPECIES_END,
};

static const enum Species sPersianFormSpeciesIdTable[] = {
    SPECIES_PERSIAN,
#if P_ALOLAN_FORMS
    SPECIES_PERSIAN_ALOLA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_MEOWTH

#if P_FAMILY_GROWLITHE
static const enum Species sGrowlitheFormSpeciesIdTable[] = {
    SPECIES_GROWLITHE,
#if P_HISUIAN_FORMS
    SPECIES_GROWLITHE_HISUI,
#endif
    FORM_SPECIES_END,
};

static const enum Species sArcanineFormSpeciesIdTable[] = {
    SPECIES_ARCANINE,
#if P_HISUIAN_FORMS
    SPECIES_ARCANINE_HISUI,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_GROWLITHE

#if P_FAMILY_ABRA
static const enum Species sAlakazamFormSpeciesIdTable[] = {
    SPECIES_ALAKAZAM,
#if P_MEGA_EVOLUTIONS
    SPECIES_ALAKAZAM_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_ABRA

#if P_FAMILY_MACHOP
static const enum Species sMachampFormSpeciesIdTable[] = {
    SPECIES_MACHAMP,
#if P_GIGANTAMAX_FORMS
    SPECIES_MACHAMP_GMAX,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_MACHOP

#if P_FAMILY_BELLSPROUT
static const enum Species sVictreebelFormSpeciesIdTable[] = {
    SPECIES_VICTREEBEL,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_VICTREEBEL_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_BELLSPROUT

#if P_FAMILY_GEODUDE
static const enum Species sGeodudeFormSpeciesIdTable[] = {
    SPECIES_GEODUDE,
#if P_ALOLAN_FORMS
    SPECIES_GEODUDE_ALOLA,
#endif
    FORM_SPECIES_END,
};

static const enum Species sGravelerFormSpeciesIdTable[] = {
    SPECIES_GRAVELER,
#if P_ALOLAN_FORMS
    SPECIES_GRAVELER_ALOLA,
#endif
    FORM_SPECIES_END,
};

static const enum Species sGolemFormSpeciesIdTable[] = {
    SPECIES_GOLEM,
#if P_ALOLAN_FORMS
    SPECIES_GOLEM_ALOLA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_GEODUDE

#if P_FAMILY_PONYTA
static const enum Species sPonytaFormSpeciesIdTable[] = {
    SPECIES_PONYTA,
#if P_GALARIAN_FORMS
    SPECIES_PONYTA_GALAR,
#endif
    FORM_SPECIES_END,
};

static const enum Species sRapidashFormSpeciesIdTable[] = {
    SPECIES_RAPIDASH,
#if P_GALARIAN_FORMS
    SPECIES_RAPIDASH_GALAR,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_PONYTA

#if P_FAMILY_SLOWPOKE
static const enum Species sSlowpokeFormSpeciesIdTable[] = {
    SPECIES_SLOWPOKE,
#if P_GALARIAN_FORMS
    SPECIES_SLOWPOKE_GALAR,
#endif
    FORM_SPECIES_END,
};

static const enum Species sSlowbroFormSpeciesIdTable[] = {
    SPECIES_SLOWBRO,
#if P_MEGA_EVOLUTIONS
    SPECIES_SLOWBRO_MEGA,
#endif
#if P_GALARIAN_FORMS
    SPECIES_SLOWBRO_GALAR,
#endif
    FORM_SPECIES_END,
};

#if P_GEN_2_CROSS_EVOS
static const enum Species sSlowkingFormSpeciesIdTable[] = {
    SPECIES_SLOWKING,
#if P_GALARIAN_FORMS
    SPECIES_SLOWKING_GALAR,
#endif
    FORM_SPECIES_END,
};
#endif //P_GEN_2_CROSS_EVOS
#endif //P_FAMILY_SLOWPOKE

#if P_FAMILY_FARFETCHD
static const enum Species sFarfetchdFormSpeciesIdTable[] = {
    SPECIES_FARFETCHD,
#if P_GALARIAN_FORMS
    SPECIES_FARFETCHD_GALAR,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_FARFETCHD

#if P_FAMILY_GRIMER
static const enum Species sGrimerFormSpeciesIdTable[] = {
    SPECIES_GRIMER,
#if P_ALOLAN_FORMS
    SPECIES_GRIMER_ALOLA,
#endif
    FORM_SPECIES_END,
};

static const enum Species sMukFormSpeciesIdTable[] = {
    SPECIES_MUK,
#if P_ALOLAN_FORMS
    SPECIES_MUK_ALOLA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_GRIMER

#if P_FAMILY_GASTLY
static const enum Species sGengarFormSpeciesIdTable[] = {
    SPECIES_GENGAR,
#if P_MEGA_EVOLUTIONS
    SPECIES_GENGAR_MEGA,
#endif
#if P_GIGANTAMAX_FORMS
    SPECIES_GENGAR_GMAX,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_GASTLY

#if P_FAMILY_ONIX
#if P_GEN_2_CROSS_EVOS
static const enum Species sSteelixFormSpeciesIdTable[] = {
    SPECIES_STEELIX,
#if P_MEGA_EVOLUTIONS
    SPECIES_STEELIX_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_GEN_2_CROSS_EVOS
#endif //P_FAMILY_ONIX

#if P_FAMILY_KRABBY
static const enum Species sKinglerFormSpeciesIdTable[] = {
    SPECIES_KINGLER,
#if P_GIGANTAMAX_FORMS
    SPECIES_KINGLER_GMAX,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_KRABBY

#if P_FAMILY_VOLTORB
static const enum Species sVoltorbFormSpeciesIdTable[] = {
    SPECIES_VOLTORB,
#if P_HISUIAN_FORMS
    SPECIES_VOLTORB_HISUI,
#endif
    FORM_SPECIES_END,
};

static const enum Species sElectrodeFormSpeciesIdTable[] = {
    SPECIES_ELECTRODE,
#if P_HISUIAN_FORMS
    SPECIES_ELECTRODE_HISUI,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_VOLTORB

#if P_FAMILY_EXEGGCUTE
static const enum Species sExeggutorFormSpeciesIdTable[] = {
    SPECIES_EXEGGUTOR,
#if P_ALOLAN_FORMS
    SPECIES_EXEGGUTOR_ALOLA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_EXEGGCUTE

#if P_FAMILY_CUBONE
static const enum Species sMarowakFormSpeciesIdTable[] = {
    SPECIES_MAROWAK,
#if P_ALOLAN_FORMS
    SPECIES_MAROWAK_ALOLA,
    SPECIES_MAROWAK_ALOLA_TOTEM,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_CUBONE

#if P_FAMILY_KOFFING
static const enum Species sWeezingFormSpeciesIdTable[] = {
    SPECIES_WEEZING,
#if P_GALARIAN_FORMS
    SPECIES_WEEZING_GALAR,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_KOFFING

#if P_FAMILY_KANGASKHAN
static const enum Species sKangaskhanFormSpeciesIdTable[] = {
    SPECIES_KANGASKHAN,
#if P_MEGA_EVOLUTIONS
    SPECIES_KANGASKHAN_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_KANGASKHAN

#if P_FAMILY_STARYU
static const enum Species sStarmieFormSpeciesIdTable[] = {
    SPECIES_STARMIE,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_STARMIE_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_STARYU

#if P_FAMILY_MR_MIME
static const enum Species sMrMimeFormSpeciesIdTable[] = {
    SPECIES_MR_MIME,
#if P_GALARIAN_FORMS
    SPECIES_MR_MIME_GALAR,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_MR_MIME

#if P_FAMILY_SCYTHER
#if P_GEN_2_CROSS_EVOS
static const enum Species sScizorFormSpeciesIdTable[] = {
    SPECIES_SCIZOR,
#if P_MEGA_EVOLUTIONS
    SPECIES_SCIZOR_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_GEN_2_CROSS_EVOS
#endif //P_FAMILY_SCYTHER

#if P_FAMILY_PINSIR
static const enum Species sPinsirFormSpeciesIdTable[] = {
    SPECIES_PINSIR,
#if P_MEGA_EVOLUTIONS
    SPECIES_PINSIR_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_PINSIR

#if P_FAMILY_TAUROS
static const enum Species sTaurosFormSpeciesIdTable[] = {
    SPECIES_TAUROS,
#if P_PALDEAN_FORMS
    SPECIES_TAUROS_PALDEA_COMBAT,
    SPECIES_TAUROS_PALDEA_BLAZE,
    SPECIES_TAUROS_PALDEA_AQUA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_TAUROS

#if P_FAMILY_MAGIKARP
static const enum Species sGyaradosFormSpeciesIdTable[] = {
    SPECIES_GYARADOS,
#if P_MEGA_EVOLUTIONS
    SPECIES_GYARADOS_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_MAGIKARP

#if P_FAMILY_LAPRAS
static const enum Species sLaprasFormSpeciesIdTable[] = {
    SPECIES_LAPRAS,
#if P_GIGANTAMAX_FORMS
    SPECIES_LAPRAS_GMAX,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_LAPRAS

#if P_FAMILY_EEVEE
static const enum Species sEeveeFormSpeciesIdTable[] = {
    SPECIES_EEVEE,
#if P_GIGANTAMAX_FORMS
    SPECIES_EEVEE_GMAX,
#endif
    SPECIES_EEVEE_STARTER,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_EEVEE

#if P_FAMILY_AERODACTYL
static const enum Species sAerodactylFormSpeciesIdTable[] = {
    SPECIES_AERODACTYL,
#if P_MEGA_EVOLUTIONS
    SPECIES_AERODACTYL_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_AERODACTYL

#if P_FAMILY_SNORLAX
static const enum Species sSnorlaxFormSpeciesIdTable[] = {
    SPECIES_SNORLAX,
#if P_GIGANTAMAX_FORMS
    SPECIES_SNORLAX_GMAX,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_SNORLAX

#if P_FAMILY_ARTICUNO
static const enum Species sArticunoFormSpeciesIdTable[] = {
    SPECIES_ARTICUNO,
#if P_GALARIAN_FORMS
    SPECIES_ARTICUNO_GALAR,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_ARTICUNO

#if P_FAMILY_ZAPDOS
static const enum Species sZapdosFormSpeciesIdTable[] = {
    SPECIES_ZAPDOS,
#if P_GALARIAN_FORMS
    SPECIES_ZAPDOS_GALAR,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_ZAPDOS

#if P_FAMILY_MOLTRES
static const enum Species sMoltresFormSpeciesIdTable[] = {
    SPECIES_MOLTRES,
#if P_GALARIAN_FORMS
    SPECIES_MOLTRES_GALAR,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_MOLTRES

#if P_FAMILY_DRATINI
static const enum Species sDragoniteFormSpeciesIdTable[] = {
    SPECIES_DRAGONITE,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_DRAGONITE_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_DRATINI

#if P_FAMILY_MEWTWO
static const enum Species sMewtwoFormSpeciesIdTable[] = {
    SPECIES_MEWTWO,
#if P_MEGA_EVOLUTIONS
    SPECIES_MEWTWO_MEGA_X,
    SPECIES_MEWTWO_MEGA_Y,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_MEWTWO

#if P_FAMILY_CHIKORITA
static const enum Species sMeganiumFormSpeciesIdTable[] = {
    SPECIES_MEGANIUM,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_MEGANIUM_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_CHIKORITA

#if P_FAMILY_CYNDAQUIL
static const enum Species sTyphlosionFormSpeciesIdTable[] = {
    SPECIES_TYPHLOSION,
#if P_HISUIAN_FORMS
    SPECIES_TYPHLOSION_HISUI,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_CYNDAQUIL

#if P_FAMILY_TOTODILE
static const enum Species sFeraligatrFormSpeciesIdTable[] = {
    SPECIES_FERALIGATR,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_FERALIGATR_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_TOTODILE

#if P_FAMILY_MAREEP
static const enum Species sAmpharosFormSpeciesIdTable[] = {
    SPECIES_AMPHAROS,
#if P_MEGA_EVOLUTIONS
    SPECIES_AMPHAROS_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_MAREEP

#if P_FAMILY_WOOPER
static const enum Species sWooperFormSpeciesIdTable[] = {
    SPECIES_WOOPER,
#if P_PALDEAN_FORMS
    SPECIES_WOOPER_PALDEA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_WOOPER

#if P_FAMILY_UNOWN
static const enum Species sUnownFormSpeciesIdTable[] = {
    SPECIES_UNOWN,
    SPECIES_UNOWN_B,
    SPECIES_UNOWN_C,
    SPECIES_UNOWN_D,
    SPECIES_UNOWN_E,
    SPECIES_UNOWN_F,
    SPECIES_UNOWN_G,
    SPECIES_UNOWN_H,
    SPECIES_UNOWN_I,
    SPECIES_UNOWN_J,
    SPECIES_UNOWN_K,
    SPECIES_UNOWN_L,
    SPECIES_UNOWN_M,
    SPECIES_UNOWN_N,
    SPECIES_UNOWN_O,
    SPECIES_UNOWN_P,
    SPECIES_UNOWN_Q,
    SPECIES_UNOWN_R,
    SPECIES_UNOWN_S,
    SPECIES_UNOWN_T,
    SPECIES_UNOWN_U,
    SPECIES_UNOWN_V,
    SPECIES_UNOWN_W,
    SPECIES_UNOWN_X,
    SPECIES_UNOWN_Y,
    SPECIES_UNOWN_Z,
    SPECIES_UNOWN_EXCLAMATION,
    SPECIES_UNOWN_QUESTION,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_UNOWN

#if P_FAMILY_DUNSPARCE
static const enum Species sDudunsparceFormSpeciesIdTable[] = {
    SPECIES_DUDUNSPARCE_TWO_SEGMENT,
    SPECIES_DUDUNSPARCE_THREE_SEGMENT,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_DUNSPARCE

#if P_FAMILY_QWILFISH
static const enum Species sQwilfishFormSpeciesIdTable[] = {
    SPECIES_QWILFISH,
#if P_HISUIAN_FORMS
    SPECIES_QWILFISH_HISUI,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_QWILFISH

#if P_FAMILY_HERACROSS
static const enum Species sHeracrossFormSpeciesIdTable[] = {
    SPECIES_HERACROSS,
#if P_MEGA_EVOLUTIONS
    SPECIES_HERACROSS_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_HERACROSS

#if P_FAMILY_SNEASEL
static const enum Species sSneaselFormSpeciesIdTable[] = {
    SPECIES_SNEASEL,
#if P_HISUIAN_FORMS
    SPECIES_SNEASEL_HISUI,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_SNEASEL

#if P_FAMILY_TEDDIURSA
static const enum Species sUrsalunaFormSpeciesIdTable[] = {
    SPECIES_URSALUNA,
    SPECIES_URSALUNA_BLOODMOON,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_TEDDIURSA

#if P_FAMILY_CORSOLA
static const enum Species sCorsolaFormSpeciesIdTable[] = {
    SPECIES_CORSOLA,
#if P_GALARIAN_FORMS
    SPECIES_CORSOLA_GALAR,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_CORSOLA

#if P_FAMILY_SKARMORY
static const enum Species sSkarmoryFormSpeciesIdTable[] = {
    SPECIES_SKARMORY,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_SKARMORY_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_SKARMORY

#if P_FAMILY_HOUNDOUR
static const enum Species sHoundoomFormSpeciesIdTable[] = {
    SPECIES_HOUNDOOM,
#if P_MEGA_EVOLUTIONS
    SPECIES_HOUNDOOM_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_HOUNDOUR

#if P_FAMILY_LARVITAR
static const enum Species sTyranitarFormSpeciesIdTable[] = {
    SPECIES_TYRANITAR,
#if P_MEGA_EVOLUTIONS
    SPECIES_TYRANITAR_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_LARVITAR

#if P_FAMILY_TREECKO
static const enum Species sSceptileFormSpeciesIdTable[] = {
    SPECIES_SCEPTILE,
#if P_MEGA_EVOLUTIONS
    SPECIES_SCEPTILE_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_TREECKO

#if P_FAMILY_TORCHIC
static const enum Species sBlazikenFormSpeciesIdTable[] = {
    SPECIES_BLAZIKEN,
#if P_MEGA_EVOLUTIONS
    SPECIES_BLAZIKEN_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_TORCHIC

#if P_FAMILY_MUDKIP
static const enum Species sSwampertFormSpeciesIdTable[] = {
    SPECIES_SWAMPERT,
#if P_MEGA_EVOLUTIONS
    SPECIES_SWAMPERT_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_MUDKIP

#if P_FAMILY_ZIGZAGOON
static const enum Species sZigzagoonFormSpeciesIdTable[] = {
    SPECIES_ZIGZAGOON,
#if P_GALARIAN_FORMS
    SPECIES_ZIGZAGOON_GALAR,
#endif
    FORM_SPECIES_END,
};

static const enum Species sLinooneFormSpeciesIdTable[] = {
    SPECIES_LINOONE,
#if P_GALARIAN_FORMS
    SPECIES_LINOONE_GALAR,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_ZIGZAGOON

#if P_FAMILY_RALTS
static const enum Species sGardevoirFormSpeciesIdTable[] = {
    SPECIES_GARDEVOIR,
#if P_MEGA_EVOLUTIONS
    SPECIES_GARDEVOIR_MEGA,
#endif
    FORM_SPECIES_END,
};

#if P_GEN_4_CROSS_EVOS
static const enum Species sGalladeFormSpeciesIdTable[] = {
    SPECIES_GALLADE,
#if P_MEGA_EVOLUTIONS
    SPECIES_GALLADE_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_RALTS

#if P_FAMILY_SABLEYE
static const enum Species sSableyeFormSpeciesIdTable[] = {
    SPECIES_SABLEYE,
#if P_MEGA_EVOLUTIONS
    SPECIES_SABLEYE_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_SABLEYE

#if P_FAMILY_MAWILE
static const enum Species sMawileFormSpeciesIdTable[] = {
    SPECIES_MAWILE,
#if P_MEGA_EVOLUTIONS
    SPECIES_MAWILE_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_MAWILE

#if P_FAMILY_ARON
static const enum Species sAggronFormSpeciesIdTable[] = {
    SPECIES_AGGRON,
#if P_MEGA_EVOLUTIONS
    SPECIES_AGGRON_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_ARON

#if P_FAMILY_MEDITITE
static const enum Species sMedichamFormSpeciesIdTable[] = {
    SPECIES_MEDICHAM,
#if P_MEGA_EVOLUTIONS
    SPECIES_MEDICHAM_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_MEDITITE

#if P_FAMILY_ELECTRIKE
static const enum Species sManectricFormSpeciesIdTable[] = {
    SPECIES_MANECTRIC,
#if P_MEGA_EVOLUTIONS
    SPECIES_MANECTRIC_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_ELECTRIKE

#if P_FAMILY_CARVANHA
static const enum Species sSharpedoFormSpeciesIdTable[] = {
    SPECIES_SHARPEDO,
#if P_MEGA_EVOLUTIONS
    SPECIES_SHARPEDO_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_CARVANHA

#if P_FAMILY_NUMEL
static const enum Species sCameruptFormSpeciesIdTable[] = {
    SPECIES_CAMERUPT,
#if P_MEGA_EVOLUTIONS
    SPECIES_CAMERUPT_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_NUMEL

#if P_FAMILY_SWABLU
static const enum Species sAltariaFormSpeciesIdTable[] = {
    SPECIES_ALTARIA,
#if P_MEGA_EVOLUTIONS
    SPECIES_ALTARIA_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_SWABLU

#if P_FAMILY_CASTFORM
static const enum Species sCastformFormSpeciesIdTable[] = {
    SPECIES_CASTFORM_NORMAL,
    SPECIES_CASTFORM_SUNNY,
    SPECIES_CASTFORM_RAINY,
    SPECIES_CASTFORM_SNOWY,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_CASTFORM

#if P_FAMILY_SHUPPET
static const enum Species sBanetteFormSpeciesIdTable[] = {
    SPECIES_BANETTE,
#if P_MEGA_EVOLUTIONS
    SPECIES_BANETTE_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_SHUPPET

#if P_FAMILY_CHIMECHO
static const enum Species sChimechoFormSpeciesIdTable[] = {
    SPECIES_CHIMECHO,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_CHIMECHO_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_CHIMECHO

#if P_FAMILY_ABSOL
static const enum Species sAbsolFormSpeciesIdTable[] = {
    SPECIES_ABSOL,
#if P_MEGA_EVOLUTIONS
    SPECIES_ABSOL_MEGA,
#endif
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_ABSOL_MEGA_Z,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_ABSOL

#if P_FAMILY_SNORUNT
static const enum Species sGlalieFormSpeciesIdTable[] = {
    SPECIES_GLALIE,
#if P_MEGA_EVOLUTIONS
    SPECIES_GLALIE_MEGA,
#endif
    FORM_SPECIES_END,
};

static const enum Species sFroslassFormSpeciesIdTable[] = {
    SPECIES_FROSLASS,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_FROSLASS_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_SNORUNT

#if P_FAMILY_BAGON
static const enum Species sSalamenceFormSpeciesIdTable[] = {
    SPECIES_SALAMENCE,
#if P_MEGA_EVOLUTIONS
    SPECIES_SALAMENCE_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_BAGON

#if P_FAMILY_BELDUM
static const enum Species sMetagrossFormSpeciesIdTable[] = {
    SPECIES_METAGROSS,
#if P_MEGA_EVOLUTIONS
    SPECIES_METAGROSS_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_BELDUM

#if P_FAMILY_LATIAS
static const enum Species sLatiasFormSpeciesIdTable[] = {
    SPECIES_LATIAS,
#if P_MEGA_EVOLUTIONS
    SPECIES_LATIAS_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_LATIAS

#if P_FAMILY_LATIOS
static const enum Species sLatiosFormSpeciesIdTable[] = {
    SPECIES_LATIOS,
#if P_MEGA_EVOLUTIONS
    SPECIES_LATIOS_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_LATIOS

#if P_FAMILY_KYOGRE
static const enum Species sKyogreFormSpeciesIdTable[] = {
    SPECIES_KYOGRE,
#if P_PRIMAL_REVERSIONS
    SPECIES_KYOGRE_PRIMAL,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_KYOGRE

#if P_FAMILY_GROUDON
static const enum Species sGroudonFormSpeciesIdTable[] = {
    SPECIES_GROUDON,
#if P_PRIMAL_REVERSIONS
    SPECIES_GROUDON_PRIMAL,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_GROUDON

#if P_FAMILY_RAYQUAZA
static const enum Species sRayquazaFormSpeciesIdTable[] = {
    SPECIES_RAYQUAZA,
#if P_MEGA_EVOLUTIONS
    SPECIES_RAYQUAZA_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_RAYQUAZA

#if P_FAMILY_DEOXYS
static const enum Species sDeoxysFormSpeciesIdTable[] = {
    SPECIES_DEOXYS_NORMAL,
    SPECIES_DEOXYS_ATTACK,
    SPECIES_DEOXYS_DEFENSE,
    SPECIES_DEOXYS_SPEED,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_DEOXYS

#if P_FAMILY_STARLY
static const enum Species sStaraptorFormSpeciesIdTable[] = {
    SPECIES_STARAPTOR,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_STARAPTOR_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_STARLY

#if P_FAMILY_BURMY
static const enum Species sBurmyFormSpeciesIdTable[] = {
    SPECIES_BURMY_PLANT,
    SPECIES_BURMY_SANDY,
    SPECIES_BURMY_TRASH,
    FORM_SPECIES_END,
};

static const enum Species sWormadamFormSpeciesIdTable[] = {
    SPECIES_WORMADAM_PLANT,
    SPECIES_WORMADAM_SANDY,
    SPECIES_WORMADAM_TRASH,
    FORM_SPECIES_END,
};

static const enum Species sMothimFormSpeciesIdTable[] = {
    SPECIES_MOTHIM_PLANT,
    SPECIES_MOTHIM_SANDY,
    SPECIES_MOTHIM_TRASH,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_BURMY

#if P_FAMILY_CHERUBI
static const enum Species sCherrimFormSpeciesIdTable[] = {
    SPECIES_CHERRIM_OVERCAST,
    SPECIES_CHERRIM_SUNSHINE,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_CHERUBI

#if P_FAMILY_SHELLOS
static const enum Species sShellosFormSpeciesIdTable[] = {
    SPECIES_SHELLOS_WEST,
    SPECIES_SHELLOS_EAST,
    FORM_SPECIES_END,
};

static const enum Species sGastrodonFormSpeciesIdTable[] = {
    SPECIES_GASTRODON_WEST,
    SPECIES_GASTRODON_EAST,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_SHELLOS

#if P_FAMILY_BUNEARY
static const enum Species sLopunnyFormSpeciesIdTable[] = {
    SPECIES_LOPUNNY,
#if P_MEGA_EVOLUTIONS
    SPECIES_LOPUNNY_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_BUNEARY

#if P_FAMILY_GIBLE
static const enum Species sGarchompFormSpeciesIdTable[] = {
    SPECIES_GARCHOMP,
#if P_MEGA_EVOLUTIONS
    SPECIES_GARCHOMP_MEGA,
#endif
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_GARCHOMP_MEGA_Z,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_GIBLE

#if P_FAMILY_RIOLU
static const enum Species sLucarioFormSpeciesIdTable[] = {
    SPECIES_LUCARIO,
#if P_MEGA_EVOLUTIONS
    SPECIES_LUCARIO_MEGA,
#endif
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_LUCARIO_MEGA_Z,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_RIOLU

#if P_FAMILY_SNOVER
static const enum Species sAbomasnowFormSpeciesIdTable[] = {
    SPECIES_ABOMASNOW,
#if P_MEGA_EVOLUTIONS
    SPECIES_ABOMASNOW_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_SNOVER

#if P_FAMILY_ROTOM
static const enum Species sRotomFormSpeciesIdTable[] = {
    SPECIES_ROTOM,
    SPECIES_ROTOM_HEAT,
    SPECIES_ROTOM_WASH,
    SPECIES_ROTOM_FROST,
    SPECIES_ROTOM_FAN,
    SPECIES_ROTOM_MOW,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_ROTOM

#if P_FAMILY_DIALGA
static const enum Species sDialgaFormSpeciesIdTable[] = {
    SPECIES_DIALGA,
    SPECIES_DIALGA_ORIGIN,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_DIALGA

#if P_FAMILY_PALKIA
static const enum Species sPalkiaFormSpeciesIdTable[] = {
    SPECIES_PALKIA,
    SPECIES_PALKIA_ORIGIN,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_PALKIA

#if P_FAMILY_HEATRAN
static const enum Species sHeatranFormSpeciesIdTable[] = {
    SPECIES_HEATRAN,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_HEATRAN_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_HEATRAN

#if P_FAMILY_GIRATINA
static const enum Species sGiratinaFormSpeciesIdTable[] = {
    SPECIES_GIRATINA_ALTERED,
    SPECIES_GIRATINA_ORIGIN,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_GIRATINA

#if P_FAMILY_DARKRAI
static const enum Species sDarkraiFormSpeciesIdTable[] = {
    SPECIES_DARKRAI,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_DARKRAI_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_DARKRAI

#if P_FAMILY_SHAYMIN
static const enum Species sShayminFormSpeciesIdTable[] = {
    SPECIES_SHAYMIN_LAND,
    SPECIES_SHAYMIN_SKY,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_SHAYMIN

#if P_FAMILY_ARCEUS
static const enum Species sArceusFormSpeciesIdTable[] = {
    SPECIES_ARCEUS_NORMAL,
    SPECIES_ARCEUS_FIGHTING,
    SPECIES_ARCEUS_FLYING,
    SPECIES_ARCEUS_POISON,
    SPECIES_ARCEUS_GROUND,
    SPECIES_ARCEUS_ROCK,
    SPECIES_ARCEUS_BUG,
    SPECIES_ARCEUS_GHOST,
    SPECIES_ARCEUS_STEEL,
    SPECIES_ARCEUS_FIRE,
    SPECIES_ARCEUS_WATER,
    SPECIES_ARCEUS_GRASS,
    SPECIES_ARCEUS_ELECTRIC,
    SPECIES_ARCEUS_PSYCHIC,
    SPECIES_ARCEUS_ICE,
    SPECIES_ARCEUS_DRAGON,
    SPECIES_ARCEUS_DARK,
    SPECIES_ARCEUS_FAIRY,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_ARCEUS

#if P_FAMILY_TEPIG
static const enum Species sEmboarFormSpeciesIdTable[] = {
    SPECIES_EMBOAR,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_EMBOAR_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_TEPIG

#if P_FAMILY_OSHAWOTT
static const enum Species sSamurottFormSpeciesIdTable[] = {
    SPECIES_SAMUROTT,
#if P_HISUIAN_FORMS
    SPECIES_SAMUROTT_HISUI,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_OSHAWOTT

#if P_FAMILY_DRILBUR
static const enum Species sExcadrillFormSpeciesIdTable[] = {
    SPECIES_EXCADRILL,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_EXCADRILL_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_DRILBUR

#if P_FAMILY_AUDINO
static const enum Species sAudinoFormSpeciesIdTable[] = {
    SPECIES_AUDINO,
#if P_MEGA_EVOLUTIONS
    SPECIES_AUDINO_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_AUDINO

#if P_FAMILY_VENIPEDE
static const enum Species sScolipedeFormSpeciesIdTable[] = {
    SPECIES_SCOLIPEDE,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_SCOLIPEDE_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_VENIPEDE

#if P_FAMILY_PETILIL
static const enum Species sLilligantFormSpeciesIdTable[] = {
    SPECIES_LILLIGANT,
#if P_HISUIAN_FORMS
    SPECIES_LILLIGANT_HISUI,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_PETILIL

#if P_FAMILY_BASCULIN
static const enum Species sBasculinFormSpeciesIdTable[] = {
    SPECIES_BASCULIN_RED_STRIPED,
    SPECIES_BASCULIN_BLUE_STRIPED,
    SPECIES_BASCULIN_WHITE_STRIPED,
    FORM_SPECIES_END,
};

static const enum Species sBasculegionFormSpeciesIdTable[] = {
    SPECIES_BASCULEGION_M,
    SPECIES_BASCULEGION_F,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_BASCULIN

#if P_FAMILY_DARUMAKA
static const enum Species sDarumakaFormSpeciesIdTable[] = {
    SPECIES_DARUMAKA,
#if P_GALARIAN_FORMS
    SPECIES_DARUMAKA_GALAR,
#endif
    FORM_SPECIES_END,
};

static const enum Species sDarmanitanFormSpeciesIdTable[] = {
    SPECIES_DARMANITAN_STANDARD,
    SPECIES_DARMANITAN_ZEN,
#if P_GALARIAN_FORMS
    SPECIES_DARMANITAN_GALAR_STANDARD,
    SPECIES_DARMANITAN_GALAR_ZEN,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_DARUMAKA

#if P_FAMILY_SCRAGGY
static const enum Species sScraftyFormSpeciesIdTable[] = {
    SPECIES_SCRAFTY,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_SCRAFTY_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_SCRAGGY

#if P_FAMILY_YAMASK
static const enum Species sYamaskFormSpeciesIdTable[] = {
    SPECIES_YAMASK,
#if P_GALARIAN_FORMS
    SPECIES_YAMASK_GALAR,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_YAMASK

#if P_FAMILY_TRUBBISH
static const enum Species sGarbodorFormSpeciesIdTable[] = {
    SPECIES_GARBODOR,
#if P_GIGANTAMAX_FORMS
    SPECIES_GARBODOR_GMAX,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_TRUBBISH

#if P_FAMILY_ZORUA
static const enum Species sZoruaFormSpeciesIdTable[] = {
    SPECIES_ZORUA,
#if P_HISUIAN_FORMS
    SPECIES_ZORUA_HISUI,
#endif
    FORM_SPECIES_END,
};

static const enum Species sZoroarkFormSpeciesIdTable[] = {
    SPECIES_ZOROARK,
#if P_HISUIAN_FORMS
    SPECIES_ZOROARK_HISUI,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_ZORUA

#if P_FAMILY_DEERLING
static const enum Species sDeerlingFormSpeciesIdTable[] = {
    SPECIES_DEERLING_SPRING,
    SPECIES_DEERLING_SUMMER,
    SPECIES_DEERLING_AUTUMN,
    SPECIES_DEERLING_WINTER,
    FORM_SPECIES_END,
};

static const enum Species sSawsbuckFormSpeciesIdTable[] = {
    SPECIES_SAWSBUCK_SPRING,
    SPECIES_SAWSBUCK_SUMMER,
    SPECIES_SAWSBUCK_AUTUMN,
    SPECIES_SAWSBUCK_WINTER,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_DEERLING

#if P_FAMILY_TYNAMO
static const enum Species sEelektrossFormSpeciesIdTable[] = {
    SPECIES_EELEKTROSS,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_EELEKTROSS_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_TYNAMO

#if P_FAMILY_LITWICK
static const enum Species sChandelureFormSpeciesIdTable[] = {
    SPECIES_CHANDELURE,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_CHANDELURE_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_LITWICK

#if P_FAMILY_GOLETT
static const enum Species sGolurkFormSpeciesIdTable[] = {
    SPECIES_GOLURK,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_GOLURK_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_GOLETT

#if P_FAMILY_STUNFISK
static const enum Species sStunfiskFormSpeciesIdTable[] = {
    SPECIES_STUNFISK,
#if P_GALARIAN_FORMS
    SPECIES_STUNFISK_GALAR,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_STUNFISK

#if P_FAMILY_RUFFLET
static const enum Species sBraviaryFormSpeciesIdTable[] = {
    SPECIES_BRAVIARY,
#if P_HISUIAN_FORMS
    SPECIES_BRAVIARY_HISUI,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_RUFFLET

#if P_FAMILY_TORNADUS
static const enum Species sTornadusFormSpeciesIdTable[] = {
    SPECIES_TORNADUS_INCARNATE,
    SPECIES_TORNADUS_THERIAN,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_TORNADUS

#if P_FAMILY_THUNDURUS
static const enum Species sThundurusFormSpeciesIdTable[] = {
    SPECIES_THUNDURUS_INCARNATE,
    SPECIES_THUNDURUS_THERIAN,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_THUNDURUS

#if P_FAMILY_LANDORUS
static const enum Species sLandorusFormSpeciesIdTable[] = {
    SPECIES_LANDORUS_INCARNATE,
    SPECIES_LANDORUS_THERIAN,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_LANDORUS

#if P_FAMILY_KYUREM
static const enum Species sKyuremFormSpeciesIdTable[] = {
    SPECIES_KYUREM,
    SPECIES_KYUREM_WHITE,
    SPECIES_KYUREM_BLACK,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_KYUREM

#if P_FAMILY_KELDEO
static const enum Species sKeldeoFormSpeciesIdTable[] = {
    SPECIES_KELDEO_ORDINARY,
    SPECIES_KELDEO_RESOLUTE,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_KELDEO

#if P_FAMILY_MELOETTA
static const enum Species sMeloettaFormSpeciesIdTable[] = {
    SPECIES_MELOETTA_ARIA,
    SPECIES_MELOETTA_PIROUETTE,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_MELOETTA

#if P_FAMILY_GENESECT
static const enum Species sGenesectFormSpeciesIdTable[] = {
    SPECIES_GENESECT,
    SPECIES_GENESECT_DOUSE,
    SPECIES_GENESECT_SHOCK,
    SPECIES_GENESECT_BURN,
    SPECIES_GENESECT_CHILL,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_GENESECT

#if P_FAMILY_CHESPIN
static const enum Species sChesnaughtFormSpeciesIdTable[] = {
    SPECIES_CHESNAUGHT,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_CHESNAUGHT_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_CHESPIN

#if P_FAMILY_FENNEKIN
static const enum Species sDelphoxFormSpeciesIdTable[] = {
    SPECIES_DELPHOX,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_DELPHOX_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_FENNEKIN

#if P_FAMILY_FROAKIE
static const enum Species sGreninjaFormSpeciesIdTable[] = {
    SPECIES_GRENINJA,
    SPECIES_GRENINJA_BATTLE_BOND,
    SPECIES_GRENINJA_ASH,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_GRENINJA_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_FROAKIE

#if P_FAMILY_SCATTERBUG
static const enum Species sScatterbugFormSpeciesIdTable[] = {
    SPECIES_SCATTERBUG_ICY_SNOW,
    SPECIES_SCATTERBUG_POLAR,
    SPECIES_SCATTERBUG_TUNDRA,
    SPECIES_SCATTERBUG_CONTINENTAL,
    SPECIES_SCATTERBUG_GARDEN,
    SPECIES_SCATTERBUG_ELEGANT,
    SPECIES_SCATTERBUG_MEADOW,
    SPECIES_SCATTERBUG_MODERN,
    SPECIES_SCATTERBUG_MARINE,
    SPECIES_SCATTERBUG_ARCHIPELAGO,
    SPECIES_SCATTERBUG_HIGH_PLAINS,
    SPECIES_SCATTERBUG_SANDSTORM,
    SPECIES_SCATTERBUG_RIVER,
    SPECIES_SCATTERBUG_MONSOON,
    SPECIES_SCATTERBUG_SAVANNA,
    SPECIES_SCATTERBUG_SUN,
    SPECIES_SCATTERBUG_OCEAN,
    SPECIES_SCATTERBUG_JUNGLE,
    SPECIES_SCATTERBUG_FANCY,
    SPECIES_SCATTERBUG_POKEBALL,
    FORM_SPECIES_END,
};

static const enum Species sSpewpaFormSpeciesIdTable[] = {
    SPECIES_SPEWPA_ICY_SNOW,
    SPECIES_SPEWPA_POLAR,
    SPECIES_SPEWPA_TUNDRA,
    SPECIES_SPEWPA_CONTINENTAL,
    SPECIES_SPEWPA_GARDEN,
    SPECIES_SPEWPA_ELEGANT,
    SPECIES_SPEWPA_MEADOW,
    SPECIES_SPEWPA_MODERN,
    SPECIES_SPEWPA_MARINE,
    SPECIES_SPEWPA_ARCHIPELAGO,
    SPECIES_SPEWPA_HIGH_PLAINS,
    SPECIES_SPEWPA_SANDSTORM,
    SPECIES_SPEWPA_RIVER,
    SPECIES_SPEWPA_MONSOON,
    SPECIES_SPEWPA_SAVANNA,
    SPECIES_SPEWPA_SUN,
    SPECIES_SPEWPA_OCEAN,
    SPECIES_SPEWPA_JUNGLE,
    SPECIES_SPEWPA_FANCY,
    SPECIES_SPEWPA_POKEBALL,
    FORM_SPECIES_END,
};

static const enum Species sVivillonFormSpeciesIdTable[] = {
    SPECIES_VIVILLON_ICY_SNOW,
    SPECIES_VIVILLON_POLAR,
    SPECIES_VIVILLON_TUNDRA,
    SPECIES_VIVILLON_CONTINENTAL,
    SPECIES_VIVILLON_GARDEN,
    SPECIES_VIVILLON_ELEGANT,
    SPECIES_VIVILLON_MEADOW,
    SPECIES_VIVILLON_MODERN,
    SPECIES_VIVILLON_MARINE,
    SPECIES_VIVILLON_ARCHIPELAGO,
    SPECIES_VIVILLON_HIGH_PLAINS,
    SPECIES_VIVILLON_SANDSTORM,
    SPECIES_VIVILLON_RIVER,
    SPECIES_VIVILLON_MONSOON,
    SPECIES_VIVILLON_SAVANNA,
    SPECIES_VIVILLON_SUN,
    SPECIES_VIVILLON_OCEAN,
    SPECIES_VIVILLON_JUNGLE,
    SPECIES_VIVILLON_FANCY,
    SPECIES_VIVILLON_POKEBALL,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_SCATTERBUG

#if P_FAMILY_LITLEO
static const enum Species sPyroarFormSpeciesIdTable[] = {
    SPECIES_PYROAR,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_PYROAR_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_LITLEO

#if P_FAMILY_FLABEBE
static const enum Species sFlabebeFormSpeciesIdTable[] = {
    SPECIES_FLABEBE_RED,
    SPECIES_FLABEBE_YELLOW,
    SPECIES_FLABEBE_ORANGE,
    SPECIES_FLABEBE_BLUE,
    SPECIES_FLABEBE_WHITE,
    FORM_SPECIES_END,
};

static const enum Species sFloetteFormSpeciesIdTable[] = {
    SPECIES_FLOETTE_RED,
    SPECIES_FLOETTE_YELLOW,
    SPECIES_FLOETTE_ORANGE,
    SPECIES_FLOETTE_BLUE,
    SPECIES_FLOETTE_WHITE,
    SPECIES_FLOETTE_ETERNAL,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_FLOETTE_MEGA,
#endif
    FORM_SPECIES_END,
};

static const enum Species sFlorgesFormSpeciesIdTable[] = {
    SPECIES_FLORGES_RED,
    SPECIES_FLORGES_YELLOW,
    SPECIES_FLORGES_ORANGE,
    SPECIES_FLORGES_BLUE,
    SPECIES_FLORGES_WHITE,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_FLABEBE

#if P_FAMILY_FURFROU
static const enum Species sFurfrouFormSpeciesIdTable[] = {
    SPECIES_FURFROU_NATURAL,
    SPECIES_FURFROU_HEART,
    SPECIES_FURFROU_STAR,
    SPECIES_FURFROU_DIAMOND,
    SPECIES_FURFROU_DEBUTANTE,
    SPECIES_FURFROU_MATRON,
    SPECIES_FURFROU_DANDY,
    SPECIES_FURFROU_LA_REINE,
    SPECIES_FURFROU_KABUKI,
    SPECIES_FURFROU_PHARAOH,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_FURFROU

#if P_FAMILY_ESPURR
static const enum Species sMeowsticFormSpeciesIdTable[] = {
    SPECIES_MEOWSTIC_M,
    SPECIES_MEOWSTIC_F,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_MEOWSTIC_M_MEGA,
    SPECIES_MEOWSTIC_F_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_ESPURR

#if P_FAMILY_HONEDGE
static const enum Species sAegislashFormSpeciesIdTable[] = {
    SPECIES_AEGISLASH_SHIELD,
    SPECIES_AEGISLASH_BLADE,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_HONEDGE

#if P_FAMILY_INKAY
static const enum Species sMalamarFormSpeciesIdTable[] = {
    SPECIES_MALAMAR,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_MALAMAR_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_INKAY

#if P_FAMILY_BINACLE
static const enum Species sBarbaracleFormSpeciesIdTable[] = {
    SPECIES_BARBARACLE,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_BARBARACLE_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_BINACLE

#if P_FAMILY_SKRELP
static const enum Species sDragalgeFormSpeciesIdTable[] = {
    SPECIES_DRAGALGE,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_DRAGALGE_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_SKRELP

#if P_FAMILY_HAWLUCHA
static const enum Species sHawluchaFormSpeciesIdTable[] = {
    SPECIES_HAWLUCHA,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_HAWLUCHA_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_HAWLUCHA

#if P_FAMILY_GOOMY
static const enum Species sSliggooFormSpeciesIdTable[] = {
    SPECIES_SLIGGOO,
#if P_HISUIAN_FORMS
    SPECIES_SLIGGOO_HISUI,
#endif
    FORM_SPECIES_END,
};

static const enum Species sGoodraFormSpeciesIdTable[] = {
    SPECIES_GOODRA,
#if P_HISUIAN_FORMS
    SPECIES_GOODRA_HISUI,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_GOOMY

#if P_FAMILY_PUMPKABOO
static const enum Species sPumpkabooFormSpeciesIdTable[] = {
    SPECIES_PUMPKABOO_AVERAGE,
    SPECIES_PUMPKABOO_SMALL,
    SPECIES_PUMPKABOO_LARGE,
    SPECIES_PUMPKABOO_SUPER,
    FORM_SPECIES_END,
};

static const enum Species sGourgeistFormSpeciesIdTable[] = {
    SPECIES_GOURGEIST_AVERAGE,
    SPECIES_GOURGEIST_SMALL,
    SPECIES_GOURGEIST_LARGE,
    SPECIES_GOURGEIST_SUPER,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_PUMPKABOO

#if P_FAMILY_BERGMITE
static const enum Species sAvaluggFormSpeciesIdTable[] = {
    SPECIES_AVALUGG,
#if P_HISUIAN_FORMS
    SPECIES_AVALUGG_HISUI,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_BERGMITE

#if P_FAMILY_XERNEAS
static const enum Species sXerneasFormSpeciesIdTable[] = {
    SPECIES_XERNEAS_NEUTRAL,
    SPECIES_XERNEAS_ACTIVE,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_XERNEAS

#if P_FAMILY_ZYGARDE
static const enum Species sZygardeFormSpeciesIdTable[] = {
    SPECIES_ZYGARDE_50,
    SPECIES_ZYGARDE_10_AURA_BREAK,
    SPECIES_ZYGARDE_10_POWER_CONSTRUCT,
    SPECIES_ZYGARDE_50_POWER_CONSTRUCT,
    SPECIES_ZYGARDE_COMPLETE,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_ZYGARDE_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_ZYGARDE

#if P_FAMILY_DIANCIE
static const enum Species sDiancieFormSpeciesIdTable[] = {
    SPECIES_DIANCIE,
#if P_MEGA_EVOLUTIONS
    SPECIES_DIANCIE_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_DIANCIE

#if P_FAMILY_HOOPA
static const enum Species sHoopaFormSpeciesIdTable[] = {
    SPECIES_HOOPA_CONFINED,
    SPECIES_HOOPA_UNBOUND,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_HOOPA

#if P_FAMILY_ROWLET
static const enum Species sDecidueyeFormSpeciesIdTable[] = {
    SPECIES_DECIDUEYE,
#if P_HISUIAN_FORMS
    SPECIES_DECIDUEYE_HISUI,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_ROWLET

#if P_FAMILY_YUNGOOS
static const enum Species sGumshoosFormSpeciesIdTable[] = {
    SPECIES_GUMSHOOS,
    SPECIES_GUMSHOOS_TOTEM,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_YUNGOOS

#if P_FAMILY_GRUBBIN
static const enum Species sVikavoltFormSpeciesIdTable[] = {
    SPECIES_VIKAVOLT,
    SPECIES_VIKAVOLT_TOTEM,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_GRUBBIN

#if P_FAMILY_CRABRAWLER
static const enum Species sCrabominableFormSpeciesIdTable[] = {
    SPECIES_CRABOMINABLE,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_CRABOMINABLE_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_CRABRAWLER

#if P_FAMILY_ORICORIO
static const enum Species sOricorioFormSpeciesIdTable[] = {
    SPECIES_ORICORIO_BAILE,
    SPECIES_ORICORIO_POM_POM,
    SPECIES_ORICORIO_PAU,
    SPECIES_ORICORIO_SENSU,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_ORICORIO

#if P_FAMILY_CUTIEFLY
static const enum Species sRibombeeFormSpeciesIdTable[] = {
    SPECIES_RIBOMBEE,
    SPECIES_RIBOMBEE_TOTEM,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_CUTIEFLY

#if P_FAMILY_ROCKRUFF
static const enum Species sRockruffFormSpeciesIdTable[] = {
    SPECIES_ROCKRUFF,
    SPECIES_ROCKRUFF_OWN_TEMPO,
    FORM_SPECIES_END,
};

static const enum Species sLycanrocFormSpeciesIdTable[] = {
    SPECIES_LYCANROC_MIDDAY,
    SPECIES_LYCANROC_MIDNIGHT,
    SPECIES_LYCANROC_DUSK,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_ROCKRUFF

#if P_FAMILY_WISHIWASHI
static const enum Species sWishiwashiFormSpeciesIdTable[] = {
    SPECIES_WISHIWASHI_SOLO,
    SPECIES_WISHIWASHI_SCHOOL,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_WISHIWASHI

#if P_FAMILY_DEWPIDER
static const enum Species sAraquanidFormSpeciesIdTable[] = {
    SPECIES_ARAQUANID,
    SPECIES_ARAQUANID_TOTEM,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_DEWPIDER

#if P_FAMILY_FOMANTIS
static const enum Species sLurantisFormSpeciesIdTable[] = {
    SPECIES_LURANTIS,
    SPECIES_LURANTIS_TOTEM,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_FOMANTIS

#if P_FAMILY_SALANDIT
static const enum Species sSalazzleFormSpeciesIdTable[] = {
    SPECIES_SALAZZLE,
    SPECIES_SALAZZLE_TOTEM,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_FOMANTIS

#if P_FAMILY_WIMPOD
static const enum Species sGolisopodFormSpeciesIdTable[] = {
    SPECIES_GOLISOPOD,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_GOLISOPOD_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_WIMPOD

#if P_FAMILY_TYPE_NULL
static const enum Species sSilvallyFormSpeciesIdTable[] = {
    SPECIES_SILVALLY_NORMAL,
    SPECIES_SILVALLY_FIGHTING,
    SPECIES_SILVALLY_FLYING,
    SPECIES_SILVALLY_POISON,
    SPECIES_SILVALLY_GROUND,
    SPECIES_SILVALLY_ROCK,
    SPECIES_SILVALLY_BUG,
    SPECIES_SILVALLY_GHOST,
    SPECIES_SILVALLY_STEEL,
    SPECIES_SILVALLY_FIRE,
    SPECIES_SILVALLY_WATER,
    SPECIES_SILVALLY_GRASS,
    SPECIES_SILVALLY_ELECTRIC,
    SPECIES_SILVALLY_PSYCHIC,
    SPECIES_SILVALLY_ICE,
    SPECIES_SILVALLY_DRAGON,
    SPECIES_SILVALLY_DARK,
    SPECIES_SILVALLY_FAIRY,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_TYPE_NULL

#if P_FAMILY_MINIOR
static const enum Species sMiniorFormSpeciesIdTable[] = {
    SPECIES_MINIOR_METEOR_RED,
    SPECIES_MINIOR_METEOR_ORANGE,
    SPECIES_MINIOR_METEOR_YELLOW,
    SPECIES_MINIOR_METEOR_GREEN,
    SPECIES_MINIOR_METEOR_BLUE,
    SPECIES_MINIOR_METEOR_INDIGO,
    SPECIES_MINIOR_METEOR_VIOLET,
    SPECIES_MINIOR_CORE_RED,
    SPECIES_MINIOR_CORE_ORANGE,
    SPECIES_MINIOR_CORE_YELLOW,
    SPECIES_MINIOR_CORE_GREEN,
    SPECIES_MINIOR_CORE_BLUE,
    SPECIES_MINIOR_CORE_INDIGO,
    SPECIES_MINIOR_CORE_VIOLET,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_MINIOR

#if P_FAMILY_TOGEDEMARU
static const enum Species sTogedemaruFormSpeciesIdTable[] = {
    SPECIES_TOGEDEMARU,
    SPECIES_TOGEDEMARU_TOTEM,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_TOGEDEMARU

#if P_FAMILY_MIMIKYU
static const enum Species sMimikyuFormSpeciesIdTable[] = {
    SPECIES_MIMIKYU_DISGUISED,
    SPECIES_MIMIKYU_BUSTED,
    SPECIES_MIMIKYU_TOTEM_DISGUISED,
    SPECIES_MIMIKYU_BUSTED_TOTEM,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_MIMIKYU

#if P_FAMILY_DRAMPA
static const enum Species sDrampaFormSpeciesIdTable[] = {
    SPECIES_DRAMPA,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_DRAMPA_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_DRAMPA

#if P_FAMILY_JANGMO_O
static const enum Species sKommoOFormSpeciesIdTable[] = {
    SPECIES_KOMMO_O,
    SPECIES_KOMMO_O_TOTEM,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_JANGMO_O

#if P_FAMILY_NECROZMA
static const enum Species sNecrozmaFormSpeciesIdTable[] = {
    SPECIES_NECROZMA,
    SPECIES_NECROZMA_DUSK_MANE,
    SPECIES_NECROZMA_DAWN_WINGS,
#if P_ULTRA_BURST_FORMS
    SPECIES_NECROZMA_ULTRA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_NECROZMA

#if P_FAMILY_MAGEARNA
static const enum Species sMagearnaFormSpeciesIdTable[] = {
    SPECIES_MAGEARNA,
    SPECIES_MAGEARNA_ORIGINAL,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_MAGEARNA_MEGA,
    SPECIES_MAGEARNA_ORIGINAL_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_MAGEARNA

#if P_FAMILY_ZERAORA
static const enum Species sZeraoraFormSpeciesIdTable[] = {
    SPECIES_ZERAORA,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_ZERAORA_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_ZERAORA

#if P_FAMILY_MELTAN
static const enum Species sMelmetalFormSpeciesIdTable[] = {
    SPECIES_MELMETAL,
#if P_GIGANTAMAX_FORMS
    SPECIES_MELMETAL_GMAX,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_MELTAN

#if P_FAMILY_GROOKEY
static const enum Species sRillaboomFormSpeciesIdTable[] = {
    SPECIES_RILLABOOM,
#if P_GIGANTAMAX_FORMS
    SPECIES_RILLABOOM_GMAX,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_GROOKEY

#if P_FAMILY_SCORBUNNY
static const enum Species sCinderaceFormSpeciesIdTable[] = {
    SPECIES_CINDERACE,
#if P_GIGANTAMAX_FORMS
    SPECIES_CINDERACE_GMAX,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_SCORBUNNY

#if P_FAMILY_SOBBLE
static const enum Species sInteleonFormSpeciesIdTable[] = {
    SPECIES_INTELEON,
#if P_GIGANTAMAX_FORMS
    SPECIES_INTELEON_GMAX,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_SOBBLE

#if P_FAMILY_ROOKIDEE
static const enum Species sCorviknightFormSpeciesIdTable[] = {
    SPECIES_CORVIKNIGHT,
#if P_GIGANTAMAX_FORMS
    SPECIES_CORVIKNIGHT_GMAX,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_ROOKIDEE

#if P_FAMILY_BLIPBUG
static const enum Species sOrbeetleFormSpeciesIdTable[] = {
    SPECIES_ORBEETLE,
#if P_GIGANTAMAX_FORMS
    SPECIES_ORBEETLE_GMAX,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_BLIPBUG

#if P_FAMILY_CHEWTLE
static const enum Species sDrednawFormSpeciesIdTable[] = {
    SPECIES_DREDNAW,
#if P_GIGANTAMAX_FORMS
    SPECIES_DREDNAW_GMAX,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_CHEWTLE

#if P_FAMILY_ROLYCOLY
static const enum Species sCoalossalFormSpeciesIdTable[] = {
    SPECIES_COALOSSAL,
#if P_GIGANTAMAX_FORMS
    SPECIES_COALOSSAL_GMAX,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_ROLYCOLY

#if P_FAMILY_APPLIN
static const enum Species sFlappleFormSpeciesIdTable[] = {
    SPECIES_FLAPPLE,
#if P_GIGANTAMAX_FORMS
    SPECIES_FLAPPLE_GMAX,
#endif
    FORM_SPECIES_END,
};

static const enum Species sAppletunFormSpeciesIdTable[] = {
    SPECIES_APPLETUN,
#if P_GIGANTAMAX_FORMS
    SPECIES_APPLETUN_GMAX,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_APPLIN

#if P_FAMILY_SILICOBRA
static const enum Species sSandacondaFormSpeciesIdTable[] = {
    SPECIES_SANDACONDA,
#if P_GIGANTAMAX_FORMS
    SPECIES_SANDACONDA_GMAX,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_SILICOBRA

#if P_FAMILY_CRAMORANT
static const enum Species sCramorantFormSpeciesIdTable[] = {
    SPECIES_CRAMORANT,
    SPECIES_CRAMORANT_GULPING,
    SPECIES_CRAMORANT_GORGING,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_CRAMORANT

#if P_FAMILY_TOXEL
static const enum Species sToxtricityFormSpeciesIdTable[] = {
    SPECIES_TOXTRICITY_AMPED,
    SPECIES_TOXTRICITY_LOW_KEY,
#if P_GIGANTAMAX_FORMS
    SPECIES_TOXTRICITY_AMPED_GMAX,
#endif
#if P_GIGANTAMAX_FORMS
    SPECIES_TOXTRICITY_LOW_KEY_GMAX,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_TOXEL

#if P_FAMILY_SIZZLIPEDE
static const enum Species sCentiskorchFormSpeciesIdTable[] = {
    SPECIES_CENTISKORCH,
#if P_GIGANTAMAX_FORMS
    SPECIES_CENTISKORCH_GMAX,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_SIZZLIPEDE

#if P_FAMILY_SINISTEA
static const enum Species sSinisteaFormSpeciesIdTable[] = {
    SPECIES_SINISTEA_PHONY,
    SPECIES_SINISTEA_ANTIQUE,
    FORM_SPECIES_END,
};

static const enum Species sPolteageistFormSpeciesIdTable[] = {
    SPECIES_POLTEAGEIST_PHONY,
    SPECIES_POLTEAGEIST_ANTIQUE,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_SINISTEA

#if P_FAMILY_HATENNA
static const enum Species sHattereneFormSpeciesIdTable[] = {
    SPECIES_HATTERENE,
#if P_GIGANTAMAX_FORMS
    SPECIES_HATTERENE_GMAX,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_HATENNA

#if P_FAMILY_IMPIDIMP
static const enum Species sGrimmsnarlFormSpeciesIdTable[] = {
    SPECIES_GRIMMSNARL,
#if P_GIGANTAMAX_FORMS
    SPECIES_GRIMMSNARL_GMAX,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_IMPIDIMP

#if P_FAMILY_MILCERY
static const enum Species sAlcremieFormSpeciesIdTable[] = {
    SPECIES_ALCREMIE_STRAWBERRY_VANILLA_CREAM,
    SPECIES_ALCREMIE_STRAWBERRY_RUBY_CREAM,
    SPECIES_ALCREMIE_STRAWBERRY_MATCHA_CREAM,
    SPECIES_ALCREMIE_STRAWBERRY_MINT_CREAM,
    SPECIES_ALCREMIE_STRAWBERRY_LEMON_CREAM,
    SPECIES_ALCREMIE_STRAWBERRY_SALTED_CREAM,
    SPECIES_ALCREMIE_STRAWBERRY_RUBY_SWIRL,
    SPECIES_ALCREMIE_STRAWBERRY_CARAMEL_SWIRL,
    SPECIES_ALCREMIE_STRAWBERRY_RAINBOW_SWIRL,
    SPECIES_ALCREMIE_BERRY_VANILLA_CREAM,
    SPECIES_ALCREMIE_BERRY_RUBY_CREAM,
    SPECIES_ALCREMIE_BERRY_MATCHA_CREAM,
    SPECIES_ALCREMIE_BERRY_MINT_CREAM,
    SPECIES_ALCREMIE_BERRY_LEMON_CREAM,
    SPECIES_ALCREMIE_BERRY_SALTED_CREAM,
    SPECIES_ALCREMIE_BERRY_RUBY_SWIRL,
    SPECIES_ALCREMIE_BERRY_CARAMEL_SWIRL,
    SPECIES_ALCREMIE_BERRY_RAINBOW_SWIRL,
    SPECIES_ALCREMIE_LOVE_VANILLA_CREAM,
    SPECIES_ALCREMIE_LOVE_RUBY_CREAM,
    SPECIES_ALCREMIE_LOVE_MATCHA_CREAM,
    SPECIES_ALCREMIE_LOVE_MINT_CREAM,
    SPECIES_ALCREMIE_LOVE_LEMON_CREAM,
    SPECIES_ALCREMIE_LOVE_SALTED_CREAM,
    SPECIES_ALCREMIE_LOVE_RUBY_SWIRL,
    SPECIES_ALCREMIE_LOVE_CARAMEL_SWIRL,
    SPECIES_ALCREMIE_LOVE_RAINBOW_SWIRL,
    SPECIES_ALCREMIE_STAR_VANILLA_CREAM,
    SPECIES_ALCREMIE_STAR_RUBY_CREAM,
    SPECIES_ALCREMIE_STAR_MATCHA_CREAM,
    SPECIES_ALCREMIE_STAR_MINT_CREAM,
    SPECIES_ALCREMIE_STAR_LEMON_CREAM,
    SPECIES_ALCREMIE_STAR_SALTED_CREAM,
    SPECIES_ALCREMIE_STAR_RUBY_SWIRL,
    SPECIES_ALCREMIE_STAR_CARAMEL_SWIRL,
    SPECIES_ALCREMIE_STAR_RAINBOW_SWIRL,
    SPECIES_ALCREMIE_CLOVER_VANILLA_CREAM,
    SPECIES_ALCREMIE_CLOVER_RUBY_CREAM,
    SPECIES_ALCREMIE_CLOVER_MATCHA_CREAM,
    SPECIES_ALCREMIE_CLOVER_MINT_CREAM,
    SPECIES_ALCREMIE_CLOVER_LEMON_CREAM,
    SPECIES_ALCREMIE_CLOVER_SALTED_CREAM,
    SPECIES_ALCREMIE_CLOVER_RUBY_SWIRL,
    SPECIES_ALCREMIE_CLOVER_CARAMEL_SWIRL,
    SPECIES_ALCREMIE_CLOVER_RAINBOW_SWIRL,
    SPECIES_ALCREMIE_FLOWER_VANILLA_CREAM,
    SPECIES_ALCREMIE_FLOWER_RUBY_CREAM,
    SPECIES_ALCREMIE_FLOWER_MATCHA_CREAM,
    SPECIES_ALCREMIE_FLOWER_MINT_CREAM,
    SPECIES_ALCREMIE_FLOWER_LEMON_CREAM,
    SPECIES_ALCREMIE_FLOWER_SALTED_CREAM,
    SPECIES_ALCREMIE_FLOWER_RUBY_SWIRL,
    SPECIES_ALCREMIE_FLOWER_CARAMEL_SWIRL,
    SPECIES_ALCREMIE_FLOWER_RAINBOW_SWIRL,
    SPECIES_ALCREMIE_RIBBON_VANILLA_CREAM,
    SPECIES_ALCREMIE_RIBBON_RUBY_CREAM,
    SPECIES_ALCREMIE_RIBBON_MATCHA_CREAM,
    SPECIES_ALCREMIE_RIBBON_MINT_CREAM,
    SPECIES_ALCREMIE_RIBBON_LEMON_CREAM,
    SPECIES_ALCREMIE_RIBBON_SALTED_CREAM,
    SPECIES_ALCREMIE_RIBBON_RUBY_SWIRL,
    SPECIES_ALCREMIE_RIBBON_CARAMEL_SWIRL,
    SPECIES_ALCREMIE_RIBBON_RAINBOW_SWIRL,
#if P_GIGANTAMAX_FORMS
    SPECIES_ALCREMIE_GMAX,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_MILCERY

#if P_FAMILY_FALINKS
static const enum Species sFalinksFormSpeciesIdTable[] = {
    SPECIES_FALINKS,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_FALINKS_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_FALINKS

#if P_FAMILY_EISCUE
static const enum Species sEiscueFormSpeciesIdTable[] = {
    SPECIES_EISCUE_ICE,
    SPECIES_EISCUE_NOICE,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_EISCUE

#if P_FAMILY_INDEEDEE
static const enum Species sIndeedeeFormSpeciesIdTable[] = {
    SPECIES_INDEEDEE_M,
    SPECIES_INDEEDEE_F,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_INDEEDEE

#if P_FAMILY_MORPEKO
static const enum Species sMorpekoFormSpeciesIdTable[] = {
    SPECIES_MORPEKO_FULL_BELLY,
    SPECIES_MORPEKO_HANGRY,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_MORPEKO

#if P_FAMILY_CUFANT
static const enum Species sCopperajahFormSpeciesIdTable[] = {
    SPECIES_COPPERAJAH,
#if P_GIGANTAMAX_FORMS
    SPECIES_COPPERAJAH_GMAX,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_CUFANT

#if P_FAMILY_DURALUDON
static const enum Species sDuraludonFormSpeciesIdTable[] = {
    SPECIES_DURALUDON,
#if P_GIGANTAMAX_FORMS
    SPECIES_DURALUDON_GMAX,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_DURALUDON

#if P_FAMILY_ZACIAN
static const enum Species sZacianFormSpeciesIdTable[] = {
    SPECIES_ZACIAN_HERO,
    SPECIES_ZACIAN_CROWNED,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_ZACIAN

#if P_FAMILY_ZAMAZENTA
static const enum Species sZamazentaFormSpeciesIdTable[] = {
    SPECIES_ZAMAZENTA_HERO,
    SPECIES_ZAMAZENTA_CROWNED,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_ZAMAZENTA

#if P_FAMILY_ETERNATUS
static const enum Species sEternatusFormSpeciesIdTable[] = {
    SPECIES_ETERNATUS,
    SPECIES_ETERNATUS_ETERNAMAX,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_ETERNATUS

#if P_FAMILY_KUBFU
static const enum Species sUrshifuFormSpeciesIdTable[] = {
    SPECIES_URSHIFU_SINGLE_STRIKE,
    SPECIES_URSHIFU_RAPID_STRIKE,
#if P_GIGANTAMAX_FORMS
    SPECIES_URSHIFU_SINGLE_STRIKE_GMAX,
    SPECIES_URSHIFU_RAPID_STRIKE_GMAX,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_KUBFU

#if P_FAMILY_ZARUDE
static const enum Species sZarudeFormSpeciesIdTable[] = {
    SPECIES_ZARUDE,
    SPECIES_ZARUDE_DADA,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_ZARUDE

#if P_FAMILY_CALYREX
static const enum Species sCalyrexFormSpeciesIdTable[] = {
    SPECIES_CALYREX,
    SPECIES_CALYREX_ICE,
    SPECIES_CALYREX_SHADOW,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_CALYREX

#if P_FAMILY_ENAMORUS
static const enum Species sEnamorusFormSpeciesIdTable[] = {
    SPECIES_ENAMORUS_INCARNATE,
    SPECIES_ENAMORUS_THERIAN,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_ENAMORUS

#if P_FAMILY_LECHONK
static const enum Species sOinkologneFormSpeciesIdTable[] = {
    SPECIES_OINKOLOGNE_M,
    SPECIES_OINKOLOGNE_F,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_LECHONK

#if P_FAMILY_TANDEMAUS
static const enum Species sMausholdFormSpeciesIdTable[] = {
    SPECIES_MAUSHOLD_THREE,
    SPECIES_MAUSHOLD_FOUR,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_TANDEMAUS

#if P_FAMILY_SQUAWKABILLY
static const enum Species sSquawkabillyFormSpeciesIdTable[] = {
    SPECIES_SQUAWKABILLY_GREEN,
    SPECIES_SQUAWKABILLY_BLUE,
    SPECIES_SQUAWKABILLY_YELLOW,
    SPECIES_SQUAWKABILLY_WHITE,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_SQUAWKABILLY

#if P_FAMILY_CAPSAKID
static const enum Species sScovillainFormSpeciesIdTable[] = {
    SPECIES_SCOVILLAIN,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_SCOVILLAIN_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_CAPSAKID

#if P_FAMILY_FINIZEN
static const enum Species sPalafinFormSpeciesIdTable[] = {
    SPECIES_PALAFIN_ZERO,
    SPECIES_PALAFIN_HERO,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_FINIZEN

#if P_FAMILY_GLIMMET
static const enum Species sGlimmoraFormSpeciesIdTable[] = {
    SPECIES_GLIMMORA,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_GLIMMORA_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_GLIMMET

#if P_FAMILY_TATSUGIRI
static const enum Species sTatsugiriFormSpeciesIdTable[] = {
    SPECIES_TATSUGIRI_CURLY,
    SPECIES_TATSUGIRI_DROOPY,
    SPECIES_TATSUGIRI_STRETCHY,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_TATSUGIRI_CURLY_MEGA,
    SPECIES_TATSUGIRI_DROOPY_MEGA,
    SPECIES_TATSUGIRI_STRETCHY_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_TATSUGIRI

#if P_FAMILY_FRIGIBAX
static const enum Species sBaxcaliburFormSpeciesIdTable[] = {
    SPECIES_BAXCALIBUR,
#if P_GEN_9_MEGA_EVOLUTIONS
    SPECIES_BAXCALIBUR_MEGA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_FRIGIBAX

#if P_FAMILY_GIMMIGHOUL
static const enum Species sGimmighoulFormSpeciesIdTable[] = {
    SPECIES_GIMMIGHOUL_CHEST,
    SPECIES_GIMMIGHOUL_ROAMING,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_GIMMIGHOUL

#if P_FAMILY_POLTCHAGEIST
static const enum Species sPoltchageistFormSpeciesIdTable[] = {
    SPECIES_POLTCHAGEIST_COUNTERFEIT,
    SPECIES_POLTCHAGEIST_ARTISAN,
    FORM_SPECIES_END,
};

static const enum Species sSinistchaFormSpeciesIdTable[] = {
    SPECIES_SINISTCHA_UNREMARKABLE,
    SPECIES_SINISTCHA_MASTERPIECE,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_POLTCHAGEIST

#if P_FAMILY_OGERPON
static const enum Species sOgerponFormSpeciesIdTable[] = {
    SPECIES_OGERPON_TEAL,
    SPECIES_OGERPON_WELLSPRING,
    SPECIES_OGERPON_HEARTHFLAME,
    SPECIES_OGERPON_CORNERSTONE,
#if P_TERA_FORMS
    SPECIES_OGERPON_TEAL_TERA,
    SPECIES_OGERPON_WELLSPRING_TERA,
    SPECIES_OGERPON_HEARTHFLAME_TERA,
    SPECIES_OGERPON_CORNERSTONE_TERA,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_OGERPON

#if P_FAMILY_TERAPAGOS
static const enum Species sTerapagosFormSpeciesIdTable[] = {
    SPECIES_TERAPAGOS_NORMAL,
    SPECIES_TERAPAGOS_TERASTAL,
#if P_TERA_FORMS
    SPECIES_TERAPAGOS_STELLAR,
#endif
    FORM_SPECIES_END,
};
#endif //P_FAMILY_TERAPAGOS
