	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Sfx_DexFanfare80109 — 4 channels (Pulse1, Pulse2, Wave, Noise)

gbs_sfx_dexfanfare_80109_Ch5:
	gbs_switch 4
	toggle_sfx
	tempo 112
	volume 7, 7
	vibrato 8, 2, 7
	duty_cycle 2
	note_type 12, 11, 1
	octave 4
	note Ds, 2
	note Ds, 1
	note Ds, 1
	octave 3
	note As, 2
	note As, 1
	note As, 1
	octave 4
	note Ds, 2
	note Ds, 1
	note Ds, 1
	note F_, 2
	note F_, 1
	note F_, 1
	volume_envelope 10, 5
	note As, 16
	sound_ret

gbs_sfx_dexfanfare_80109_Ch6:
	gbs_switch 5
	toggle_sfx
	vibrato 8, 2, 7
	duty_cycle 2
	note_type 12, 12, 1
	octave 4
	note G_, 2
	note G_, 1
	note G_, 1
	note Ds, 2
	note Ds, 1
	note Ds, 1
	note Gs, 2
	note Gs, 1
	note Gs, 1
	note As, 2
	note As, 1
	note As, 1
	volume_envelope 11, 5
	octave 5
	note Ds, 16
	sound_ret

gbs_sfx_dexfanfare_80109_Ch7:
	gbs_switch 6
	toggle_sfx
	note_type 12, 2, 5
	octave 4
	note Ds, 1
	rest 1
	octave 3
	note As, 2
	octave 4
	note Ds, 1
	rest 1
	octave 3
	note As, 2
	octave 4
	note Ds, 1
	rest 1
	note C_, 2
	note D_, 1
	rest 1
	octave 3
	note As, 2
	note Ds, 4
	volume_envelope 3, 5
	note Ds, 3
	rest 9
	sound_ret

gbs_sfx_dexfanfare_80109_Ch8:
	gbs_switch 7
	toggle_sfx
	sfx_toggle_noise 4
	drum_speed 12
	note C_, 16
	rest 16
	sound_ret

	.align 4
	.global gbs_sfx_dexfanfare_80109_Header
gbs_sfx_dexfanfare_80109_Header:
	.byte 4 @ NumTrks
	.byte 0 @ NumBlks
	.byte 0 @ Priority
	.byte 0 @ Reverb

	.int voicegroup000

	.int gbs_sfx_dexfanfare_80109_Ch5
	.int gbs_sfx_dexfanfare_80109_Ch6
	.int gbs_sfx_dexfanfare_80109_Ch7
	.int gbs_sfx_dexfanfare_80109_Ch8
