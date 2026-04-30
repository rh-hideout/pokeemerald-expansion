	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cry_slowpoke_Ch5:
	gbs_switch 4
	duty_cycle_pattern 0, 0, 0, 0
	square_note 8, 15, 5, 1152
	square_note 2, 14, 1, 1504
	square_note 8, 13, 1, 1500
	sound_ret

gbs_cry_slowpoke_Ch6:
	gbs_switch 5
	duty_cycle_pattern 2, 2, 1, 1
	square_note 7, 9, 5, 1089
	square_note 2, 8, 1, 1313
	square_note 8, 6, 1, 1306
	sound_ret

@ Ch8 is silent in Crystal (immediate sound_ret).
gbs_cry_slowpoke_Ch8:
	gbs_switch 7
	sound_ret

	.align 4
	.global gbs_cry_slowpoke_Header
gbs_cry_slowpoke_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cry_slowpoke_Ch5
	.int gbs_cry_slowpoke_Ch6
	.int gbs_cry_slowpoke_Ch8
