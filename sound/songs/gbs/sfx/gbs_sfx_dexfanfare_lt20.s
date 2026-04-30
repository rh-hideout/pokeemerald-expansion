	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Sfx_DexFanfareLessThan20 — 4 channels (Pulse1, Pulse2, Wave, Noise)

gbs_sfx_dexfanfare_lt20_Ch5:
	gbs_switch 4
	toggle_sfx
	tempo 124
	volume 7, 7
	note_type 8, 11, 1
	octave 3
	note A_, 4
	note Fs, 2
	note A_, 4
	note Fs, 2
	note Cs, 6
	note G_, 6
	note Fs, 6
	note E_, 2
	note E_, 2
	note E_, 2
	note D_, 6
	sound_ret

gbs_sfx_dexfanfare_lt20_Ch6:
	gbs_switch 5
	toggle_sfx
	note_type 8, 12, 1
	octave 3
	note B_, 4
	note A_, 2
	note B_, 4
	note A_, 2
	note Ds, 6
	note As, 6
	note A_, 6
	note A_, 2
	note A_, 2
	note G_, 2
	note Fs, 6
	sound_ret

gbs_sfx_dexfanfare_lt20_Ch7:
	gbs_switch 6
	toggle_sfx
	note_type 8, 2, 5
	octave 4
	note D_, 6
	octave 3
	note A_, 2
	rest 2
	note A_, 2
	note As, 4
	note G_, 2
	octave 4
	note Ds, 6
	note D_, 2
	rest 4
	octave 3
	note E_, 1
	rest 1
	note Fs, 1
	rest 1
	note G_, 1
	rest 1
	note A_, 2
	rest 6
	sound_ret

gbs_sfx_dexfanfare_lt20_Ch8:
	gbs_switch 7
	toggle_sfx
	sfx_toggle_noise 4
	drum_speed 12
	note Cs, 6
	rest 16
	rest 12
	sound_ret

	.align 4
	.global gbs_sfx_dexfanfare_lt20_Header
gbs_sfx_dexfanfare_lt20_Header:
	.byte 4 @ NumTrks
	.byte 0 @ NumBlks
	.byte 0 @ Priority
	.byte 0 @ Reverb

	.int voicegroup000

	.int gbs_sfx_dexfanfare_lt20_Ch5
	.int gbs_sfx_dexfanfare_lt20_Ch6
	.int gbs_sfx_dexfanfare_lt20_Ch7
	.int gbs_sfx_dexfanfare_lt20_Ch8
