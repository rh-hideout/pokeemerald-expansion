	.align 2
voicegroup278::
	voice_keysplit voicegroup005, KeySplitTableGBAPiano1Custom                            @ 000 | RSE Piano |  voice_keysplit voicegroup233, KeySplitTable103   @ piano
	voice_keysplit voicegroup233, KeySplitTable35                                         @ 001 | HGSS Piano |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit voicegroup236, KeySplitTable9                                          @ 002 | HGSS Rhodes 1 |  voice_keysplit voicegroup236, KeySplitTable83    @ rhodes 1
	voice_keysplit voicegroup237, KeySplitTable9                                          @ 003 | HGSS Rhodes 2 |  voice_keysplit voicegroup237, KeySplitTable83    @ rhodes 2
	voice_keysplit voicegroup238, KeySplitTable36                                         @ 004 | HGSS Vibraphone |  voice_keysplit voicegroup238, KeySplitTable83    @ vibraphone
	voice_keysplit voicegroup239, KeySplitTable38                                         @ 005 | HGSS Marimba |  voice_keysplit voicegroup239, KeySplitTable76    @ marimba
	voice_keysplit voicegroup241, KeySplitTable25                                         @ 006 | HGSS Tubular Bell |  voice_keysplit voicegroup241, KeySplitTable25    @ tubular bell
	voice_keysplit voicegroup245, KeySplitTable40                                         @ 007 | HGSS Jazz Organ |  voice_keysplit voicegroup245, KeySplitTable71    @ jazz organ
	voice_keysplit voicegroup247, KeySplitTable41                                         @ 008 | HGSS Nylon Guitar |  voice_keysplit voicegroup247, KeySplitTable41    @ nylon guitar
	voice_keysplit voicegroup250, KeySplitTable32                                         @ 009 | HGSS Distortion Guitar 2 |  voice_keysplit voicegroup250, KeySplitTable32    @ distortion guitar 2
	voice_keysplit voicegroup252, KeySplitTable42                                         @ 010 | HGSS Upright Bass |  voice_keysplit voicegroup252, KeySplitTable42    @ upright bass
	voice_keysplit voicegroup253, KeySplitTable43                                         @ 011 | HGSS Fingered Bass |  voice_keysplit voicegroup253, KeySplitTable43    @ fingered bass
	voice_directsound 60, 0, DirectSoundWaveData_dp_slapbass_c1_16, 255, 0, 255, 192      @ 012 | HGSS Slap Bass |  voice_directsound 60, 0, DirectSoundWaveData_dp_slapbass_c1_16, 255, 0, 255, 192
	voice_keysplit voicegroup255, KeySplitTable45                                         @ 013 | HGSS Strings |  voice_keysplit voicegroup255, KeySplitTable45    @ strings
	voice_keysplit voicegroup258, KeySplitTable48                                         @ 014 | HGSS Pizzicato |  voice_keysplit voicegroup258, KeySplitTable48    @ pizzicato
	voice_keysplit voicegroup259, KeySplitTable40                                         @ 015 | HGSS Harp |  voice_keysplit voicegroup259, KeySplitTable71    @ harp
	voice_keysplit voicegroup260, KeySplitTable40                                         @ 016 | HGSS Timpani |  voice_keysplit voicegroup260, KeySplitTable40    @ timpani
	voice_keysplit voicegroup261, KeySplitTable39                                         @ 017 | HGSS Trumpets |  voice_keysplit voicegroup261, KeySplitTable39    @ trumpets
	voice_keysplit voicegroup264, KeySplitTable50                                         @ 018 | HGSS French Horns |  voice_keysplit voicegroup264, KeySplitTable104   @ french horns
	voice_keysplit voicegroup266, KeySplitTable52                                         @ 019 | HGSS Clarinet |  voice_keysplit voicegroup266, KeySplitTable52    @ clarinet
	voice_keysplit voicegroup267, KeySplitTable53                                         @ 020 | HGSS Flute |  voice_keysplit voicegroup267, KeySplitTable53    @ flute
	voice_keysplit voicegroup269, KeySplitTable55                                         @ 021 | HGSS Orchestra Hit |  voice_keysplit voicegroup269, KeySplitTable105   @ orchestra hit
	voice_keysplit_all voicegroup285                                                      @ 022 | Drum Split |  voice_keysplit_all voicegroup285 @ drums
	voice_square_2_alt 60, 0, 2, 0, 7, 2, 2                                               @ 023 | GB Square-2 |  voice_square_2_alt 60, 0, 2, 0, 7, 2, 2
	voice_programmable_wave_alt 60, 0, ProgrammableWaveData_1, 0, 7, 11, 3                @ 024 | GB Wave |  voice_programmable_wave_alt 60, 0, ProgrammableWaveData_sq37half, 0, 7, 11, 3
	voice_square_2_alt 60, 0, 0, 0, 7, 11, 3                                              @ 025 | GB Square-2 |  voice_square_2_alt 60, 0, 0, 0, 7, 11, 3
	voice_directsound 60, 0, DirectSoundWaveData_puresquare_37, 254, 234, 191, 210        @ 026 | HGSS Pure Square |  voice_directsound 60, 0, DirectSoundWaveData_puresquare_37, 254, 234, 191, 210
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 027 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 028 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 029 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit voicegroup234, KeySplitTable36                                         @ 030 | HGSS Piano 2 |  voice_keysplit voicegroup234, KeySplitTable36    @ piano 2
	voice_keysplit voicegroup236, KeySplitTable9                                          @ 031 | HGSS Rhodes 1 |  voice_keysplit voicegroup294, KeySplitTable36    @ rhodes
	voice_keysplit voicegroup238, KeySplitTable36                                         @ 032 | HGSS Vibraphone |  voice_keysplit voicegroup297, KeySplitTable76    @ vibraphone
	voice_keysplit voicegroup245, KeySplitTable40                                         @ 033 | HGSS Jazz Organ |  voice_keysplit voicegroup245, KeySplitTable71    @ jazz organ
	voice_keysplit voicegroup254, KeySplitTable44                                         @ 034 | HGSS Synth Bass |  voice_keysplit voicegroup254, KeySplitTable73    @ synth bass
	voice_keysplit voicegroup255, KeySplitTable45                                         @ 035 | HGSS Strings |  voice_keysplit voicegroup255, KeySplitTable60    @ strings
	voice_keysplit voicegroup247, KeySplitTable41                                         @ 036 | HGSS Nylon Guitar |  voice_keysplit voicegroup292, KeySplitTable72    @ nylon str. guitar
	voice_keysplit_all voicegroup286                                                      @ 037 | Drum Split |  voice_keysplit_all voicegroup286 @ drums
	voice_keysplit voicegroup253, KeySplitTable43                                         @ 038 | HGSS Fingered Bass |  voice_keysplit voicegroup253, KeySplitTable43    @ fingered bass
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 039 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 040 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 041 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 042 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 043 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 044 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 045 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 046 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 047 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 048 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 049 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 050 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 051 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 052 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 053 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 054 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 055 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 056 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 057 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 058 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 059 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_church_organ3_low, 255, 76, 154, 188 @ 060 | RSE Church Organ |  voice_directsound 60, 0, DirectSoundWaveData_bw_gflogo1, 255, 0, 255, 236
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_church_organ3_low, 255, 76, 154, 188 @ 061 | RSE Church Organ |  voice_directsound 60, 0, DirectSoundWaveData_bw_gflogo2, 255, 0, 255, 236
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_church_organ3_low, 255, 76, 154, 188 @ 062 | RSE Church Organ |  voice_directsound 60, 0, DirectSoundWaveData_bw_gflogo3, 255, 0, 255, 236
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_church_organ3_low, 255, 76, 154, 188 @ 063 | RSE Church Organ |  voice_directsound 60, 0, DirectSoundWaveData_bw_gflogo4, 255, 0, 255, 236
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_church_organ3_low, 255, 76, 154, 188 @ 064 | RSE Church Organ |  voice_directsound 60, 0, DirectSoundWaveData_bw_gflogo5, 255, 0, 255, 236
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 065 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 066 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 067 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 068 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 069 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 070 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 071 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 072 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 073 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 074 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 075 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 076 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 077 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 078 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 079 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 080 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 081 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 082 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 083 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 084 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 085 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 086 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 087 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 088 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 089 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 090 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 091 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 092 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 093 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 094 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 095 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 096 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 097 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 098 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 099 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_church_organ3_low, 255, 76, 154, 188 @ 100 | RSE Church Organ |  voice_directsound 60, 0, DirectSoundWaveData_bw_msl_mellowmunna, 255, 0, 255, 171
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_church_organ3_low, 255, 76, 154, 188 @ 101 | RSE Church Organ |  voice_directsound 60, 0, DirectSoundWaveData_bw_msl_yeah, 255, 0, 255, 171
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_church_organ3_low, 255, 76, 154, 188 @ 102 | RSE Church Organ |  voice_directsound 60, 0, DirectSoundWaveData_bw_msl_thatsright, 255, 0, 255, 171
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_church_organ3_low, 255, 76, 154, 188 @ 103 | RSE Church Organ |  voice_directsound 60, 0, DirectSoundWaveData_bw_msl_crymunna, 255, 0, 255, 171
	voice_directsound 60, 0, DirectSoundWaveData_dp_sawtoothlead60, 255, 0, 255, 171      @ 104 | HGSS Sawtooth |  voice_directsound 60, 0, DirectSoundWaveData_bw_msl_supersaw, 255, 0, 255, 171
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_church_organ3_low, 255, 76, 154, 188 @ 105 | RSE Church Organ |  voice_directsound 60, 0, DirectSoundWaveData_bw_drumloop_smash, 255, 0, 255, 171
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_church_organ3_low, 255, 76, 154, 188 @ 106 | RSE Church Organ |  voice_directsound 60, 0, DirectSoundWaveData_bw_msl_chantpokemon, 255, 0, 255, 171
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_church_organ3_low, 255, 76, 154, 188 @ 107 | RSE Church Organ |  voice_directsound 60, 0, DirectSoundWaveData_bw_msl_chantsmash, 255, 0, 255, 171
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_detuned_ep1_low, 128, 249, 0, 188 @ 108 | RSE Elec Piano |  voice_directsound 60, 0, DirectSoundWaveData_bw_msl_dulcimer, 255, 0, 255, 171
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_church_organ3_low, 255, 76, 154, 188 @ 109 | RSE Church Organ |  voice_directsound 60, 0, DirectSoundWaveData_bw_msl_aah, 255, 0, 255, 171
	voice_directsound 60, 0, DirectSoundWaveData_dp_synthsnare, 255, 0, 255, 171          @ 110 | HGSS Synth Snare |  voice_directsound 60, 0, DirectSoundWaveData_bw_msl_deepkick, 255, 0, 255, 171
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_church_organ3_low, 255, 76, 154, 188 @ 111 | RSE Church Organ |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, DirectSoundWaveData_drum_and_percussion_kick, 255, 0, 255, 171 @ 112 | HGSS Reverse Cymbal |  voice_directsound 60, 0, DirectSoundWaveData_bw_drumloop_meloetta, 255, 0, 255, 171
	voice_directsound 60, 0, DirectSoundWaveData_dp_synthkick, 255, 0, 255, 171           @ 113 | HGSS Synth Kick |  voice_directsound 60, 0, DirectSoundWaveData_bw_msl_kick_melo, 255, 0, 255, 171
	voice_directsound 60, 0, DirectSoundWaveData_dp_synthsnare, 255, 0, 255, 171          @ 114 | HGSS Synth Snare |  voice_directsound 60, 0, DirectSoundWaveData_bw_172snare909, 255, 0, 255, 171
	voice_directsound 60, 0, DirectSoundWaveData_dp_sawtoothlead60, 255, 0, 255, 171      @ 115 | HGSS Sawtooth |  voice_directsound 60, 0, DirectSoundWaveData_bw_msl_supersaw, 255, 0, 255, 171
	voice_directsound 60, 0, DirectSoundWaveData_dp_synthsnare, 255, 0, 255, 171          @ 116 | HGSS Synth Snare |  voice_directsound 60, 0, DirectSoundWaveData_bw_msl_timbale, 255, 0, 255, 171
	voice_directsound 60, 0, DirectSoundWaveData_dp_synthsnare, 255, 0, 255, 171          @ 117 | HGSS Synth Snare |  voice_directsound 60, 0, DirectSoundWaveData_bw_drumloop_ludicolo, 255, 0, 255, 171
	voice_directsound 60, 0, DirectSoundWaveData_dp_synthsnare, 255, 0, 255, 171          @ 118 | HGSS Synth Snare |  voice_directsound 60, 0, DirectSoundWaveData_bw_msl_cuica, 255, 0, 255, 171
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 119 | --- |  
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 120 | --- |  
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 121 | --- |  
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 122 | --- |  
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 123 | --- |  
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 124 | --- |  
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 125 | --- |  
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 126 | --- |  
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 127 | --- |  
