	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_sfx_spite_Ch5:
	gbs_switch 4
	toggle_sfx
	vibrato 0, 1, 2
	duty_cycle 3
	pitch_sweep 15, -5
	note_type 3, 15, 8
	octave 3
	note F_, 3
	note Gs, 3
	note B_, 3
	note E_, 3
	note G_, 3
	note As, 3
	volume_envelope 11, -7
	note Ds, 3
	note Fs, 3
	note A_, 3
	volume_envelope 5, -7
	note D_, 3
	volume_envelope 2, -7
	note F_, 3
	note Gs, 3
	pitch_sweep 0, 8
	toggle_sfx
	sound_ret

	.align 4
	.global gbs_sfx_spite_Header
gbs_sfx_spite_Header:
	.byte 1	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_spite_Ch5
