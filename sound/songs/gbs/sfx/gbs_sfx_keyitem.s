	.include "asm/macros.inc"

	.section .rodata
	.align 1


gbs_sfx_keyitem_Ch5:
	gbs_switch 4
	toggle_sfx
	tempo 120
	volume 7, 7
	duty_cycle 2
	note_type 6, 11, 1
	octave 3
	note B_, 4
	note B_, 2
	note B_, 2
	note B_, 4
	octave 4
	note E_, 4
	volume_envelope 11, 3
	note Gs, 16
	sound_ret

gbs_sfx_keyitem_Ch6:
	gbs_switch 5
	toggle_sfx
	duty_cycle 2
	note_type 6, 12, 1
	octave 4
	note E_, 4
	note E_, 2
	note E_, 2
	note E_, 4
	note Gs, 4
	volume_envelope 12, 3
	note B_, 16
	sound_ret

gbs_sfx_keyitem_Ch7:
	gbs_switch 6
	toggle_sfx
	note_type 6, 2, 5
	octave 4
	note Gs, 2
	rest 2
	note Gs, 1
	rest 1
	note Gs, 1
	rest 1
	note Gs, 2
	rest 2
	note B_, 2
	rest 2
	octave 5
	note E_, 8
	volume_envelope 3, 5
	note E_, 4
	rest 4
	sound_ret

gbs_sfx_keyitem_Ch8:
	gbs_switch 7
	toggle_sfx
	sfx_toggle_noise 4
	drum_speed 12
	note C_, 16
	sound_ret

	.align 4
	.global gbs_sfx_keyitem_Header
gbs_sfx_keyitem_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_keyitem_Ch5
	.int gbs_sfx_keyitem_Ch6
	.int gbs_sfx_keyitem_Ch7
	.int gbs_sfx_keyitem_Ch8
