const u16 gTutorMoves[TUTOR_MOVE_COUNT] =
{
};

#define TUTOR(move) (1u << (TUTOR_##move))

static const u32 sTutorLearnsets[TUTOR_MOVE_COUNT] =
{
    [SPECIES_NONE]             = (0),


    [SPECIES_BULBASAUR]        = (),

    [SPECIES_IVYSAUR]          = (),

    [SPECIES_VENUSAUR]         = (),

    [SPECIES_CHARMANDER]       = (),

    [SPECIES_CHARMELEON]       = (),

    [SPECIES_CHARIZARD]        = (),

    [SPECIES_SQUIRTLE]         = (),

    [SPECIES_WARTORTLE]        = (),

    [SPECIES_BLASTOISE]        = (),

    [SPECIES_CATERPIE]         = (),

    [SPECIES_METAPOD]          = (),

    [SPECIES_BUTTERFREE]       = (),

    [SPECIES_WEEDLE]           = (),

    [SPECIES_KAKUNA]           = (),

    [SPECIES_BEEDRILL]         = (),

    [SPECIES_PIDGEY]           = (),

    [SPECIES_PIDGEOTTO]        = (),

    [SPECIES_PIDGEOT]          = (),

    [SPECIES_RATTATA]          = (),

    [SPECIES_RATICATE]         = (),

    [SPECIES_SPEAROW]          = (),

    [SPECIES_FEAROW]           = (),

    [SPECIES_EKANS]            = (),

    [SPECIES_ARBOK]            = (),

    [SPECIES_PIKACHU]          = (),

    [SPECIES_RAICHU]           = (),

    [SPECIES_SANDSHREW]        = (),

    [SPECIES_SANDSLASH]        = (),

    [SPECIES_NIDORAN_F]        = (),

    [SPECIES_NIDORINA]         = (),

    [SPECIES_NIDOQUEEN]        = (),

    [SPECIES_NIDORAN_M]        = (),

    [SPECIES_NIDORINO]         = (),

    [SPECIES_NIDOKING]         = (),

    [SPECIES_CLEFAIRY]         = (),

    [SPECIES_CLEFABLE]         = (),

    [SPECIES_VULPIX]           = (),

    [SPECIES_NINETALES]        = (),

    [SPECIES_JIGGLYPUFF]       = (),

    [SPECIES_WIGGLYTUFF]       = (),

    [SPECIES_ZUBAT]            = (),

    [SPECIES_GOLBAT]           = (),

    [SPECIES_ODDISH]           = (),

    [SPECIES_GLOOM]            = (),

    [SPECIES_VILEPLUME]        = (),

    [SPECIES_PARAS]            = (),

    [SPECIES_PARASECT]         = (),

    [SPECIES_VENONAT]          = (),

    [SPECIES_VENOMOTH]         = (),

    [SPECIES_DIGLETT]          = (),

    [SPECIES_DUGTRIO]          = (),

    [SPECIES_MEOWTH]           = (),

    [SPECIES_PERSIAN]          = (),

    [SPECIES_PSYDUCK]          = (),

    [SPECIES_GOLDUCK]          = (),

    [SPECIES_MANKEY]           = (),

    [SPECIES_PRIMEAPE]         = (),

    [SPECIES_GROWLITHE]        = (),

    [SPECIES_ARCANINE]         = (),

    [SPECIES_POLIWAG]          = (),

    [SPECIES_POLIWHIRL]        = (),

    [SPECIES_POLIWRATH]        = (),

    [SPECIES_ABRA]             = (),

    [SPECIES_KADABRA]          = (),

    [SPECIES_ALAKAZAM]         = (),

    [SPECIES_MACHOP]           = (),

    [SPECIES_MACHOKE]          = (),

    [SPECIES_MACHAMP]          = (),

    [SPECIES_BELLSPROUT]       = (),

    [SPECIES_WEEPINBELL]       = (),

    [SPECIES_VICTREEBEL]       = (),

    [SPECIES_TENTACOOL]        = (),

    [SPECIES_TENTACRUEL]       = (),

    [SPECIES_GEODUDE]          = (),

    [SPECIES_GRAVELER]         = (),

    [SPECIES_GOLEM]            = (),

    [SPECIES_PONYTA]           = (),

    [SPECIES_RAPIDASH]         = (),

    [SPECIES_SLOWPOKE]         = (),

    [SPECIES_SLOWBRO]          = (),

    [SPECIES_MAGNEMITE]        = (),

    [SPECIES_MAGNETON]         = (),

    [SPECIES_FARFETCHD]        = (),

    [SPECIES_DODUO]            = (),

    [SPECIES_DODRIO]           = (),

    [SPECIES_SEEL]             = (),

    [SPECIES_DEWGONG]          = (),

    [SPECIES_GRIMER]           = (),

    [SPECIES_MUK]              = (),

    [SPECIES_SHELLDER]         = (),

    [SPECIES_CLOYSTER]         = (),

    [SPECIES_GASTLY]           = (),

    [SPECIES_HAUNTER]          = (),

    [SPECIES_GENGAR]           = (),

    [SPECIES_ONIX]             = (),

    [SPECIES_DROWZEE]          = (),

    [SPECIES_HYPNO]            = (),

    [SPECIES_KRABBY]           = (),

    [SPECIES_KINGLER]          = (),

    [SPECIES_VOLTORB]          = (),

    [SPECIES_ELECTRODE]        = (),

    [SPECIES_EXEGGCUTE]        = (),

    [SPECIES_EXEGGUTOR]        = (),

    [SPECIES_CUBONE]           = (),

    [SPECIES_MAROWAK]          = (),

    [SPECIES_HITMONLEE]        = (),

    [SPECIES_HITMONCHAN]       = (),

    [SPECIES_LICKITUNG]        = (),

    [SPECIES_KOFFING]          = (),

    [SPECIES_WEEZING]          = (),

    [SPECIES_RHYHORN]          = (),

    [SPECIES_RHYDON]           = (),

    [SPECIES_CHANSEY]          = (),

    [SPECIES_TANGELA]          = (),

    [SPECIES_KANGASKHAN]       = (),

    [SPECIES_HORSEA]           = (),

    [SPECIES_SEADRA]           = (),

    [SPECIES_GOLDEEN]          = (),

    [SPECIES_SEAKING]          = (),

    [SPECIES_STARYU]           = (),

    [SPECIES_STARMIE]          = (),

    [SPECIES_MR_MIME]          = (),

    [SPECIES_SCYTHER]          = (),

    [SPECIES_JYNX]             = (),

    [SPECIES_ELECTABUZZ]       = (),

    [SPECIES_MAGMAR]           = (),

    [SPECIES_PINSIR]           = (),

    [SPECIES_TAUROS]           = (),

    [SPECIES_MAGIKARP]         = (),

    [SPECIES_GYARADOS]         = (),

    [SPECIES_LAPRAS]           = (),

    [SPECIES_DITTO]            = (),

    [SPECIES_EEVEE]            = (),

    [SPECIES_VAPOREON]         = (),

    [SPECIES_JOLTEON]          = (),

    [SPECIES_FLAREON]          = (),

    [SPECIES_PORYGON]          = (),

    [SPECIES_OMANYTE]          = (),

    [SPECIES_OMASTAR]          = (),

    [SPECIES_KABUTO]           = (),

    [SPECIES_KABUTOPS]         = (),

    [SPECIES_AERODACTYL]       = (),

    [SPECIES_SNORLAX]          = (),

    [SPECIES_ARTICUNO]         = (),

    [SPECIES_ZAPDOS]           = (),

    [SPECIES_MOLTRES]          = (),

    [SPECIES_DRATINI]          = (),

    [SPECIES_DRAGONAIR]        = (),

    [SPECIES_DRAGONITE]        = (),

    [SPECIES_MEWTWO]           = (),

    [SPECIES_MEW]              = (),

    [SPECIES_CHIKORITA]        = (),

    [SPECIES_BAYLEEF]          = (),

    [SPECIES_MEGANIUM]         = (),

    [SPECIES_CYNDAQUIL]        = (),

    [SPECIES_QUILAVA]          = (),

    [SPECIES_TYPHLOSION]       = (),

    [SPECIES_TOTODILE]         = (),

    [SPECIES_CROCONAW]         = (),

    [SPECIES_FERALIGATR]       = (),

    [SPECIES_SENTRET]          = (),

    [SPECIES_FURRET]           = (),

    [SPECIES_HOOTHOOT]         = (),

    [SPECIES_NOCTOWL]          = (),

    [SPECIES_LEDYBA]           = (),

    [SPECIES_LEDIAN]           = (),

    [SPECIES_SPINARAK]         = (),

    [SPECIES_ARIADOS]          = (),

    [SPECIES_CROBAT]           = (),

    [SPECIES_CHINCHOU]         = (),

    [SPECIES_LANTURN]          = (),

    [SPECIES_PICHU]            = (),

    [SPECIES_CLEFFA]           = (),

    [SPECIES_IGGLYBUFF]        = (),

    [SPECIES_TOGEPI]           = (),

    [SPECIES_TOGETIC]          = (),

    [SPECIES_NATU]             = (),

    [SPECIES_XATU]             = (),

    [SPECIES_MAREEP]           = (),

    [SPECIES_FLAAFFY]          = (),

    [SPECIES_AMPHAROS]         = (),

    [SPECIES_BELLOSSOM]        = (),

    [SPECIES_MARILL]           = (),

    [SPECIES_AZUMARILL]        = (),

    [SPECIES_SUDOWOODO]        = (),

    [SPECIES_POLITOED]         = (),

    [SPECIES_HOPPIP]           = (),

    [SPECIES_SKIPLOOM]         = (),

    [SPECIES_JUMPLUFF]         = (),

    [SPECIES_AIPOM]            = (),

    [SPECIES_SUNKERN]          = (),

    [SPECIES_SUNFLORA]         = (),

    [SPECIES_YANMA]            = (),

    [SPECIES_WOOPER]           = (),

    [SPECIES_QUAGSIRE]         = (),

    [SPECIES_ESPEON]           = (),

    [SPECIES_UMBREON]          = (),

    [SPECIES_MURKROW]          = (),

    [SPECIES_SLOWKING]         = (),

    [SPECIES_MISDREAVUS]       = (),

    [SPECIES_UNOWN]            = (),

    [SPECIES_WOBBUFFET]        = (),

    [SPECIES_GIRAFARIG]        = (),

    [SPECIES_PINECO]           = (),

    [SPECIES_FORRETRESS]       = (),

    [SPECIES_DUNSPARCE]        = (),

    [SPECIES_GLIGAR]           = (),

    [SPECIES_STEELIX]          = (),

    [SPECIES_SNUBBULL]         = (),

    [SPECIES_GRANBULL]         = (),

    [SPECIES_QWILFISH]         = (),

    [SPECIES_SCIZOR]           = (),

    [SPECIES_SHUCKLE]          = (),

    [SPECIES_HERACROSS]        = (),

    [SPECIES_SNEASEL]          = (),

    [SPECIES_TEDDIURSA]        = (),

    [SPECIES_URSARING]         = (),

    [SPECIES_SLUGMA]           = (),

    [SPECIES_MAGCARGO]         = (),

    [SPECIES_SWINUB]           = (),

    [SPECIES_PILOSWINE]        = (),

    [SPECIES_CORSOLA]          = (),

    [SPECIES_REMORAID]         = (),

    [SPECIES_OCTILLERY]        = (),

    [SPECIES_DELIBIRD]         = (),

    [SPECIES_MANTINE]          = (),

    [SPECIES_SKARMORY]         = (),

    [SPECIES_HOUNDOUR]         = (),

    [SPECIES_HOUNDOOM]         = (),

    [SPECIES_KINGDRA]          = (),

    [SPECIES_PHANPY]           = (),

    [SPECIES_DONPHAN]          = (),

    [SPECIES_PORYGON2]         = (),

    [SPECIES_STANTLER]         = (),

    [SPECIES_SMEARGLE]         = (),

    [SPECIES_TYROGUE]          = (),

    [SPECIES_HITMONTOP]        = (),

    [SPECIES_SMOOCHUM]         = (),

    [SPECIES_ELEKID]           = (),

    [SPECIES_MAGBY]            = (),

    [SPECIES_MILTANK]          = (),

    [SPECIES_BLISSEY]          = (),

    [SPECIES_RAIKOU]           = (),

    [SPECIES_ENTEI]            = (),

    [SPECIES_SUICUNE]          = (),

    [SPECIES_LARVITAR]         = (),

    [SPECIES_PUPITAR]          = (),

    [SPECIES_TYRANITAR]        = (),

    [SPECIES_LUGIA]            = (),

    [SPECIES_HO_OH]            = (),

    [SPECIES_CELEBI]           = (),

    [SPECIES_TREECKO]          = (),

    [SPECIES_GROVYLE]          = (),

    [SPECIES_SCEPTILE]         = (),

    [SPECIES_TORCHIC]          = (),

    [SPECIES_COMBUSKEN]        = (),

    [SPECIES_BLAZIKEN]         = (),

    [SPECIES_MUDKIP]           = (),

    [SPECIES_MARSHTOMP]        = (),

    [SPECIES_SWAMPERT]         = (),

    [SPECIES_POOCHYENA]        = (),

    [SPECIES_MIGHTYENA]        = (),

    [SPECIES_ZIGZAGOON]        = (),

    [SPECIES_LINOONE]          = (),

    [SPECIES_WURMPLE]          = (),

    [SPECIES_SILCOON]          = (),

    [SPECIES_BEAUTIFLY]        = (),

    [SPECIES_CASCOON]          = (),

    [SPECIES_DUSTOX]           = (),

    [SPECIES_LOTAD]            = (),

    [SPECIES_LOMBRE]           = (),

    [SPECIES_LUDICOLO]         = (),

    [SPECIES_SEEDOT]           = (),

    [SPECIES_NUZLEAF]          = (),

    [SPECIES_SHIFTRY]          = (),

    [SPECIES_TAILLOW]          = (),

    [SPECIES_SWELLOW]          = (),

    [SPECIES_WINGULL]          = (),

    [SPECIES_PELIPPER]         = (),

    [SPECIES_RALTS]            = (),

    [SPECIES_KIRLIA]           = (),

    [SPECIES_GARDEVOIR]        = (),

    [SPECIES_SURSKIT]          = (),

    [SPECIES_MASQUERAIN]       = (),

    [SPECIES_SHROOMISH]        = (),

    [SPECIES_BRELOOM]          = (),

    [SPECIES_SLAKOTH]          = (),

    [SPECIES_VIGOROTH]         = (),

    [SPECIES_SLAKING]          = (),

    [SPECIES_NINCADA]          = (),

    [SPECIES_NINJASK]          = (),

    [SPECIES_SHEDINJA]         = (),

    [SPECIES_WHISMUR]          = (),

    [SPECIES_LOUDRED]          = (),

    [SPECIES_EXPLOUD]          = (),

    [SPECIES_MAKUHITA]         = (),

    [SPECIES_HARIYAMA]         = (),

    [SPECIES_AZURILL]          = (),

    [SPECIES_NOSEPASS]         = (),

    [SPECIES_SKITTY]           = (),

    [SPECIES_DELCATTY]         = (),

    [SPECIES_SABLEYE]          = (),

    [SPECIES_MAWILE]           = (),

    [SPECIES_ARON]             = (),

    [SPECIES_LAIRON]           = (),

    [SPECIES_AGGRON]           = (),

    [SPECIES_MEDITITE]         = (),

    [SPECIES_MEDICHAM]         = (),

    [SPECIES_ELECTRIKE]        = (),

    [SPECIES_MANECTRIC]        = (),

    [SPECIES_PLUSLE]           = (),

    [SPECIES_MINUN]            = (),

    [SPECIES_VOLBEAT]          = (),

    [SPECIES_ILLUMISE]         = (),

    [SPECIES_ROSELIA]          = (),

    [SPECIES_GULPIN]           = (),

    [SPECIES_SWALOT]           = (),

    [SPECIES_CARVANHA]         = (),

    [SPECIES_SHARPEDO]         = (),

    [SPECIES_WAILMER]          = (),

    [SPECIES_WAILORD]          = (),

    [SPECIES_NUMEL]            = (),

    [SPECIES_CAMERUPT]         = (),

    [SPECIES_TORKOAL]          = (),

    [SPECIES_SPOINK]           = (),

    [SPECIES_GRUMPIG]          = (),

    [SPECIES_SPINDA]           = (),

    [SPECIES_TRAPINCH]         = (),

    [SPECIES_VIBRAVA]          = (),

    [SPECIES_FLYGON]           = (),

    [SPECIES_CACNEA]           = (),

    [SPECIES_CACTURNE]         = (),

    [SPECIES_SWABLU]           = (),

    [SPECIES_ALTARIA]          = (),

    [SPECIES_ZANGOOSE]         = (),

    [SPECIES_SEVIPER]          = (),

    [SPECIES_LUNATONE]         = (),

    [SPECIES_SOLROCK]          = (),

    [SPECIES_BARBOACH]         = (),

    [SPECIES_WHISCASH]         = (),

    [SPECIES_CORPHISH]         = (),

    [SPECIES_CRAWDAUNT]        = (),

    [SPECIES_BALTOY]           = (),

    [SPECIES_CLAYDOL]          = (),

    [SPECIES_LILEEP]           = (),

    [SPECIES_CRADILY]          = (),

    [SPECIES_ANORITH]          = (),

    [SPECIES_ARMALDO]          = (),

    [SPECIES_FEEBAS]           = (),

    [SPECIES_MILOTIC]          = (),

    [SPECIES_CASTFORM]         = (),

    [SPECIES_KECLEON]          = (),

    [SPECIES_SHUPPET]          = (),

    [SPECIES_BANETTE]          = (),

    [SPECIES_DUSKULL]          = (),

    [SPECIES_DUSCLOPS]         = (),

    [SPECIES_TROPIUS]          = (),

    [SPECIES_CHIMECHO]         = (),

    [SPECIES_ABSOL]            = (),

    [SPECIES_WYNAUT]           = (),

    [SPECIES_SNORUNT]          = (),

    [SPECIES_GLALIE]           = (),

    [SPECIES_SPHEAL]           = (),

    [SPECIES_SEALEO]           = (),

    [SPECIES_WALREIN]          = (),

    [SPECIES_CLAMPERL]         = (),

    [SPECIES_HUNTAIL]          = (),

    [SPECIES_GOREBYSS]         = (),

    [SPECIES_RELICANTH]        = (),

    [SPECIES_LUVDISC]          = (),

    [SPECIES_BAGON]            = (),

    [SPECIES_SHELGON]          = (),

    [SPECIES_SALAMENCE]        = (),

    [SPECIES_BELDUM]           = (),

    [SPECIES_METANG]           = (),

    [SPECIES_METAGROSS]        = (),

    [SPECIES_REGIROCK]         = (),

    [SPECIES_REGICE]           = (),

    [SPECIES_REGISTEEL]        = (),

    [SPECIES_LATIAS]           = (),

    [SPECIES_LATIOS]           = (),

    [SPECIES_KYOGRE]           = (),

    [SPECIES_GROUDON]          = (),

    [SPECIES_RAYQUAZA]         = (),

    [SPECIES_JIRACHI]          = (),

    [SPECIES_DEOXYS_NORMAL]    = (),

    [SPECIES_TURTWIG]          = (),

    [SPECIES_GROTLE]           = (),

    [SPECIES_TORTERRA]         = (),

    [SPECIES_CHIMCHAR]         = (),

    [SPECIES_MONFERNO]         = (),

    [SPECIES_INFERNAPE]        = (),

    [SPECIES_PIPLUP]           = (),

    [SPECIES_PRINPLUP]         = (),

    [SPECIES_EMPOLEON]         = (),

    [SPECIES_STARLY]           = (),

    [SPECIES_STARAVIA]         = (),

    [SPECIES_STARAPTOR]        = (),

    [SPECIES_BIDOOF]           = (),

    [SPECIES_BIBAREL]          = (),

    [SPECIES_KRICKETOT]        = (),

    [SPECIES_KRICKETUNE]       = (),

    [SPECIES_SHINX]            = (),

    [SPECIES_LUXIO]            = (),

    [SPECIES_LUXRAY]           = (),

    [SPECIES_BUDEW]            = (),

    [SPECIES_ROSERADE]         = (),

    [SPECIES_CRANIDOS]         = (),

    [SPECIES_RAMPARDOS]        = (),

    [SPECIES_SHIELDON]         = (),

    [SPECIES_BASTIODON]        = (),

    [SPECIES_BURMY]            = (),

    [SPECIES_WORMADAM]         = (),

    [SPECIES_MOTHIM]           = (),

    [SPECIES_COMBEE]           = (),

    [SPECIES_VESPIQUEN]        = (),

    [SPECIES_PACHIRISU]        = (),

    [SPECIES_BUIZEL]           = (),

    [SPECIES_FLOATZEL]         = (),

    [SPECIES_CHERUBI]          = (),

    [SPECIES_CHERRIM]          = (),

    [SPECIES_SHELLOS]          = (),

    [SPECIES_GASTRODON]        = (),

    [SPECIES_AMBIPOM]          = (),

    [SPECIES_DRIFLOON]         = (),

    [SPECIES_DRIFBLIM]         = (),

    [SPECIES_BUNEARY]          = (),

    [SPECIES_LOPUNNY]          = (),

    [SPECIES_MISMAGIUS]        = (),

    [SPECIES_HONCHKROW]        = (),

    [SPECIES_GLAMEOW]          = (),

    [SPECIES_PURUGLY]          = (),

    [SPECIES_CHINGLING]        = (),

    [SPECIES_STUNKY]           = (),

    [SPECIES_SKUNTANK]         = (),

    [SPECIES_BRONZOR]          = (),

    [SPECIES_BRONZONG]         = (),

    [SPECIES_BONSLY]           = (),

    [SPECIES_MIME_JR]          = (),

    [SPECIES_HAPPINY]          = (),

    [SPECIES_CHATOT]           = (),

    [SPECIES_SPIRITOMB]        = (),

    [SPECIES_GIBLE]            = (),

    [SPECIES_GABITE]           = (),

    [SPECIES_GARCHOMP]         = (),

    [SPECIES_MUNCHLAX]         = (),

    [SPECIES_RIOLU]            = (),

    [SPECIES_LUCARIO]          = (),

    [SPECIES_HIPPOPOTAS]       = (),

    [SPECIES_HIPPOWDON]        = (),

    [SPECIES_SKORUPI]          = (),

    [SPECIES_DRAPION]          = (),

    [SPECIES_CROAGUNK]         = (),

    [SPECIES_TOXICROAK]        = (),

    [SPECIES_CARNIVINE]        = (),

    [SPECIES_FINNEON]          = (),

    [SPECIES_LUMINEON]         = (),

    [SPECIES_MANTYKE]          = (),

    [SPECIES_SNOVER]           = (),

    [SPECIES_ABOMASNOW]        = (),

    [SPECIES_WEAVILE]          = (),

    [SPECIES_MAGNEZONE]        = (),

    [SPECIES_LICKILICKY]       = (),

    [SPECIES_RHYPERIOR]        = (),

    [SPECIES_TANGROWTH]        = (),

    [SPECIES_ELECTIVIRE]       = (),

    [SPECIES_MAGMORTAR]        = (),

    [SPECIES_TOGEKISS]         = (),

    [SPECIES_YANMEGA]          = (),

    [SPECIES_LEAFEON]          = (),

    [SPECIES_GLACEON]          = (),

    [SPECIES_GLISCOR]          = (),

    [SPECIES_MAMOSWINE]        = (),

    [SPECIES_PORYGON_Z]        = (),

    [SPECIES_GALLADE]          = (),

    [SPECIES_PROBOPASS]        = (),

    [SPECIES_DUSKNOIR]         = (),

    [SPECIES_FROSLASS]         = (),

    [SPECIES_ROTOM]            = (),

    [SPECIES_UXIE]             = (),

    [SPECIES_MESPRIT]          = (),

    [SPECIES_AZELF]            = (),

    [SPECIES_DIALGA]           = (),

    [SPECIES_PALKIA]           = (),

    [SPECIES_HEATRAN]          = (),

    [SPECIES_REGIGIGAS]        = (),

    [SPECIES_GIRATINA]         = (),

    [SPECIES_CRESSELIA]        = (),

    [SPECIES_PHIONE]           = (),

    [SPECIES_MANAPHY]          = (),

    [SPECIES_DARKRAI]          = (),

    [SPECIES_SHAYMIN]          = (),

    [SPECIES_ARCEUS]           = (),

    [SPECIES_VICTINI]          = (),

    [SPECIES_SNIVY]            = (),

    [SPECIES_SERVINE]          = (),

    [SPECIES_SERPERIOR]        = (),

    [SPECIES_TEPIG]            = (),

    [SPECIES_PIGNITE]          = (),

    [SPECIES_EMBOAR]           = (),

    [SPECIES_OSHAWOTT]         = (),

    [SPECIES_DEWOTT]           = (),

    [SPECIES_SAMUROTT]         = (),

    [SPECIES_PATRAT]           = (),

    [SPECIES_WATCHOG]          = (),

    [SPECIES_LILLIPUP]         = (),

    [SPECIES_HERDIER]          = (),

    [SPECIES_STOUTLAND]        = (),

    [SPECIES_PURRLOIN]         = (),

    [SPECIES_LIEPARD]          = (),

    [SPECIES_PANSAGE]          = (),

    [SPECIES_SIMISAGE]         = (),

    [SPECIES_PANSEAR]          = (),

    [SPECIES_SIMISEAR]         = (),

    [SPECIES_PANPOUR]          = (),

    [SPECIES_SIMIPOUR]         = (),

    [SPECIES_MUNNA]            = (),

    [SPECIES_MUSHARNA]         = (),

    [SPECIES_PIDOVE]           = (),

    [SPECIES_TRANQUILL]        = (),

    [SPECIES_UNFEZANT]         = (),

    [SPECIES_BLITZLE]          = (),

    [SPECIES_ZEBSTRIKA]        = (),

    [SPECIES_ROGGENROLA]       = (),

    [SPECIES_BOLDORE]          = (),

    [SPECIES_GIGALITH]         = (),

    [SPECIES_WOOBAT]           = (),

    [SPECIES_SWOOBAT]          = (),

    [SPECIES_DRILBUR]          = (),

    [SPECIES_EXCADRILL]        = (),

    [SPECIES_AUDINO]           = (),

    [SPECIES_TIMBURR]          = (),

    [SPECIES_GURDURR]          = (),

    [SPECIES_CONKELDURR]       = (),

    [SPECIES_TYMPOLE]          = (),

    [SPECIES_PALPITOAD]        = (),

    [SPECIES_SEISMITOAD]       = (),

    [SPECIES_THROH]            = (),

    [SPECIES_SAWK]             = (),

    [SPECIES_SEWADDLE]         = (),

    [SPECIES_SWADLOON]         = (),

    [SPECIES_LEAVANNY]         = (),

    [SPECIES_VENIPEDE]         = (),

    [SPECIES_WHIRLIPEDE]       = (),

    [SPECIES_SCOLIPEDE]        = (),

    [SPECIES_COTTONEE]         = (),

    [SPECIES_WHIMSICOTT]       = (),

    [SPECIES_PETILIL]          = (),

    [SPECIES_LILLIGANT]        = (),

    [SPECIES_BASCULIN_RED_STRIPED]= (),

    [SPECIES_BASCULIN_BLUE_STRIPED]= (),

    [SPECIES_SANDILE]          = (),

    [SPECIES_KROKOROK]         = (),

    [SPECIES_KROOKODILE]       = (),

    [SPECIES_DARUMAKA]         = (),

    [SPECIES_DARMANITAN]       = (),

    [SPECIES_MARACTUS]         = (),

    [SPECIES_DWEBBLE]          = (),

    [SPECIES_CRUSTLE]          = (),

    [SPECIES_SCRAGGY]          = (),

    [SPECIES_SCRAFTY]          = (),

    [SPECIES_SIGILYPH]         = (),

    [SPECIES_YAMASK]           = (),

    [SPECIES_COFAGRIGUS]       = (),

    [SPECIES_TIRTOUGA]         = (),

    [SPECIES_CARRACOSTA]       = (),

    [SPECIES_ARCHEN]           = (),

    [SPECIES_ARCHEOPS]         = (),

    [SPECIES_TRUBBISH]         = (),

    [SPECIES_GARBODOR]         = (),

    [SPECIES_ZORUA]            = (),

    [SPECIES_ZOROARK]          = (),

    [SPECIES_MINCCINO]         = (),

    [SPECIES_CINCCINO]         = (),

    [SPECIES_GOTHITA]          = (),

    [SPECIES_GOTHORITA]        = (),

    [SPECIES_GOTHITELLE]       = (),

    [SPECIES_SOLOSIS]          = (),

    [SPECIES_DUOSION]          = (),

    [SPECIES_REUNICLUS]        = (),

    [SPECIES_DUCKLETT]         = (),

    [SPECIES_SWANNA]           = (),

    [SPECIES_VANILLITE]        = (),

    [SPECIES_VANILLISH]        = (),

    [SPECIES_VANILLUXE]        = (),

    [SPECIES_DEERLING]         = (),

    [SPECIES_SAWSBUCK]         = (),

    [SPECIES_EMOLGA]           = (),

    [SPECIES_KARRABLAST]       = (),

    [SPECIES_ESCAVALIER]       = (),

    [SPECIES_FOONGUS]          = (),

    [SPECIES_AMOONGUSS]        = (),

    [SPECIES_FRILLISH]         = (),

    [SPECIES_JELLICENT]        = (),

    [SPECIES_ALOMOMOLA]        = (),

    [SPECIES_JOLTIK]           = (),

    [SPECIES_GALVANTULA]       = (),

    [SPECIES_FERROSEED]        = (),

    [SPECIES_FERROTHORN]       = (),

    [SPECIES_KLINK]            = (),

    [SPECIES_KLANG]            = (),

    [SPECIES_KLINKLANG]        = (),

    [SPECIES_TYNAMO]           = (),

    [SPECIES_EELEKTRIK]        = (),

    [SPECIES_EELEKTROSS]       = (),

    [SPECIES_ELGYEM]           = (),

    [SPECIES_BEHEEYEM]         = (),

    [SPECIES_LITWICK]          = (),

    [SPECIES_LAMPENT]          = (),

    [SPECIES_CHANDELURE]       = (),

    [SPECIES_AXEW]             = (),

    [SPECIES_FRAXURE]          = (),

    [SPECIES_HAXORUS]          = (),

    [SPECIES_CUBCHOO]          = (),

    [SPECIES_BEARTIC]          = (),

    [SPECIES_CRYOGONAL]        = (),

    [SPECIES_SHELMET]          = (),

    [SPECIES_ACCELGOR]         = (),

    [SPECIES_STUNFISK]         = (),

    [SPECIES_MIENFOO]          = (),

    [SPECIES_MIENSHAO]         = (),

    [SPECIES_DRUDDIGON]        = (),

    [SPECIES_GOLETT]           = (),

    [SPECIES_GOLURK]           = (),

    [SPECIES_PAWNIARD]         = (),

    [SPECIES_BISHARP]          = (),

    [SPECIES_BOUFFALANT]       = (),

    [SPECIES_RUFFLET]          = (),

    [SPECIES_BRAVIARY]         = (),

    [SPECIES_VULLABY]          = (),

    [SPECIES_MANDIBUZZ]        = (),

    [SPECIES_HEATMOR]          = (),

    [SPECIES_DURANT]           = (),

    [SPECIES_DEINO]            = (),

    [SPECIES_ZWEILOUS]         = (),

    [SPECIES_HYDREIGON]        = (),

    [SPECIES_LARVESTA]         = (),

    [SPECIES_VOLCARONA]        = (),

    [SPECIES_COBALION]         = (),

    [SPECIES_TERRAKION]        = (),

    [SPECIES_VIRIZION]         = (),

    [SPECIES_TORNADUS]         = (),

    [SPECIES_THUNDURUS]        = (),

    [SPECIES_RESHIRAM]         = (),

    [SPECIES_ZEKROM]           = (),

    [SPECIES_LANDORUS]         = (),

    [SPECIES_KYUREM]           = (),

    [SPECIES_KELDEO]           = (),

    [SPECIES_MELOETTA]         = (),

    [SPECIES_GENESECT]         = (),

    [SPECIES_CHESPIN]          = (),

    [SPECIES_QUILLADIN]        = (),

    [SPECIES_CHESNAUGHT]       = (),

    [SPECIES_FENNEKIN]         = (),

    [SPECIES_BRAIXEN]          = (),

    [SPECIES_DELPHOX]          = (),

    [SPECIES_FROAKIE]          = (),

    [SPECIES_FROGADIER]        = (),

    [SPECIES_GRENINJA]         = (),

    [SPECIES_BUNNELBY]         = (),

    [SPECIES_DIGGERSBY]        = (),

    [SPECIES_FLETCHLING]       = (),

    [SPECIES_FLETCHINDER]      = (),

    [SPECIES_TALONFLAME]       = (),

    [SPECIES_SCATTERBUG]       = (),

    [SPECIES_SPEWPA]           = (),

    [SPECIES_VIVILLON]         = (),

    [SPECIES_LITLEO]           = (),

    [SPECIES_PYROAR]           = (),

    [SPECIES_FLABEBE]          = (),

    [SPECIES_FLOETTE]          = (),

    [SPECIES_FLORGES]          = (),

    [SPECIES_SKIDDO]           = (),

    [SPECIES_GOGOAT]           = (),

    [SPECIES_PANCHAM]          = (),

    [SPECIES_PANGORO]          = (),

    [SPECIES_FURFROU]          = (),

    [SPECIES_ESPURR]           = (),

    [SPECIES_MEOWSTIC]         = (),

    [SPECIES_HONEDGE]          = (),

    [SPECIES_DOUBLADE]         = (),

    [SPECIES_AEGISLASH]        = (),

    [SPECIES_SPRITZEE]         = (),

    [SPECIES_AROMATISSE]       = (),

    [SPECIES_SWIRLIX]          = (),

    [SPECIES_SLURPUFF]         = (),

    [SPECIES_INKAY]            = (),

    [SPECIES_MALAMAR]          = (),

    [SPECIES_BINACLE]          = (),

    [SPECIES_BARBARACLE]       = (),

    [SPECIES_SKRELP]           = (),

    [SPECIES_DRAGALGE]         = (),

    [SPECIES_CLAUNCHER]        = (),

    [SPECIES_CLAWITZER]        = (),

    [SPECIES_HELIOPTILE]       = (),

    [SPECIES_HELIOLISK]        = (),

    [SPECIES_TYRUNT]           = (),

    [SPECIES_TYRANTRUM]        = (),

    [SPECIES_AMAURA]           = (),

    [SPECIES_AURORUS]          = (),

    [SPECIES_SYLVEON]          = (),

    [SPECIES_HAWLUCHA]         = (),

    [SPECIES_DEDENNE]          = (),

    [SPECIES_CARBINK]          = (),

    [SPECIES_GOOMY]            = (),

    [SPECIES_SLIGGOO]          = (),

    [SPECIES_GOODRA]           = (),

    [SPECIES_KLEFKI]           = (),

    [SPECIES_PHANTUMP]         = (),

    [SPECIES_TREVENANT]        = (),

    [SPECIES_PUMPKABOO]        = (),

    [SPECIES_GOURGEIST]        = (),

    [SPECIES_BERGMITE]         = (),

    [SPECIES_AVALUGG]          = (),

    [SPECIES_NOIBAT]           = (),

    [SPECIES_NOIVERN]          = (),

    [SPECIES_XERNEAS]          = (),

    [SPECIES_YVELTAL]          = (),

    [SPECIES_ZYGARDE]          = (),

    [SPECIES_DIANCIE]          = (),

    [SPECIES_HOOPA]            = (),

    [SPECIES_VOLCANION]        = (),

    [SPECIES_ROWLET]           = (),

    [SPECIES_DARTRIX]          = (),

    [SPECIES_DECIDUEYE]        = (),

    [SPECIES_LITTEN]           = (),

    [SPECIES_TORRACAT]         = (),

    [SPECIES_INCINEROAR]       = (),

    [SPECIES_POPPLIO]          = (),

    [SPECIES_BRIONNE]          = (),

    [SPECIES_PRIMARINA]        = (),

    [SPECIES_PIKIPEK]          = (),

    [SPECIES_TRUMBEAK]         = (),

    [SPECIES_TOUCANNON]        = (),

    [SPECIES_YUNGOOS]          = (),

    [SPECIES_GUMSHOOS]         = (),

    [SPECIES_GRUBBIN]          = (),

    [SPECIES_CHARJABUG]        = (),

    [SPECIES_VIKAVOLT]         = (),

    [SPECIES_CRABRAWLER]       = (),

    [SPECIES_CRABOMINABLE]     = (),

    [SPECIES_ORICORIO]         = (),

    [SPECIES_CUTIEFLY]         = (),

    [SPECIES_RIBOMBEE]         = (),

    [SPECIES_ROCKRUFF]         = (),

    [SPECIES_LYCANROC]         = (),

    [SPECIES_WISHIWASHI]       = (),

    [SPECIES_MAREANIE]         = (),

    [SPECIES_TOXAPEX]          = (),

    [SPECIES_MUDBRAY]          = (),

    [SPECIES_MUDSDALE]         = (),

    [SPECIES_DEWPIDER]         = (),

    [SPECIES_ARAQUANID]        = (),

    [SPECIES_FOMANTIS]         = (),

    [SPECIES_LURANTIS]         = (),

    [SPECIES_MORELULL]         = (),

    [SPECIES_SHIINOTIC]        = (),

    [SPECIES_SALANDIT]         = (),

    [SPECIES_SALAZZLE]         = (),

    [SPECIES_STUFFUL]          = (),

    [SPECIES_BEWEAR]           = (),

    [SPECIES_BOUNSWEET]        = (),

    [SPECIES_STEENEE]          = (),

    [SPECIES_TSAREENA]         = (),

    [SPECIES_COMFEY]           = (),

    [SPECIES_ORANGURU]         = (),

    [SPECIES_PASSIMIAN]        = (),

    [SPECIES_WIMPOD]           = (),

    [SPECIES_GOLISOPOD]        = (),

    [SPECIES_SANDYGAST]        = (),

    [SPECIES_PALOSSAND]        = (),

    [SPECIES_PYUKUMUKU]        = (),

    [SPECIES_TYPE_NULL]        = (),

    [SPECIES_SILVALLY]         = (),

    [SPECIES_MINIOR]           = (),

    [SPECIES_KOMALA]           = (),

    [SPECIES_TURTONATOR]       = (),

    [SPECIES_TOGEDEMARU]       = (),

    [SPECIES_MIMIKYU]          = (),

    [SPECIES_BRUXISH]          = (),

    [SPECIES_DRAMPA]           = (),

    [SPECIES_DHELMISE]         = (),

    [SPECIES_JANGMO_O]         = (),

    [SPECIES_HAKAMO_O]         = (),

    [SPECIES_KOMMO_O]          = (),

    [SPECIES_TAPU_KOKO]        = (),

    [SPECIES_TAPU_LELE]        = (),

    [SPECIES_TAPU_BULU]        = (),

    [SPECIES_TAPU_FINI]        = (),

    [SPECIES_COSMOG]           = (),

    [SPECIES_COSMOEM]          = (),

    [SPECIES_SOLGALEO]         = (),

    [SPECIES_LUNALA]           = (),

    [SPECIES_NIHILEGO]         = (),

    [SPECIES_BUZZWOLE]         = (),

    [SPECIES_PHEROMOSA]        = (),

    [SPECIES_XURKITREE]        = (),

    [SPECIES_CELESTEELA]       = (),

    [SPECIES_KARTANA]          = (),

    [SPECIES_GUZZLORD]         = (),

    [SPECIES_NECROZMA]         = (),

    [SPECIES_MAGEARNA]         = (),

    [SPECIES_MARSHADOW]        = (),

    [SPECIES_POIPOLE]          = (),

    [SPECIES_NAGANADEL]        = (),

    [SPECIES_STAKATAKA]        = (),

    [SPECIES_BLACEPHALON]      = (),

    [SPECIES_ZERAORA]          = (),

    [SPECIES_MELTAN]           = (),

    [SPECIES_MELMETAL]         = (),

    [SPECIES_GROOKEY]          = (),

    [SPECIES_THWACKEY]         = (),

    [SPECIES_RILLABOOM]        = (),

    [SPECIES_SCORBUNNY]        = (),

    [SPECIES_RABOOT]           = (),

    [SPECIES_CINDERACE]        = (),

    [SPECIES_SOBBLE]           = (),

    [SPECIES_DRIZZILE]         = (),

    [SPECIES_INTELEON]         = (),

    [SPECIES_SKWOVET]          = (),

    [SPECIES_GREEDENT]         = (),

    [SPECIES_ROOKIDEE]         = (),

    [SPECIES_CORVISQUIRE]      = (),

    [SPECIES_CORVIKNIGHT]      = (),

    [SPECIES_BLIPBUG]          = (),

    [SPECIES_DOTTLER]          = (),

    [SPECIES_ORBEETLE]         = (),

    [SPECIES_NICKIT]           = (),

    [SPECIES_THIEVUL]          = (),

    [SPECIES_GOSSIFLEUR]       = (),

    [SPECIES_ELDEGOSS]         = (),

    [SPECIES_WOOLOO]           = (),

    [SPECIES_DUBWOOL]          = (),

    [SPECIES_CHEWTLE]          = (),

    [SPECIES_DREDNAW]          = (),

    [SPECIES_YAMPER]           = (),

    [SPECIES_BOLTUND]          = (),

    [SPECIES_ROLYCOLY]         = (),

    [SPECIES_CARKOL]           = (),

    [SPECIES_COALOSSAL]        = (),

    [SPECIES_APPLIN]           = (),

    [SPECIES_FLAPPLE]          = (),

    [SPECIES_APPLETUN]         = (),

    [SPECIES_SILICOBRA]        = (),

    [SPECIES_SANDACONDA]       = (),

    [SPECIES_CRAMORANT]        = (),

    [SPECIES_ARROKUDA]         = (),

    [SPECIES_BARRASKEWDA]      = (),

    [SPECIES_TOXEL]            = (),

    [SPECIES_TOXTRICITY]       = (),

    [SPECIES_SIZZLIPEDE]       = (),

    [SPECIES_CENTISKORCH]      = (),

    [SPECIES_CLOBBOPUS]        = (),

    [SPECIES_GRAPPLOCT]        = (),

    [SPECIES_SINISTEA]         = (),

    [SPECIES_POLTEAGEIST]      = (),

    [SPECIES_HATENNA]          = (),

    [SPECIES_HATTREM]          = (),

    [SPECIES_HATTERENE]        = (),

    [SPECIES_IMPIDIMP]         = (),

    [SPECIES_MORGREM]          = (),

    [SPECIES_GRIMMSNARL]       = (),

    [SPECIES_OBSTAGOON]        = (),

    [SPECIES_PERRSERKER]       = (),

    [SPECIES_CURSOLA]          = (),

    [SPECIES_SIRFETCHD]        = (),

    [SPECIES_MR_RIME]          = (),

    [SPECIES_RUNERIGUS]        = (),

    [SPECIES_MILCERY]          = (),

    [SPECIES_ALCREMIE]         = (),

    [SPECIES_FALINKS]          = (),

    [SPECIES_PINCURCHIN]       = (),

    [SPECIES_SNOM]             = (),

    [SPECIES_FROSMOTH]         = (),

    [SPECIES_STONJOURNER]      = (),

    [SPECIES_EISCUE]           = (),

    [SPECIES_INDEEDEE]         = (),

    [SPECIES_MORPEKO]          = (),

    [SPECIES_CUFANT]           = (),

    [SPECIES_COPPERAJAH]       = (),

    [SPECIES_DRACOZOLT]        = (),

    [SPECIES_ARCTOZOLT]        = (),

    [SPECIES_DRACOVISH]        = (),

    [SPECIES_ARCTOVISH]        = (),

    [SPECIES_DURALUDON]        = (),

    [SPECIES_DREEPY]           = (),

    [SPECIES_DRAKLOAK]         = (),

    [SPECIES_DRAGAPULT]        = (),

    [SPECIES_ZACIAN]           = (),

    [SPECIES_ZAMAZENTA]        = (),

    [SPECIES_ETERNATUS]        = (),

    [SPECIES_KUBFU]            = (),

    [SPECIES_URSHIFU]          = (),

    [SPECIES_ZARUDE]           = (),

    [SPECIES_REGIELEKI]        = (),

    [SPECIES_REGIDRAGO]        = (),

    [SPECIES_GLASTRIER]        = (),

    [SPECIES_SPECTRIER]        = (),

    [SPECIES_CALYREX]          = (),

    [SPECIES_WYRDEER]          = (),

    [SPECIES_KLEAVOR]          = (),

    [SPECIES_URSALUNA]         = (),

    [SPECIES_BASCULEGION]      = (),

    [SPECIES_SNEASLER]         = (),

    [SPECIES_OVERQWIL]         = (),

    [SPECIES_ENAMORUS]         = (),

    [SPECIES_RATTATA_ALOLAN]   = (),

    [SPECIES_RATICATE_ALOLAN]  = (),

    [SPECIES_RAICHU_ALOLAN]    = (),

    [SPECIES_SANDSHREW_ALOLAN] = (),

    [SPECIES_SANDSLASH_ALOLAN] = (),

    [SPECIES_VULPIX_ALOLAN]    = (),

    [SPECIES_NINETALES_ALOLAN] = (),

    [SPECIES_DIGLETT_ALOLAN]   = (),

    [SPECIES_DUGTRIO_ALOLAN]   = (),

    [SPECIES_MEOWTH_ALOLAN]    = (),

    [SPECIES_PERSIAN_ALOLAN]   = (),

    [SPECIES_GEODUDE_ALOLAN]   = (),

    [SPECIES_GRAVELER_ALOLAN]  = (),

    [SPECIES_GOLEM_ALOLAN]     = (),

    [SPECIES_GRIMER_ALOLAN]    = (),

    [SPECIES_MUK_ALOLAN]       = (),

    [SPECIES_EXEGGUTOR_ALOLAN] = (),

    [SPECIES_MAROWAK_ALOLAN]   = (),

    [SPECIES_MEOWTH_GALARIAN]  = (),

    [SPECIES_PONYTA_GALARIAN]  = (),

    [SPECIES_RAPIDASH_GALARIAN]= (),

    [SPECIES_SLOWPOKE_GALARIAN]= (),

    [SPECIES_SLOWBRO_GALARIAN] = (),

    [SPECIES_FARFETCHD_GALARIAN]= (),

    [SPECIES_WEEZING_GALARIAN] = (),

    [SPECIES_MR_MIME_GALARIAN] = (),

    [SPECIES_ARTICUNO_GALARIAN]= (),

    [SPECIES_ZAPDOS_GALARIAN]  = (),

    [SPECIES_MOLTRES_GALARIAN] = (),

    [SPECIES_SLOWKING_GALARIAN]= (),

    [SPECIES_CORSOLA_GALARIAN] = (),

    [SPECIES_ZIGZAGOON_GALARIAN]= (),

    [SPECIES_LINOONE_GALARIAN] = (),

    [SPECIES_DARUMAKA_GALARIAN]= (),

    [SPECIES_DARMANITAN_GALARIAN]= (),

    [SPECIES_YAMASK_GALARIAN]  = (),

    [SPECIES_STUNFISK_GALARIAN]= (),

    [SPECIES_DEOXYS_ATTACK]    = (),

    [SPECIES_DEOXYS_DEFENSE]   = (),

    [SPECIES_DEOXYS_SPEED]     = (),

    [SPECIES_WORMADAM_SANDY_CLOAK]= (),

    [SPECIES_WORMADAM_TRASH_CLOAK]= (),

    [SPECIES_ROTOM_HEAT]       = (),

    [SPECIES_ROTOM_WASH]       = (),

    [SPECIES_ROTOM_FROST]      = (),

    [SPECIES_ROTOM_FAN]        = (),

    [SPECIES_ROTOM_MOW]        = (),

    [SPECIES_SHAYMIN_SKY]      = (),

    [SPECIES_KYUREM_BLACK]     = (),

    [SPECIES_KYUREM_WHITE]     = (),

    [SPECIES_FLOETTE_ETERNAL_FLOWER]= (),

    [SPECIES_MEOWSTIC_FEMALE]  = (),

    [SPECIES_HOOPA_UNBOUND]    = (),

    [SPECIES_LYCANROC_MIDNIGHT]= (),

    [SPECIES_LYCANROC_DUSK]    = (),

    [SPECIES_TOXTRICITY_LOW_KEY]= (),

    [SPECIES_INDEEDEE_FEMALE]  = (),

    [SPECIES_URSHIFU_RAPID_STRIKE_STYLE]= (),

    [SPECIES_CALYREX_ICE_RIDER]= (),

    [SPECIES_CALYREX_SHADOW_RIDER]= (),

    [SPECIES_GROWLITHE_HISUIAN]= (),

    [SPECIES_ARCANINE_HISUIAN] = (),

    [SPECIES_VOLTORB_HISUIAN]  = (),

    [SPECIES_ELECTRODE_HISUIAN]= (),

    [SPECIES_TYPHLOSION_HISUIAN]= (),

    [SPECIES_QWILFISH_HISUIAN] = (),

    [SPECIES_SNEASEL_HISUIAN]  = (),

    [SPECIES_SAMUROTT_HISUIAN] = (),

    [SPECIES_LILLIGANT_HISUIAN]= (),

    [SPECIES_BASCULIN_WHITE_STRIPED]= (),

    [SPECIES_ZORUA_HISUIAN]    = (),

    [SPECIES_ZOROARK_HISUIAN]  = (),

    [SPECIES_BRAVIARY_HISUIAN] = (),

    [SPECIES_SLIGGOO_HISUIAN]  = (),

    [SPECIES_GOODRA_HISUIAN]   = (),

    [SPECIES_AVALUGG_HISUIAN]  = (),

    [SPECIES_DECIDUEYE_HISUIAN]= (),

    [SPECIES_TAUROS_PALDEAN_COMBAT_BREED]= (),

    [SPECIES_TAUROS_PALDEAN_BLAZE_BREED]= (),

    [SPECIES_TAUROS_PALDEAN_AQUA_BREED]= (),

    [SPECIES_WOOPER_PALDEAN]   = (),

    [SPECIES_SPRIGATITO]       = (),

    [SPECIES_FLORAGATO]        = (),

    [SPECIES_MEOWSCARADA]      = (),

    [SPECIES_FUECOCO]          = (),

    [SPECIES_CROCALOR]         = (),

    [SPECIES_SKELEDIRGE]       = (),

    [SPECIES_QUAXLY]           = (),

    [SPECIES_QUAXWELL]         = (),

    [SPECIES_QUAQUAVAL]        = (),

    [SPECIES_LECHONK]          = (),

    [SPECIES_OINKOLOGNE]       = (),

    [SPECIES_TAROUNTULA]       = (),

    [SPECIES_SPIDOPS]          = (),

    [SPECIES_NYMBLE]           = (),

    [SPECIES_LOKIX]            = (),

    [SPECIES_PAWMI]            = (),

    [SPECIES_PAWMO]            = (),

    [SPECIES_PAWMOT]           = (),

    [SPECIES_TANDEMAUS]        = (),

    [SPECIES_MAUSHOLD]         = (),

    [SPECIES_FIDOUGH]          = (),

    [SPECIES_DACHSBUN]         = (),

    [SPECIES_SMOLIV]           = (),

    [SPECIES_DOLLIV]           = (),

    [SPECIES_ARBOLIVA]         = (),

    [SPECIES_SQUAWKABILLY]     = (),

    [SPECIES_NACLI]            = (),

    [SPECIES_NACLSTACK]        = (),

    [SPECIES_GARGANACL]        = (),

    [SPECIES_CHARCADET]        = (),

    [SPECIES_ARMAROUGE]        = (),

    [SPECIES_CERULEDGE]        = (),

    [SPECIES_TADBULB]          = (),

    [SPECIES_BELLIBOLT]        = (),

    [SPECIES_WATTREL]          = (),

    [SPECIES_KILOWATTREL]      = (),

    [SPECIES_MASCHIFF]         = (),

    [SPECIES_MABOSSTIFF]       = (),

    [SPECIES_SHROODLE]         = (),

    [SPECIES_GRAFAIAI]         = (),

    [SPECIES_BRAMBLIN]         = (),

    [SPECIES_BRAMBLEGHAST]     = (),

    [SPECIES_TOEDSCOOL]        = (),

    [SPECIES_TOEDSCRUEL]       = (),

    [SPECIES_KLAWF]            = (),

    [SPECIES_CAPSAKID]         = (),

    [SPECIES_SCOVILLAIN]       = (),

    [SPECIES_RELLOR]           = (),

    [SPECIES_RABSCA]           = (),

    [SPECIES_FLITTLE]          = (),

    [SPECIES_ESPATHRA]         = (),

    [SPECIES_TINKATINK]        = (),

    [SPECIES_TINKATUFF]        = (),

    [SPECIES_TINKATON]         = (),

    [SPECIES_WIGLETT]          = (),

    [SPECIES_WUGTRIO]          = (),

    [SPECIES_BOMBIRDIER]       = (),

    [SPECIES_FINIZEN]          = (),

    [SPECIES_PALAFIN_ZERO]     = (),

    [SPECIES_VAROOM]           = (),

    [SPECIES_REVAVROOM]        = (),

    [SPECIES_CYCLIZAR]         = (),

    [SPECIES_ORTHWORM]         = (),

    [SPECIES_GLIMMET]          = (),

    [SPECIES_GLIMMORA]         = (),

    [SPECIES_GREAVARD]         = (),

    [SPECIES_HOUNDSTONE]       = (),

    [SPECIES_FLAMIGO]          = (),

    [SPECIES_CETODDLE]         = (),

    [SPECIES_CETITAN]          = (),

    [SPECIES_VELUZA]           = (),

    [SPECIES_DONDOZO]          = (),

    [SPECIES_TATSUGIRI]        = (),

    [SPECIES_ANNIHILAPE]       = (),

    [SPECIES_CLODSIRE]         = (),

    [SPECIES_FARIGIRAF]        = (),

    [SPECIES_DUDUNSPARCE]      = (),

    [SPECIES_KINGAMBIT]        = (),

    [SPECIES_GREAT_TUSK]       = (),

    [SPECIES_SCREAM_TAIL]      = (),

    [SPECIES_BRUTE_BONNET]     = (),

    [SPECIES_FLUTTER_MANE]     = (),

    [SPECIES_SLITHER_WING]     = (),

    [SPECIES_SANDY_SHOCKS]     = (),

    [SPECIES_IRON_TREADS]      = (),

    [SPECIES_IRON_BUNDLE]      = (),

    [SPECIES_IRON_HANDS]       = (),

    [SPECIES_IRON_JUGULIS]     = (),

    [SPECIES_IRON_MOTH]        = (),

    [SPECIES_IRON_THORNS]      = (),

    [SPECIES_FRIGIBAX]         = (),

    [SPECIES_ARCTIBAX]         = (),

    [SPECIES_BAXCALIBUR]       = (),

    [SPECIES_GIMMIGHOUL_CHEST] = (),

    [SPECIES_GHOLDENGO]        = (),

    [SPECIES_WO_CHIEN]         = (),

    [SPECIES_CHIEN_PAO]        = (),

    [SPECIES_TING_LU]          = (),

    [SPECIES_CHI_YU]           = (),

    [SPECIES_ROARING_MOON]     = (),

    [SPECIES_IRON_VALIANT]     = (),

    [SPECIES_KORAIDON]         = (),

    [SPECIES_MIRAIDON]         = (),

    [SPECIES_WALKING_WAKE]     = (),

    [SPECIES_IRON_LEAVES]      = (),

    [SPECIES_PIKACHU_PARTNER]  = (),

    [SPECIES_EEVEE_PARTNER]    = (),

};
