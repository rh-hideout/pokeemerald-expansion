	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_registerphonenumber_Ch5:
	gbs_switch 4
	toggle_sfx
	tempo 124
	volume 7, 7
	duty_cycle 3
	note_type 12, 10, 2
	rest 2
	octave 3
	note C_, 4
	note Gs, 4
	octave 4
	note C_, 2
	octave 3
	note F_, 1
	note Gs, 2
	note C_, 1
	note F_, 2
	note As, 3
	octave 4
	note Cs, 3
	note C_, 2
	sound_ret

	toggle_sfx @ unused

gbs_sfx_registerphonenumber_Ch6:
	gbs_switch 5
	toggle_sfx
	duty_cycle 3
	note_type 12, 12, 2
	rest 2
	octave 4
	note Ds, 2
	note Cs, 2
	note C_, 2
	note Ds, 2
	note F_, 2
	rest 1
	note Gs, 3
	octave 5
	note C_, 2
	note Ds, 3
	octave 4
	note G_, 3
	note Gs, 2
	sound_ret

	toggle_sfx @ unused

gbs_sfx_registerphonenumber_Ch7:
	gbs_switch 6
	toggle_sfx
	note_type 12, 2, 5
	rest 2
	octave 3
	note Ds, 7
	rest 1
	note Gs, 2
	rest 1
	note C_, 2
	rest 1
	note Gs, 2
	note G_, 2
	rest 1
	note As, 3
	note Gs, 2
	sound_ret

	toggle_sfx @ unused

gbs_sfx_registerphonenumber_Ch8:
	gbs_switch 7
	toggle_sfx
	sfx_toggle_noise 4
	drum_speed 12
	note C_, 2
	rest 16
	rest 8
	sound_ret

	toggle_sfx @ unused

	.align 4
	.global gbs_sfx_registerphonenumber_Header
gbs_sfx_registerphonenumber_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_registerphonenumber_Ch5
	.int gbs_sfx_registerphonenumber_Ch6
	.int gbs_sfx_registerphonenumber_Ch7
	.int gbs_sfx_registerphonenumber_Ch8
