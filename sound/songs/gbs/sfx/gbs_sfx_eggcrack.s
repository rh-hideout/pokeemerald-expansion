	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_eggcrack_Ch5:
	gbs_switch 4
	toggle_sfx
	note_type 1, 15, 1
	duty_cycle 0
	octave 4
	note Ds, 1
	note C_, 1
	rest 1
	note Fs, 1
	sound_ret

	.align 4
	.global gbs_sfx_eggcrack_Header
gbs_sfx_eggcrack_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_eggcrack_Ch5
