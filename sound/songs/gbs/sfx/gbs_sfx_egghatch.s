	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_egghatch_Ch5:
	gbs_switch 4
	toggle_sfx
	note_type 2, 15, 1
	duty_cycle 2
	octave 5
	note E_, 1
	note C_, 1
	rest 1
	note G_, 1
	note D_, 1
	volume_envelope 14, 2
	note B_, 7
	volume_envelope 8, 2
	note B_, 7
	volume_envelope 4, 2
	note B_, 7
	sound_ret

	.align 4
	.global gbs_sfx_egghatch_Header
gbs_sfx_egghatch_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_egghatch_Ch5
