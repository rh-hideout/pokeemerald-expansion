voice_group bw_main_1                                                                                        @ Num | Substitute Instrument     |  Original BW
	voice_keysplit voicegroup_piano_keysplit, keysplit_piano_custom                                          @ 000 | RSE Piano                 |  voice_keysplit voicegroup323, KeySplitTable59    @ piano (all splits)
	voice_keysplit voicegroup_keysplit_hgss_piano_1, keysplit_hgss_piano_1                                   @ 001 | HGSS Piano                |  voice_keysplit voicegroup233, KeySplitTable35    @ piano (HGSS)
	voice_keysplit voicegroup_keysplit_hgss_piano_2, keysplit_hgss_piano_2_vibraphone_glockglockenspiel      @ 002 | HGSS Piano 2              |  voice_keysplit voicegroup323, KeySplitTable75    @ piano | 41 | 50 ||||| 77
	voice_keysplit voicegroup_keysplit_hgss_rhodes_1, keysplit_dp_electric_piano_2_rhodes                    @ 003 | HGSS Rhodes 1             |  voice_keysplit voicegroup294, KeySplitTable36    @ rhodes
	voice_keysplit voicegroup_keysplit_hgss_rhodes_2, keysplit_dp_electric_piano_2_rhodes                    @ 004 | HGSS Rhodes 2             |  voice_keysplit voicegroup304, KeySplitTable63    @ xtransceiver tone
	voice_keysplit voicegroup_keysplit_hgss_vibraphone, keysplit_hgss_piano_2_vibraphone_glockglockenspiel   @ 005 | HGSS Vibraphone           |  voice_directsound 60, 0, DirectSoundWaveData_bw_vibrc5_pc, 255, 248, 2, 205
	voice_directsound 60, 0, DirectSoundWaveData_unknown_koto_high, 255, 0, 206, 242                         @ 006 | RSE Koto High             |  voice_keysplit voicegroup290, KeySplitTable70    @ harpsichord
	voice_keysplit voicegroup_keysplit_hgss_marimba, keysplit_hgss_marimba_music_box_sampled_square          @ 007 | HGSS Marimba              |  voice_keysplit voicegroup295, KeySplitTable74    @ marimba
	voice_directsound 60, 0, DirectSoundWaveData_unknown_koto_low, 255, 0, 206, 242                          @ 008 | RSE Koto Low              |  voice_directsound 60, 0, DirectSoundWaveData_bw_xtransceiverbeep, 255, 0, 255, 205
	voice_directsound 60, 0, DirectSoundWaveData_hg_jinglebell, 255, 0, 255, 171                             @ 009 | HGSS Jingle Bell          |  voice_directsound 60, 0, DirectSoundWaveData_bw_bellg3_evo, 255, 248, 0, 205
	voice_keysplit voicegroup_keysplit_hgss_vibraphone, keysplit_hgss_piano_2_vibraphone_glockglockenspiel   @ 010 | HGSS Vibraphone           |  voice_keysplit voicegroup297, KeySplitTable76    @ vibraphone
	voice_keysplit voicegroup_keysplit_hgss_marimba, keysplit_hgss_marimba_music_box_sampled_square          @ 011 | HGSS Marimba              |  voice_keysplit voicegroup239, KeySplitTable38    @ marimba (HGSS)
	voice_keysplit voicegroup_keysplit_hgss_xylophone, keysplit_hgss_xylophone_trumpet                       @ 012 | HGSS Xylophone            |  voice_keysplit voicegroup240, KeySplitTable39    @ xylophone
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_wind, 67, 243, 155, 224                             @ 013 | HGSS Wind                 |  voice_directsound 60, 0, DirectSoundWaveData_bw_windc4, 255, 0, 255, 0
	voice_directsound 60, 0, DirectSoundWaveData_hg_jinglebell, 255, 0, 255, 171                             @ 014 | HGSS Jingle Bell          |  voice_directsound 60, 0, DirectSoundWaveData_hg_147tbellg4, 255, 248, 0, 205
	voice_keysplit voicegroup_keysplit_hgss_glockenspiel, keysplit_hgss_piano_2_vibraphone_glockglockenspiel @ 015 | HGSS Glockenspiel         |  voice_keysplit voicegroup296, KeySplitTable83    @ glockenspiel
	voice_keysplit voicegroup_keysplit_hgss_music_box, keysplit_hgss_marimba_music_box_sampled_square        @ 016 | HGSS Music Box            |  voice_keysplit voicegroup243, KeySplitTable76    @ music box
	voice_keysplit voicegroup_keysplit_hgss_distortion_guitar_2, keysplit_dp_distortion_guitar_2             @ 017 | HGSS Distortion Guitar 2  |  voice_keysplit voicegroup308, KeySplitTable84    @ lp marschall guitar
	voice_keysplit voicegroup_keysplit_hgss_drawbar_organ, keysplit_hgss_organ_accordion_harp_timpani        @ 018 | HGSS Drawbar Organ        |  voice_keysplit voicegroup244, KeySplitTable71    @ drawbar organ
	voice_keysplit voicegroup_keysplit_hgss_accordion, keysplit_hgss_organ_accordion_harp_timpani            @ 019 | HGSS Accordion            |  voice_keysplit voicegroup291, KeySplitTable71    @ accordion
	voice_keysplit voicegroup_keysplit_hgss_nylon_guitar, keysplit_hgss_guitar                               @ 020 | HGSS Nylon Guitar         |  voice_keysplit voicegroup292, KeySplitTable72    @ nylon str. guitar
	voice_keysplit voicegroup_keysplit_hgss_upright_bass, keysplit_hgss_upright_bass                         @ 021 | HGSS Upright Bass         |  voice_keysplit voicegroup252, KeySplitTable42    @ upright bass
	voice_keysplit voicegroup_keysplit_hgss_nylon_guitar, keysplit_hgss_guitar                               @ 022 | HGSS Nylon Guitar         |  voice_keysplit voicegroup247, KeySplitTable72    @ nylon guitar (HGSS)
	voice_keysplit voicegroup_keysplit_hgss_fingered_bass, keysplit_hgss_fingered_bass                       @ 023 | HGSS Fingered Bass        |  voice_keysplit voicegroup300, KeySplitTable8     @ fingered bass (pokecenter, icirrus)
	voice_keysplit voicegroup_strings_keysplit, keysplit_strings_custom                                      @ 024 | RSE Strings               |  voice_keysplit voicegroup298, KeySplitTable77    @ strings 2
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fretless_bass, 255, 253, 0, 149                     @ 025 | RSE Fretless Bass         |  voice_keysplit voicegroup311, KeySplitTable86    @ fretless bass
	voice_keysplit voicegroup_keysplit_hgss_pizzicato, keysplit_hgss_pizzicato                               @ 026 | HGSS Pizzicato            |  voice_keysplit voicegroup293, KeySplitTable48    @ pizzicato
	voice_keysplit voicegroup_keysplit_hgss_fingered_bass, keysplit_hgss_fingered_bass                       @ 027 | HGSS Fingered Bass        |  voice_keysplit voicegroup253, KeySplitTable43    @ fingered bass
	voice_keysplit voicegroup_keysplit_hgss_clean_guitar, keysplit_hgss_guitar                               @ 028 | HGSS Clean Guitar         |  voice_keysplit voicegroup316, KeySplitTable41    @ clean guitar
	voice_keysplit voicegroup_keysplit_hgss_synth_bass, keysplit_hgss_synth_bass                             @ 029 | HGSS Synth Bass           |  voice_keysplit voicegroup254, KeySplitTable73    @ synth bass
	voice_keysplit voicegroup_keysplit_hgss_strings, keysplit_hgss_strings                                   @ 030 | HGSS Strings              |  voice_keysplit voicegroup255, KeySplitTable60    @ strings
	voice_directsound 60, 0, DirectSoundWaveData_unused_sc88pro_unison_slap, 255, 165, 180, 216              @ 031 | RSE Unison Bass           |  voice_keysplit voicegroup315, KeySplitTable90    @ picked bass (nimbasa)
	voice_keysplit voicegroup_keysplit_hgss_violin, keysplit_hgss_violin                                     @ 032 | HGSS Violin               |  voice_keysplit voicegroup256, KeySplitTable46    @ violin
	voice_keysplit voicegroup_keysplit_hgss_cello, keysplit_hgss_cello_trombone                              @ 033 | HGSS Cello                |  voice_directsound 60, 0, DirectSoundWaveData_hg_021cellog2, 254, 242, 255, 205
	voice_keysplit voicegroup_keysplit_hgss_clarinet, keysplit_hgss_clarinet                                 @ 034 | HGSS Clarinet             |  voice_keysplit voicegroup301, KeySplitTable79    @ clarinet (pokecenter)
	voice_keysplit voicegroup_keysplit_hgss_harp, keysplit_hgss_organ_accordion_harp_timpani                 @ 035 | HGSS Harp                 |  voice_keysplit voicegroup299, KeySplitTable78    @ harp 2
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_harp, 255, 242, 51, 242                             @ 036 | RSE Harp                  |  voice_keysplit voicegroup302, KeySplitTable80    @ harp 1
	voice_keysplit voicegroup_keysplit_hgss_orchestral_hit, keysplit_hgss_orchestral_hit                     @ 037 | HGSS Orchestal Hit        |  voice_directsound 60, 0, DirectSoundWaveData_bw_orchhita3_lowhp, 254, 250, 2, 205
	voice_keysplit voicegroup_keysplit_hgss_timpani, keysplit_hgss_organ_accordion_harp_timpani              @ 038 | HGSS Timpani              |  voice_keysplit voicegroup260, KeySplitTable61    @ timpani
	voice_keysplit voicegroup_keysplit_hgss_trumpet, keysplit_hgss_xylophone_trumpet                         @ 039 | HGSS Trumpets             |  voice_keysplit voicegroup261, KeySplitTable39    @ trumpets
	voice_keysplit voicegroup_keysplit_hgss_trombone, keysplit_hgss_cello_trombone                           @ 040 | HGSS Trombones            |  voice_keysplit voicegroup262, KeySplitTable47    @ trombones
	voice_keysplit voicegroup_keysplit_hgss_martin_guitar, keysplit_hgss_guitar                              @ 041 | HGSS Martin Guitar        |  voice_keysplit voicegroup248, KeySplitTable72    @ martin guitar
	voice_keysplit voicegroup_keysplit_hgss_french_horn_solo, keysplit_hgss_french_horn_solo                 @ 042 | HGSS French Horns Split   |  voice_keysplit voicegroup327, KeySplitTable64    @ french horns (old splits)
	voice_keysplit voicegroup_keysplit_hgss_french_horn, keysplit_hgss_french_horn                           @ 043 | HGSS French Horns         |  voice_keysplit voicegroup327, KeySplitTable41    @ french horns
	voice_keysplit voicegroup_keysplit_hgss_oboe, keysplit_hgss_oboe                                         @ 044 | HGSS Oboe                 |  voice_keysplit voicegroup288, KeySplitTable105   @ oboe
	voice_keysplit voicegroup_keysplit_hgss_clarinet, keysplit_hgss_clarinet                                 @ 045 | HGSS Clarinet             |  voice_keysplit voicegroup266, KeySplitTable52    @ clarinet
	voice_keysplit voicegroup_tuba_keysplit, keysplit_tuba_custom                                            @ 046 | RSE Tuba                  |  voice_keysplit voicegroup305, KeySplitTable44    @ tuba
	voice_keysplit voicegroup_keysplit_hgss_flute, keysplit_hgss_flute                                       @ 047 | HGSS Flute                |  voice_keysplit voicegroup287, KeySplitTable67    @ flute 2
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_flute, 255, 127, 231, 127                           @ 048 | RSE Flute                 |  voice_keysplit voicegroup328, KeySplitTable65    @ flute 1
	voice_square_2_alt 60, 0, 2, 0, 6, 2, 0                                                                  @ 049 | GB Square-2               |  voice_square_2_alt 60, 0, 2, 0, 6, 2, 0
	voice_directsound 60, 0, DirectSoundWaveData_dp_altosax_c3_16, 255, 216, 252, 192                        @ 050 | HGSS Alto Sax             |  voice_keysplit voicegroup314, KeySplitTable89    @ alto sax
	voice_keysplit voicegroup_keysplit_hgss_trombone, keysplit_hgss_cello_trombone                           @ 051 | HGSS Trombone             |  voice_directsound 60, 0, DirectSoundWaveData_bw_trombonesstaccatocs2, 255, 197, 227, 205
	voice_keysplit voicegroup_keysplit_hgss_piano_4, keysplit_hgss_piano_4                                   @ 052 | HGSS Piano/National Park  |  voice_keysplit voicegroup323, KeySplitTable96    @ piano | 44 || 56 || 68 || 80
	voice_keysplit voicegroup_french_horn_keysplit, keysplit_french_horn_custom                              @ 053 | RSE French Horns          |  voice_keysplit voicegroup327, KeySplitTable98    @ french horns | 52 | 53
	voice_keysplit voicegroup_keysplit_hgss_oboe, keysplit_hgss_oboe                                         @ 054 | HGSS Oboe                 |  voice_keysplit voicegroup265, KeySplitTable51    @ oboe (HGSS)
	voice_keysplit voicegroup_keysplit_hgss_french_horn, keysplit_hgss_french_horn                           @ 055 | HGSS French Horns         |  voice_keysplit voicegroup327, KeySplitTable68    @ french horns ||| 69
	voice_keysplit voicegroup_trumpet_keysplit, keysplit_trumpet_custom                                      @ 056 | RSE Trumpets              |  voice_keysplit voicegroup289, KeySplitTable39    @ trumpets (short start)
	voice_keysplit voicegroup_keysplit_hgss_jazz_organ, keysplit_hgss_organ_accordion_harp_timpani           @ 057 | HGSS Jazz Organ           |  voice_keysplit voicegroup245, KeySplitTable71    @ jazz organ
	voice_directsound 60, 0, DirectSoundWaveData_dp_slapbass_c1_16, 255, 0, 255, 192                         @ 058 | HGSS Slap Bass            |  voice_directsound 60, 0, DirectSoundWaveData_dp_slapbass_c1_16, 255, 0, 255, 192
	voice_keysplit voicegroup_keysplit_hgss_nylon_guitar, keysplit_hgss_guitar                               @ 059 | HGSS Nylon Guitar         |  voice_keysplit voicegroup331, KeySplitTable111   @ nylon str. guitar 2 (relic song)
	voice_keysplit voicegroup_trumpet_keysplit, keysplit_trumpet_custom                                      @ 060 | RSE Trumpets              |  voice_keysplit voicegroup261, KeySplitTable112   @ trumpets | 65
	voice_keysplit voicegroup_keysplit_hgss_piano_3, keysplit_hgss_piano_3                                   @ 061 | HGSS Piano Octave         |  voice_keysplit voicegroup234, KeySplitTable36    @ piano 2
	voice_directsound 60, 0, DirectSoundWaveData_dp_reverscyn_16, 255, 0, 255, 16                            @ 062 | HGSS Reverse Cymbal       |  voice_directsound 60, 0, DirectSoundWaveData_bw_reversecymbale2, 255, 0, 255, 236
	voice_directsound 60, 0, DirectSoundWaveData_classical_choir_voice_ahhs, 255, 188, 220, 243              @ 063 | RSE Female Choir          |  voice_keysplit voicegroup324, KeySplitTable62    @ choir male
	voice_directsound 60, 0, DirectSoundWaveData_classical_choir_voice_ahhs, 255, 188, 220, 243              @ 064 | RSE Male Choir            |  voice_keysplit voicegroup325, KeySplitTable63    @ choir female
	voice_directsound 60, 0, DirectSoundWaveData_classical_choir_voice_ahhs, 255, 188, 220, 243              @ 065 | RSE Choir                 |  voice_keysplit voicegroup303, KeySplitTable81    @ choir full
	voice_directsound 60, 0, DirectSoundWaveData_dp_orchhitminor60, 255, 197, 255, 171                       @ 066 | HGSS Orchestral Hit Minor |  voice_directsound 60, 0, DirectSoundWaveData_dp_orchhitminor60, 255, 0, 255, 205
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_detuned_ep1_low, 128, 249, 0, 188            @ 067 | RSE Electric Piano        |  voice_keysplit voicegroup332, KeySplitTable114   @ piano (longer decay)
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 068 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 069 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit voicegroup_keysplit_hgss_tubular_bell, keysplit_dp_pizzicato_music_box                    @ 070 | HGSS Tubular Bell         |  voice_directsound 60, 0, DirectSoundWaveData_bw_gongp, 255, 252, 0, 236
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 071 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 072 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 073 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 074 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_church_organ3_high, 255, 76, 154, 188               @ 075 | RSE Church Organ High     |  voice_keysplit voicegroup319, KeySplitTable97    @ pipe organ
	voice_directsound 60, 0, DirectSoundWaveData_dp_bassdr1, 255, 0, 227, 171                                @ 076 | HGSS Bass Drum Part 1     |  voice_directsound 60, 0, DirectSoundWaveData_bw_steeldrumg4_undella, 255, 251, 0, 205
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 077 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 078 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 079 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 080 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 081 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 082 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 083 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 084 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 085 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 086 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 087 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, DirectSoundWaveData_dp_sawtoothlead60, 255, 197, 255, 171                       @ 088 | HGSS Sawtooth             |  voice_keysplit voicegroup306, KeySplitTable102   @ saw lead | 56
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 089 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit voicegroup_keysplit_hgss_french_horn, keysplit_hgss_french_horn                           @ 090 | HGSS French Horns         |  voice_keysplit voicegroup320, KeySplitTable99    @ french horns p
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 091 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 092 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 093 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 094 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 095 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 096 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 097 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 098 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 099 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, DirectSoundWaveData_dp_synthsnare, 255, 0, 255, 171                             @ 100 | HGSS Bass Drum Part 2     |  voice_directsound 60, 0, DirectSoundWaveData_bw_drumloop_vssubway, 255, 0, 255, 2
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 101 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 1, 6, 0                                                                     @ 102 | GB Noise                  |  voice_directsound 60, 0, DirectSoundWaveData_bw_seashorec4, 255, 0, 255, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 103 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 104 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 105 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 106 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 107 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 108 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 109 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 110 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 111 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 112 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 113 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 114 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 115 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 116 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 117 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 118 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 119 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 2, 0, 6, 2, 0                                                               @ 120 | GB Square-1               |  voice_square_1_alt 60, 0, 0, 2, 0, 6, 2, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 121 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 122 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 123 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 124 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, DirectSoundWaveData_dp_orchhitmajor60, 255, 197, 255, 171                       @ 125 | HGSS Orchestral Hit Major |  voice_directsound 60, 0, DirectSoundWaveData_dp_orchhitmajor60, 255, 0, 255, 205
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                                                  @ 126 | ---                       |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit_all voicegroup_allkeysplit_bw_drum_1                                                      @ 127 | Drum                      |  voice_keysplit_all voicegroup281 @ drums
