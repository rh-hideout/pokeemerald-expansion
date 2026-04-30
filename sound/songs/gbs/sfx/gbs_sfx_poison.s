	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_poison_Ch5:
	gbs_switch 4
gbs_sfx_poison_Ch5.loop:
	duty_cycle 0
	pitch_sweep 1, 4
	square_note 4, 15, 2, 1536
	sound_loop 4, gbs_sfx_poison_Ch5.loop
	square_note 15, 15, 3, 1536
	pitch_sweep 0, 8
	sound_ret

	.align 4
	.global gbs_sfx_poison_Header
gbs_sfx_poison_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_poison_Ch5
