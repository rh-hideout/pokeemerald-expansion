	.include "asm/macros.inc"

	.section .rodata
	.align 1


gbs_sfx_getegg_Ch5:
	gbs_switch 4
	toggle_sfx
	tempo 120
	volume 7, 7
	vibrato 18, 3, 4
	duty_cycle 2
	note_type 8, 10, 1
	rest 2
	octave 3
	note C_, 2
	note F_, 2
	note A_, 2
	note F_, 2
	note As, 2
	octave 4
	note D_, 2
	volume_envelope 10, 2
	note F_, 6
	volume_envelope 10, 1
	duty_cycle 3
	octave 3
	note E_, 2
	note G_, 2
	octave 4
	note C_, 2
	volume_envelope 10, 4
	note F_, 9
	sound_ret

	toggle_sfx @ unused

gbs_sfx_getegg_Ch6:
	gbs_switch 5
	toggle_sfx
	vibrato 18, 3, 4
	duty_cycle 3
	note_type 8, 12, 2
	rest 2
	octave 4
	note F_, 2
	rest 2
	note A_, 2
	volume_envelope 12, 1
	note As, 2
	note A_, 2
	note As, 2
	volume_envelope 12, 2
	octave 5
	note C_, 6
	volume_envelope 12, 1
	octave 4
	note C_, 2
	note E_, 2
	note G_, 2
	volume_envelope 12, 4
	note A_, 9
	sound_ret

	toggle_sfx @ unused

gbs_sfx_getegg_Ch7:
	gbs_switch 6
	toggle_sfx
	note_type 8, 2, 5
	rest 2
	octave 3
	note C_, 6
	octave 2
	note As, 6
	octave 3
	note C_, 2
	note F_, 2
	note G_, 2
	note As, 6
	note A_, 9
	sound_ret

	toggle_sfx @ unused

gbs_sfx_getegg_Ch8:
	gbs_switch 7
	toggle_sfx
	sfx_toggle_noise 4
	drum_speed 8
	rest 2
	drum_speed 12
	rest 16
	rest 3
	sound_ret

	toggle_sfx @ unused

	.align 4
	.global gbs_sfx_getegg_Header
gbs_sfx_getegg_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_getegg_Ch5
	.int gbs_sfx_getegg_Ch6
	.int gbs_sfx_getegg_Ch7
	.int gbs_sfx_getegg_Ch8
