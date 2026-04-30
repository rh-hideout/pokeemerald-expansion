	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_flash_Ch5:
	gbs_switch 4
	duty_cycle 1
	pitch_sweep 14, -7
	square_note 1, 4, 0, 2024
	square_note 1, 6, 0, 2024
	square_note 2, 8, 0, 2024
	square_note 5, 10, 0, 2024
	square_note 6, 10, 0, 2024
	square_note 7, 8, 0, 2024
	square_note 8, 6, 0, 2024
	square_note 9, 3, 0, 2024
	square_note 15, 1, 2, 2024
	pitch_sweep 0, 8
	sound_ret

	.align 4
	.global gbs_sfx_flash_Header
gbs_sfx_flash_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_flash_Ch5
