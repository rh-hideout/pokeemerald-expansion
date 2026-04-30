	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_mindreader_Ch5:
	gbs_switch 4
	toggle_sfx
	duty_cycle 2
	note_type 2, 15, 1
	octave 5
	note C_, 3
	volume_envelope 4, 1
	note C_, 3
	volume_envelope 15, 1
	note Cs, 3
	volume_envelope 4, 1
	note Cs, 3
	volume_envelope 15, 1
	note D_, 3
	volume_envelope 4, 1
	note D_, 3
	toggle_sfx
	sound_ret

gbs_sfx_mindreader_Ch8:
	gbs_switch 7
	noise_note 17, 10, -7, 25
	noise_note 18, 10, -7, 24
	sound_ret

	.align 4
	.global gbs_sfx_mindreader_Header
gbs_sfx_mindreader_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_mindreader_Ch5
	.int gbs_sfx_mindreader_Ch8
