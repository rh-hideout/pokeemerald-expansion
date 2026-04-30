	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_caughtmon_Ch5:
	gbs_switch 4
	toggle_sfx
	tempo 112
	volume 7, 7
	vibrato 8, 2, 7
	duty_cycle 2
	note_type 8, 11, 3
	octave 4
	note C_, 6
	octave 3
	note A_, 6
	note F_, 12
	volume_envelope 11, 1
	octave 4
	note Ds, 2
	note Ds, 2
	note Ds, 2
	note Ds, 2
	note Ds, 2
	note G_, 2
	volume_envelope 11, 3
	note F_, 12
	sound_ret

gbs_sfx_caughtmon_Ch6:
	gbs_switch 5
	toggle_sfx
	duty_cycle 2
	vibrato 8, 2, 7
	note_type 8, 12, 3
	octave 4
	note A_, 6
	note F_, 6
	note C_, 12
	volume_envelope 12, 1
	note As, 2
	note As, 2
	note As, 2
	note G_, 2
	note G_, 2
	note As, 2
	volume_envelope 12, 3
	note A_, 12
	sound_ret

gbs_sfx_caughtmon_Ch7:
	gbs_switch 6
	toggle_sfx
	note_type 8, 2, 5
	octave 3
	note C_, 12
	note C_, 6
	octave 2
	note A_, 2
	octave 3
	note C_, 2
	note F_, 2
	note G_, 6
	note As, 6
	note A_, 6
	volume_envelope 3, 5
	note A_, 3
	rest 3
	sound_ret

gbs_sfx_caughtmon_Ch8:
	gbs_switch 7
	toggle_sfx
	sfx_toggle_noise 4
	drum_speed 12
	note C_, 16
	rest 16
	sound_ret

	.align 4
	.global gbs_sfx_caughtmon_Header
gbs_sfx_caughtmon_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_caughtmon_Ch5
	.int gbs_sfx_caughtmon_Ch6
	.int gbs_sfx_caughtmon_Ch7
	.int gbs_sfx_caughtmon_Ch8
