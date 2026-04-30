	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_sing_Ch5:
	gbs_switch 4
	toggle_sfx
	vibrato 10, 2, 4
	duty_cycle 2
	note_type 10, 8, 7
	octave 5
	note G_, 8
	octave 6
	note F_, 4
	note Ds, 4
	octave 5
	note G_, 8
	toggle_sfx
	sound_ret

gbs_sfx_sing_Ch6:
	gbs_switch 5
	toggle_sfx
	vibrato 10, 2, 3
	duty_cycle 2
	note_type 11, 6, 7
	octave 5
	note G_, 8
	note_type 10, 6, 7
	octave 6
	note F_, 4
	note Ds, 4
	octave 5
	note G_, 8
	toggle_sfx
	sound_ret

	.align 4
	.global gbs_sfx_sing_Header
gbs_sfx_sing_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_sing_Ch5
	.int gbs_sfx_sing_Ch6
