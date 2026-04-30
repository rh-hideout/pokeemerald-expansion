	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_slotmachinestart_Ch5:
	gbs_switch 4
	duty_cycle 2
	pitch_sweep 4, 4
	square_note 15, 15, 0, 1264
	pitch_sweep 1, 7
	square_note 15, 15, 2, 1616
	pitch_sweep 0, 8
	sound_ret

gbs_sfx_slotmachinestart_Ch6:
	gbs_switch 5
	duty_cycle 2
	square_note 15, 9, 2, 1536
	square_note 15, 9, 2, 1922
	sound_ret

	.align 4
	.global gbs_sfx_slotmachinestart_Header
gbs_sfx_slotmachinestart_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_slotmachinestart_Ch5
	.int gbs_sfx_slotmachinestart_Ch6
