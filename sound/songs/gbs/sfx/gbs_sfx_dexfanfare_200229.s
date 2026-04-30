	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Sfx_DexFanfare200229 — 4 channels (Pulse1, Pulse2, Wave, Noise)

gbs_sfx_dexfanfare_200229_Ch5:
	gbs_switch 4
	toggle_sfx
	tempo 124
	volume 7, 7
	vibrato 18, 3, 4
	duty_cycle 3
	note_type 8, 11, 2
	octave 3
	note C_, 2
	note E_, 2
	note G_, 2
	octave 4
	note C_, 4
	octave 3
	note B_, 4
	note A_, 4
	note As, 4
	octave 4
	note Ds, 4
	note G_, 4
	note_type 12, 10, 8
	note Fs, 12
	rest 4
	sound_ret

gbs_sfx_dexfanfare_200229_Ch6:
	gbs_switch 5
	toggle_sfx
	vibrato 18, 3, 4
	duty_cycle 3
	note_type 8, 11, 2
	octave 3
	note E_, 2
	note G_, 2
	octave 4
	note C_, 2
	note E_, 4
	note D_, 4
	note C_, 4
	note Ds, 4
	note G_, 4
	note As, 4
	note_type 12, 11, 8
	note A_, 12
	rest 4
	sound_ret

gbs_sfx_dexfanfare_200229_Ch7:
	gbs_switch 6
	toggle_sfx
	note_type 8, 2, 5
	octave 3
	note C_, 1
	rest 1
	note C_, 1
	rest 1
	note C_, 1
	rest 1
	note C_, 2
	note E_, 2
	note G_, 2
	octave 4
	note C_, 2
	octave 3
	note C_, 4
	note Ds, 2
	note G_, 2
	note As, 2
	octave 4
	note Ds, 2
	octave 3
	note Ds, 4
	note D_, 1
	rest 1
	note D_, 1
	rest 1
	octave 2
	note A_, 2
	octave 3
	note D_, 1
	rest 1
	note D_, 1
	rest 1
	octave 2
	note A_, 2
	octave 3
	note D_, 6
	rest 6
	sound_ret

gbs_sfx_dexfanfare_200229_Ch8:
	gbs_switch 7
	toggle_sfx
	sfx_toggle_noise 4
	drum_speed 8
	note Cs, 1
	note Cs, 1
	note Cs, 1
	note Cs, 1
	note Cs, 1
	note Cs, 1
	note D_, 4
	note D_, 4
	note D_, 4
	note D_, 4
	note D_, 4
	note Cs, 1
	note Cs, 1
	note Cs, 1
	note Cs, 1
	note D_, 4
	note D_, 2
	note D_, 2
	note D_, 2
	note D_, 2
	note B_, 12
	sound_ret

	.align 4
	.global gbs_sfx_dexfanfare_200229_Header
gbs_sfx_dexfanfare_200229_Header:
	.byte 4 @ NumTrks
	.byte 0 @ NumBlks
	.byte 0 @ Priority
	.byte 0 @ Reverb

	.int voicegroup000

	.int gbs_sfx_dexfanfare_200229_Ch5
	.int gbs_sfx_dexfanfare_200229_Ch6
	.int gbs_sfx_dexfanfare_200229_Ch7
	.int gbs_sfx_dexfanfare_200229_Ch8
