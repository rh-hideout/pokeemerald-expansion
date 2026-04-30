	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Sfx_DexFanfare2049 — 4 channels (Pulse1, Pulse2, Wave, Noise)

gbs_sfx_dexfanfare_2049_Ch5:
	gbs_switch 4
	toggle_sfx
	tempo 104
	volume 7, 7
	duty_cycle 2
	note_type 12, 8, 8
	octave 3
	note A_, 4
	rest 2
	note A_, 1
	rest 1
	note As, 4
	rest 2
	note As, 1
	rest 1
	octave 4
	note C_, 2
	rest 2
	octave 3
	note As, 2
	rest 2
	note A_, 2
	rest 6
	sound_ret

gbs_sfx_dexfanfare_2049_Ch6:
	gbs_switch 5
	toggle_sfx
	duty_cycle 2
	note_type 12, 12, 1
	octave 5
	note F_, 2
	note E_, 2
	note D_, 2
	note C_, 2
	octave 4
	note As, 2
	octave 5
	note C_, 2
	note D_, 2
	note E_, 2
	note F_, 4
	note G_, 4
	note F_, 8
	sound_ret

gbs_sfx_dexfanfare_2049_Ch7:
	gbs_switch 6
	toggle_sfx
	note_type 12, 2, 5
	octave 4
	note F_, 4
	rest 2
	note F_, 1
	rest 1
	note F_, 4
	rest 2
	note F_, 1
	rest 1
	note A_, 2
	rest 2
	note E_, 2
	rest 2
	note F_, 2
	rest 6
	sound_ret

gbs_sfx_dexfanfare_2049_Ch8:
	gbs_switch 7
	toggle_sfx
	sfx_toggle_noise 4
	drum_speed 12
	note C_, 16
	rest 16
	sound_ret

	.align 4
	.global gbs_sfx_dexfanfare_2049_Header
gbs_sfx_dexfanfare_2049_Header:
	.byte 4 @ NumTrks
	.byte 0 @ NumBlks
	.byte 0 @ Priority
	.byte 0 @ Reverb

	.int voicegroup000

	.int gbs_sfx_dexfanfare_2049_Ch5
	.int gbs_sfx_dexfanfare_2049_Ch6
	.int gbs_sfx_dexfanfare_2049_Ch7
	.int gbs_sfx_dexfanfare_2049_Ch8
