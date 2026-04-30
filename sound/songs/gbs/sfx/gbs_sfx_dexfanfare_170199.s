	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Sfx_DexFanfare170199 — 4 channels (Pulse1, Pulse2, Wave, Noise)

gbs_sfx_dexfanfare_170199_Ch5:
	gbs_switch 4
	toggle_sfx
	tempo 112
	volume 7, 7
	vibrato 18, 3, 4
	duty_cycle 3
	note_type 8, 11, 4
	octave 3
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note G_, 6
	rest 2
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	volume_envelope 12, 1
	note F_, 4
	note G_, 4
	note A_, 4
	note_type 12, 10, 8
	note As, 12
	rest 4
	sound_ret

gbs_sfx_dexfanfare_170199_Ch6:
	gbs_switch 5
	toggle_sfx
	vibrato 18, 3, 4
	duty_cycle 3
	note_type 8, 12, 4
	octave 3
	note As, 1
	rest 1
	note As, 1
	rest 1
	note As, 6
	rest 2
	note As, 1
	rest 1
	note As, 1
	rest 1
	volume_envelope 13, 1
	octave 4
	note Ds, 4
	note Ds, 4
	note Ds, 4
	note_type 12, 11, 8
	note D_, 12
	rest 4
	sound_ret

gbs_sfx_dexfanfare_170199_Ch7:
	gbs_switch 6
	toggle_sfx
	note_type 8, 2, 5
	octave 3
	note Ds, 1
	rest 1
	note Ds, 1
	rest 1
	note Ds, 6
	rest 2
	note Ds, 1
	rest 1
	note Ds, 1
	rest 1
	note C_, 2
	rest 2
	note C_, 2
	rest 2
	note C_, 2
	rest 2
	note_type 12, 2, 5
	octave 2
	note As, 12
	rest 4
	sound_ret

gbs_sfx_dexfanfare_170199_Ch8:
	gbs_switch 7
	toggle_sfx
	sfx_toggle_noise 4
	drum_speed 8
	note D_, 2
	note D_, 2
	note D_, 4
	note D_, 4
	note D_, 2
	note D_, 2
	note D_, 4
	note D_, 4
	note Cs, 1
	note Cs, 1
	note Cs, 1
	note Cs, 1
	drum_speed 12
	note B_, 16
	sound_ret

	.align 4
	.global gbs_sfx_dexfanfare_170199_Header
gbs_sfx_dexfanfare_170199_Header:
	.byte 4 @ NumTrks
	.byte 0 @ NumBlks
	.byte 0 @ Priority
	.byte 0 @ Reverb

	.int voicegroup000

	.int gbs_sfx_dexfanfare_170199_Ch5
	.int gbs_sfx_dexfanfare_170199_Ch6
	.int gbs_sfx_dexfanfare_170199_Ch7
	.int gbs_sfx_dexfanfare_170199_Ch8
