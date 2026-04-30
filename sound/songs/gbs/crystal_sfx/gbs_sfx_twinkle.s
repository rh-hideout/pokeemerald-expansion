	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_twinkle_Ch5:
	gbs_switch 4
	toggle_sfx
	duty_cycle 0
	transpose 0, 2
	note_type 2, 14, 1
	octave 3
	note G_, 2
	volume_envelope 11, 1
	octave 4
	note D_, 2
	volume_envelope 14, 1
	note B_, 2
	volume_envelope 11, 1
	note G_, 2
	volume_envelope 14, 1
	octave 5
	note D_, 2
	volume_envelope 11, 1
	octave 4
	note B_, 2
	volume_envelope 14, 1
	octave 5
	note G_, 6
	sound_ret

	.align 4
	.global gbs_sfx_twinkle_Header
gbs_sfx_twinkle_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_twinkle_Ch5
