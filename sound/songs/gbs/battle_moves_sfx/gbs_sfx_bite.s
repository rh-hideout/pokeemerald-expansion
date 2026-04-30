	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_bite_Ch5:
	gbs_switch 4
	duty_cycle 0
	pitch_sweep 3, -2
	square_note 4, 15, 2, 512
	pitch_sweep 2, 2
	square_note 8, 14, 2, 512
	pitch_sweep 0, 8
	sound_ret

gbs_sfx_bite_Ch8:
	gbs_switch 7
	noise_note 0, 13, 1, 66
	noise_note 4, 10, 1, 50
	noise_note 0, 13, 1, 34
	noise_note 6, 10, 1, 50
	sound_ret

	.align 4
	.global gbs_sfx_bite_Header
gbs_sfx_bite_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_bite_Ch5
	.int gbs_sfx_bite_Ch8
