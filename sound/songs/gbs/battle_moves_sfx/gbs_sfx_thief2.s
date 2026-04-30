	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_thief2_Ch5:
	gbs_switch 4
	toggle_sfx
	note_type 2, 15, 4
	duty_cycle 0
	octave 4
	note Cs, 3
	note As, 3
	volume_envelope 13, 2
	note Cs, 3
	note As, 3
	volume_envelope 11, 1
	note C_, 3
	note A_, 3
	volume_envelope 8, 1
	note C_, 3
	note A_, 3
	toggle_sfx
	sound_ret

	.align 4
	.global gbs_sfx_thief2_Header
gbs_sfx_thief2_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_thief2_Ch5
