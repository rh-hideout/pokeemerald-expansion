@ Due to the way mks4agb (Nintendo's tool) works, key split table labels can
@ appear before the actual start of the key split table data. If you look at
@ the first keysplit table (keysplit_piano), you'll notice it's offset backwards
@ by 36 bytes. This is because the key split tables don't map instruments
@ for the entire note range (0-127)--they only map subsets, and the upper
@ and lower ranges aren't necessarily 0 or 127.
@
@ For example if a key split table maps an note range of 10-20, then the key
@ split table label will be offset 10 bytes before the actual key split data
@ begins. Therefore, the notes naturally map to the key split table without
@ any extra offset calculation.

keysplit piano, 36
	split 0, 55
	split 1, 70
	split 2, 91
	split 3, 108

keysplit strings, 36
	split 0, 69
	split 1, 81
	split 2, 108

keysplit trumpet, 36
	split 0, 66
	split 1, 84
	split 2, 108

keysplit tuba, 24
	split 0, 42
	split 1, 108

keysplit french_horn, 36
	split 0, 66
	split 1, 108

keysplit dp_piano_1, 0             @ .set KeySplitTable6, . - 0    @ | 43 | 57 | 64 | 71 | 76 | 83 | 88
    split 0, 43
    split 1, 57
    split 2, 64
    split 3, 71
    split 4, 76
    split 5, 83
    split 6, 88
	split 7, 127

keysplit dp_piano_2, 0             @ .set KeySplitTable7, . - 0    @ | 30
    split 0, 30
    split 1, 127

keysplit dp_electric_piano_1, 0    @ .set KeySplitTable8, . - 0    @ | 54
    split 0, 54
    split 1, 127

keysplit dp_electric_piano_2_rhodes, 0 @ .set KeySplitTable9, . - 0    @ | 55
	split 0, 55
	split 1, 127

keysplit dp_clavinet, 0            @ .set KeySplitTable10, . - 0    @ | 43 | 57
    split 0, 43
    split 1, 57
    split 2, 127

keysplit dp_vibraphone, 0          @ .set KeySplitTable11, . - 0    @ | 47 | 59 | 71 | 83 | 95
    split 0, 47
    split 1, 59
    split 2, 71
    split 3, 83
    split 4, 95
    split 5, 127

keysplit dp_marimba, 0             @ .set KeySplitTable12, . - 0    @ | 71 | 83
    split 0, 71
    split 1, 83
    split 2, 127

keysplit dp_xylophone, 0           @ .set KeySplitTable13, . - 0    @ | 48 | 65 | 76 | 88
    split 0, 48
    split 1, 65
    split 2, 76
    split 3, 88
    split 4, 127

keysplit dp_tubular_bell, 0        @ .set KeySplitTable14, . - 0    @ | 66 | 78 | 90
    split 0, 66
    split 1, 78
    split 2, 90
    split 3, 127

keysplit dp_trinity_piano, 0       @ .set KeySplitTable15, . - 0    @ | 36 | 52 | 67
    split 0, 36
    split 1, 52
    split 2, 67
    split 3, 127

keysplit dp_rotary_organ, 0        @ .set KeySplitTable16, . - 0    @ | 59 | 77 | 89
    split 0, 59
    split 1, 77
    split 2, 89
    split 3, 127

keysplit dp_straight_organ, 0      @ .set KeySplitTable17, . - 0    @ | 59
    split 0, 59
    split 1, 127

keysplit dp_accordion, 0           @ .set KeySplitTable18, . - 0    @ | 35 | 47 | 59
    split 0, 35
    split 1, 47
    split 2, 59
    split 3, 127

keysplit dp_accoustic_guitar, 0    @ .set KeySplitTable19, . - 0    @ | 45 | 57 | 69
    split 0, 45
    split 1, 57
    split 2, 69
    split 3, 127

keysplit dp_clean_guitar, 0        @ .set KeySplitTable20, . - 0    @ | 47 | 59
    split 0, 47
    split 1, 59
    split 2, 127

keysplit dp_distortion_guitar_1, 0 @ .set KeySplitTable21, . - 0    @ | 47 | 60 | 72 | 79
    split 0, 47
    split 1, 60
    split 2, 72
    split 3, 79
    split 4, 127

keysplit dp_power_guitar, 0        @ .set KeySplitTable22, . - 0    @ | 43 | 50
    split 0, 43
    split 1, 50
    split 2, 127

keysplit dp_wood_bass, 0           @ .set KeySplitTable23, . - 0    @ | 34 | 47
    split 0, 34
    split 1, 47
    split 2, 127

keysplit dp_violin, 0              @ .set KeySplitTable24, . - 0    @ | 47 | 69 | 88
    split 0, 47
    split 1, 69
    split 2, 88
    split 3, 127

keysplit dp_pizzicato_music_box, 0 @ .set KeySplitTable25, . - 0    @ | 71
	split 0, 71
	split 1, 127

keysplit dp_harp, 0                @ .set KeySplitTable26, . - 0    @ | 71 | 83 | 95
    split 0, 71
    split 1, 83
    split 2, 95
    split 3, 127

keysplit dp_timpani, 0             @ .set KeySplitTable27, . - 0    @ | 48
	split 0, 48
	split 1, 127

keysplit dp_strings, 0             @ .set KeySplitTable28, . - 0    @ | 43 | 53 | 69
    split 0, 43
    split 1, 53
    split 2, 69
    split 3, 127

keysplit dp_trumpet, 0             @ .set KeySplitTable29, . - 0    @ | 64 | 84
	split 0, 64
	split 1, 84
	split 2, 127

keysplit dp_trombone, 0            @ .set KeySplitTable30, . - 0    @ | 52 | 62
	split 0, 52
	split 1, 62
	split 2, 127

keysplit dp_tuba, 0                @ .set KeySplitTable31, . - 0    @ | 31
	split 0, 31
	split 1, 127

keysplit dp_distortion_guitar_2, 0 @ .set KeySplitTable32, . - 0    @ | 47 | 60 | 72
	split 0, 47
	split 1, 60
	split 2, 72
	split 3, 127

keysplit dp_flute, 0               @ .set KeySplitTable33, . - 0    @ | 72 | 89
	split 0, 72
	split 1, 89
	split 2, 127

keysplit dp_banjo, 0               @ .set KeySplitTable34, . - 0    @ | 57
	split 0, 57
	split 1, 127

keysplit hgss_piano_1, 0           @ .set KeySplitTable35, . - 0    @ | 43 | 55 | 67 | 79
	split 0, 43
	split 1, 55
	split 2, 67
	split 3, 79
	split 4, 127

keysplit hgss_piano_2_vibraphone_glockglockenspiel, 0 @ .set KeySplitTable36, . - 0    @ | 67
	split 0, 67
	split 1, 127

keysplit hgss_piano_3, 0           @ .set KeySplitTable37, . - 0    @ | 43 | 55 | 67
	split 0, 43
	split 1, 55
	split 2, 67
	split 3, 127

keysplit hgss_marimba_music_box_sampled_square, 0 @ .set KeySplitTable38, . - 0    @ | 67 | 79
	split 0, 67
	split 1, 79
	split 2, 127

keysplit hgss_xylophone_trumpet, 0 @ .set KeySplitTable39, . - 0    @ | 65 | 74
	split 0, 65
	split 1, 74
	split 2, 127

keysplit hgss_organ_accordion_harp_timpani, 0 @ .set KeySplitTable40, . - 0    @ | 55 | 67
	split 0, 55
	split 1, 67
	split 2, 127

keysplit hgss_guitar, 0            @ .set KeySplitTable41, . - 0    @ | 52 | 60 | 69
	split 0, 52
	split 1, 60
	split 2, 69
	split 3, 127

keysplit hgss_upright_bass, 0      @ .set KeySplitTable42, . - 0    @ | 45
	split 0, 45
	split 1, 127

keysplit hgss_fingered_bass, 0     @ .set KeySplitTable43, . - 0    @ | 53
	split 0, 53
	split 1, 127

keysplit hgss_synth_bass, 0        @ .set KeySplitTable44, . - 0    @ | 43
	split 0, 43
	split 1, 127

keysplit hgss_strings, 0           @ .set KeySplitTable45, . - 0    @ | 65 | 74 | 83
	split 0, 65
	split 1, 74
	split 2, 83
	split 3, 127

keysplit hgss_violin, 0            @ .set KeySplitTable46, . - 0    @ | 69 | 77
	split 0, 69
	split 1, 77
	split 2, 127

keysplit hgss_cello_trombone, 0    @ .set KeySplitTable47, . - 0    @ | 48 | 57
	split 0, 48
	split 1, 57
	split 2, 127

keysplit hgss_pizzicato, 0         @ .set KeySplitTable48, . - 0    @ | 48 | 57 | 65 | 74
	split 0, 48
	split 1, 57
	split 2, 65
	split 4, 74
	split 5, 127

keysplit hgss_french_horn_solo, 0  @ .set KeySplitTable49, . - 0    @ | 60 | 65
	split 0, 60
	split 1, 65
	split 2, 127

keysplit hgss_french_horn, 0       @ .set KeySplitTable50, . - 0    @ | 53 | 62
	split 0, 53
	split 1, 62
	split 2, 127

keysplit hgss_oboe, 0              @ .set KeySplitTable51, . - 0    @ | 69 | 76
	split 0, 69
	split 1, 76
	split 2, 127

keysplit hgss_clarinet, 0          @ .set KeySplitTable52, . - 0    @ | 60 | 69
	split 0, 60
	split 1, 69
	split 2, 127

keysplit hgss_flute, 0             @ .set KeySplitTable53, . - 0    @ | 65 | 74 | 81
	split 0, 65
	split 1, 74
	split 2, 81
	split 3, 127

keysplit hgss_bassoon, 0           @ .set KeySplitTable54, . - 0    @ | 45 | 53
	split 0, 45
	split 1, 53
	split 2, 127

keysplit hgss_orchestral_hit, 0    @ .set KeySplitTable55, . - 0    @ | 67 | 76 | 82
	split 0, 67
	split 1, 76
	split 2, 82
	split 3, 127

keysplit hgss_koto, 0              @ .set KeySplitTable56, . - 0    @ | 57 | 67
	split 0, 57
	split 1, 67
	split 2, 127

keysplit hgss_shamisen, 0          @ .set KeySplitTable57, . - 0    @ | 55 | 64
	split 0, 55
	split 1, 64
	split 2, 127

keysplit hgss_piano_4, 0           @ .set KeySplitTable58, . - 0    @ | 41 | 50 | 59 | 67 | 76 | 84
	split 0, 41
	split 1, 50
	split 2, 59
	split 3, 67
	split 4, 76
	split 5, 84
	split 6, 127

keysplit piano_custom, 0           @ .set KeySplitTableGBAPiano1Custom, . - 0
	split 0, 55
	split 1, 70
	split 2, 91
	split 3, 127

keysplit strings_custom, 0         @.set KeySplitTableGBAStringEnsembleCustom, . - 0
	split 0, 69
	split 1, 81
	split 2, 127

keysplit trumpet_custom, 0         @ .set KeySplitTableGBATrumpetCustom, . - 0
	split 0, 66
	split 1, 84
	split 2, 127

keysplit tuba_custom, 0            @ .set KeySplitTableGBATubaCustom, . - 0
	split 0, 42
	split 1, 127

keysplit french_horn_custom, 0     @ .set KeySplitTableGBAFrenchHornCustom, . - 0
	split 0, 66
	split 1, 127
