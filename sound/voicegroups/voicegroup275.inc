	.align 2
voicegroup275::
	voice_keysplit voicegroup005, KeySplitTableGBAPiano1Custom                            @ 000 | RSE Piano |  voice_keysplit voicegroup323, KeySplitTable59    @ piano (all splits)
	voice_keysplit voicegroup233, KeySplitTable35                                         @ 001 | HGSS Piano |  voice_keysplit voicegroup233, KeySplitTable35    @ piano (HGSS)
	voice_keysplit voicegroup235, KeySplitTable37                                         @ 002 | HGSS Piano Octave |  voice_keysplit voicegroup235, KeySplitTable91    @ piano octave
	voice_keysplit voicegroup236, KeySplitTable9                                          @ 003 | HGSS Rhodes 1 |  voice_keysplit voicegroup294, KeySplitTable36    @ rhodes
	voice_keysplit voicegroup237, KeySplitTable9                                          @ 004 | HGSS Rhodes 2 |  voice_keysplit voicegroup236, KeySplitTable83    @ rhodes (HGSS)
	voice_keysplit voicegroup234, KeySplitTable36                                         @ 005 | HGSS Piano 2 |  voice_keysplit voicegroup234, KeySplitTable36    @ piano 2
	voice_keysplit voicegroup273, KeySplitTable58                                         @ 006 | HGSS Piano National Park |  voice_keysplit voicegroup326, KeySplitTable36    @ tack piano
	voice_directsound 60, 0, DirectSoundWaveData_unknown_koto_high, 255, 0, 206, 242      @ 007 | RSE Koto High |  voice_keysplit voicegroup290, KeySplitTable70    @ harpsichord
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 008 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 009 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit voicegroup238, KeySplitTable36                                         @ 010 | HGSS Vibraphone |  voice_keysplit voicegroup297, KeySplitTable76    @ vibraphone
	voice_keysplit voicegroup239, KeySplitTable38                                         @ 011 | HGSS Marimba |  voice_keysplit voicegroup295, KeySplitTable74    @ marimba
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 012 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 013 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit voicegroup241, KeySplitTable25                                         @ 014 | HGSS Tubular Bell |  voice_keysplit voicegroup241, KeySplitTable25    @ tubular bell
	voice_keysplit voicegroup242, KeySplitTable36                                         @ 015 | HGSS Glockenspiel |  voice_keysplit voicegroup296, KeySplitTable83    @ glockenspiel
	voice_keysplit voicegroup243, KeySplitTable38                                         @ 016 | HGSS Music Box |  voice_keysplit voicegroup243, KeySplitTable76    @ music box
	voice_keysplit voicegroup244, KeySplitTable40                                         @ 017 | HGSS Drawbar Organ |  voice_keysplit voicegroup244, KeySplitTable71    @ drawbar organ
	voice_keysplit voicegroup245, KeySplitTable40                                         @ 018 | HGSS Jazz Organ |  voice_keysplit voicegroup245, KeySplitTable71    @ jazz organ
	voice_keysplit voicegroup246, KeySplitTable40                                         @ 019 | HGSS Accordion |  voice_keysplit voicegroup291, KeySplitTable71    @ accordion
	voice_keysplit voicegroup247, KeySplitTable41                                         @ 020 | HGSS Nylon Guitar |  voice_keysplit voicegroup292, KeySplitTable72    @ nylon str. guitar
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 021 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 022 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit voicegroup248, KeySplitTable41                                         @ 023 | HGSS Martin Guitar |  voice_keysplit voicegroup308, KeySplitTable84    @ lp marschall guitar
	voice_keysplit voicegroup251, KeySplitTable41                                         @ 024 | HGSS Clean Guitar |  voice_keysplit voicegroup316, KeySplitTable41    @ clean guitar
	voice_keysplit voicegroup252, KeySplitTable42                                         @ 025 | HGSS Upright Bass |  voice_keysplit voicegroup252, KeySplitTable42    @ upright bass
	voice_keysplit voicegroup253, KeySplitTable43                                         @ 026 | HGSS Fingered Bass |  voice_keysplit voicegroup253, KeySplitTable43    @ fingered bass
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fretless_bass, 255, 253, 0, 149  @ 027 | RSE Fretless Bass |  voice_keysplit voicegroup311, KeySplitTable86    @ fretless bass
	voice_directsound 60, 0, DirectSoundWaveData_dp_slapbass_c1_16, 255, 0, 255, 192      @ 028 | HGSS Slap Bass |  voice_keysplit voicegroup309, KeySplitTable92    @ slap bass full
	voice_keysplit voicegroup254, KeySplitTable44                                         @ 029 | HGSS Synth Bass |  voice_keysplit voicegroup254, KeySplitTable73    @ synth bass
	voice_keysplit voicegroup255, KeySplitTable45                                         @ 030 | HGSS Strings |  voice_keysplit voicegroup255, KeySplitTable60    @ strings
	voice_keysplit voicegroup006, KeySplitTable2                                          @ 031 | RSE Strings |  voice_keysplit voicegroup298, KeySplitTable82    @ strings 2
	voice_keysplit voicegroup256, KeySplitTable46                                         @ 032 | HGSS Violin |  voice_keysplit voicegroup256, KeySplitTable46    @ violin
	voice_directsound 60, 0, DirectSoundWaveData_hg_021cellog2, 254, 242, 255, 205        @ 033 | HGSS Cello Part |  voice_directsound 60, 0, DirectSoundWaveData_hg_021cellog2, 254, 242, 255, 205
	voice_keysplit voicegroup258, KeySplitTable48                                         @ 034 | HGSS Pizzicato |  voice_keysplit voicegroup293, KeySplitTable48    @ pizzicato
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_harp, 255, 242, 51, 242          @ 035 | RSE Harp |  voice_keysplit voicegroup299, KeySplitTable78    @ harp 2
	voice_keysplit voicegroup259, KeySplitTable40                                         @ 036 | HGSS Harp |  voice_keysplit voicegroup259, KeySplitTable40    @ harp (HGSS)
	voice_keysplit voicegroup259, KeySplitTable40                                         @ 037 | HGSS Harp |  voice_keysplit voicegroup302, KeySplitTable80    @ harp 1
	voice_keysplit voicegroup260, KeySplitTable40                                         @ 038 | HGSS Timpani |  voice_keysplit voicegroup260, KeySplitTable61    @ timpani
	voice_keysplit voicegroup261, KeySplitTable39                                         @ 039 | HGSS Trumpets |  voice_keysplit voicegroup261, KeySplitTable39    @ trumpets
	voice_keysplit voicegroup262, KeySplitTable47                                         @ 040 | HGSS Trombone |  voice_keysplit voicegroup262, KeySplitTable47    @ trombones
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 041 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit voicegroup263, KeySplitTable49                                         @ 042 | HGSS French Horns Solo |  voice_keysplit voicegroup327, KeySplitTable64    @ french horns (old splits)
	voice_keysplit voicegroup264, KeySplitTable50                                         @ 043 | HGSS French Horns |  voice_keysplit voicegroup327, KeySplitTable41    @ french horns
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_oboe, 43, 188, 103, 165   @ 044 | RSE Oboe 1 |  voice_keysplit voicegroup288, KeySplitTable46    @ oboe
	voice_keysplit voicegroup266, KeySplitTable52                                         @ 045 | HGSS Clarinet |  voice_keysplit voicegroup266, KeySplitTable52    @ clarinet
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 046 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_flute, 255, 127, 231, 127        @ 047 | RSE Flute |  voice_keysplit voicegroup287, KeySplitTable67    @ flute 2
	voice_keysplit voicegroup267, KeySplitTable53                                         @ 048 | HGSS Flute |  voice_keysplit voicegroup328, KeySplitTable65    @ flute 1
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 049 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 050 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_whistle, 43, 76, 103, 216 @ 051 | RSE Whistle |  voice_directsound 60, 0, DirectSoundWaveData_bw_sambawhistlec4_route2, 255, 0, 255, 171
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 052 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 053 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_noise_alt 60, 0, 0, 0, 1, 6, 0                                                  @ 054 | GB Noise |  voice_directsound 60, 0, DirectSoundWaveData_bw_seashorec4, 255, 0, 255, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 055 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_bubbles, 255, 0, 255, 0          @ 056 | HGSS Bubble |  voice_keysplit voicegroup329, KeySplitTable19    @ abyssal ruins
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 057 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 058 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 059 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 060 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 061 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 062 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, DirectSoundWaveData_dp_tenorchoir48, 255, 188, 220, 243      @ 063 | RSE Choir |  voice_keysplit voicegroup303, KeySplitTable81    @ choir full
	voice_directsound 60, 0, DirectSoundWaveData_dp_altosax_c3_16, 255, 216, 252, 192     @ 064 | HGSS Altosax |  voice_keysplit voicegroup314, KeySplitTable71    @ alto sax
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
	voice_directsound 60, 0, DirectSoundWaveData_unknown_koto_high, 255, 0, 206, 242      @ 075 | RSE Koto High |  voice_keysplit voicegroup330, KeySplitTable108   @ sitar
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
	voice_square_2_alt 60, 0, 2, 0, 7, 2, 0                                               @ 100 | GB Square-2 |  voice_square_2_alt 60, 0, 2, 0, 7, 2, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 101 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 102 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 103 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 104 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 105 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 106 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 107 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 108 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 109 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 110 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 111 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 112 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 113 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 114 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 115 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 116 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 117 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 118 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 119 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1_alt 60, 0, 0, 2, 0, 7, 2, 0                                            @ 120 | GB Square-1 |  voice_square_1_alt 60, 0, 0, 2, 0, 7, 2, 0
	voice_programmable_wave_alt 60, 0, ProgrammableWaveData_3, 0, 7, 2, 0                 @ 121 | GB Wave |  voice_programmable_wave_alt 60, 0, ProgrammableWaveData_sq50half, 0, 7, 2, 0
	voice_directsound 60, 0, DirectSoundWaveData_puresquare_50, 255, 242, 25, 0           @ 122 | HGSS Pure Square |  voice_directsound 60, 0, DirectSoundWaveData_puresquare_50, 255, 242, 25, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 123 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 124 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 125 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0                                               @ 126 | --- |  voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_keysplit_all voicegroup282                                                      @ 127 | HGSS Drum Split |  voice_keysplit_all voicegroup282 @ drums
