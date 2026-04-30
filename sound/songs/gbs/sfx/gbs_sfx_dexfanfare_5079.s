	.include "asm/macros.inc"

	.section .rodata
	.align 1

@ Sfx_DexFanfare5079 — identical to Sfx_LevelUp (same channel data, unique header)
@ 4 channels (Pulse1, Pulse2, Wave, Noise)

gbs_sfx_dexfanfare_5079_Ch5:
	gbs_switch 4
	toggle_sfx
	tempo 120
	volume 7, 7
	duty_cycle 2
	note_type 8, 11, 1
	octave 3
	note B_, 2
	note B_, 2
	note B_, 2
	volume_envelope 11, 3
	octave 4
	note Gs, 12
	sound_ret

gbs_sfx_dexfanfare_5079_Ch6:
	gbs_switch 5
	toggle_sfx
	duty_cycle 2
	note_type 8, 12, 1
	octave 4
	note E_, 2
	note E_, 2
	note E_, 2
	volume_envelope 12, 3
	note B_, 12
	sound_ret

gbs_sfx_dexfanfare_5079_Ch7:
	gbs_switch 6
	toggle_sfx
	note_type 8, 2, 5
	octave 4
	note Gs, 1
	rest 1
	note Gs, 1
	rest 1
	note Gs, 1
	rest 1
	octave 5
	note E_, 5
	volume_envelope 3, 5
	note E_, 3
	rest 4
	sound_ret

gbs_sfx_dexfanfare_5079_Ch8:
	gbs_switch 7
	toggle_sfx
	sfx_toggle_noise 4
	drum_speed 12
	note C_, 12
	sound_ret

	.align 4
	.global gbs_sfx_dexfanfare_5079_Header
gbs_sfx_dexfanfare_5079_Header:
	.byte 4 @ NumTrks
	.byte 0 @ NumBlks
	.byte 0 @ Priority
	.byte 0 @ Reverb

	.int voicegroup000

	.int gbs_sfx_dexfanfare_5079_Ch5
	.int gbs_sfx_dexfanfare_5079_Ch6
	.int gbs_sfx_dexfanfare_5079_Ch7
	.int gbs_sfx_dexfanfare_5079_Ch8
