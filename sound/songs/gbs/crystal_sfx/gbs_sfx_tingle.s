	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_tingle_Ch5:
	gbs_switch 4
	toggle_sfx
	duty_cycle 1
	transpose 0, 11
	note_type 1, 11, 1
gbs_sfx_tingle_Ch5.loop1:
	octave 5
	note C_, 3
	octave 6
	note G_, 2
	octave 5
	note C_, 3
	rest 2
	sound_loop 2, gbs_sfx_tingle_Ch5.loop1
	note C_, 2
	volume_envelope 10, 1
	note G_, 13
	sound_ret

	.align 4
	.global gbs_sfx_tingle_Header
gbs_sfx_tingle_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_tingle_Ch5
