	.include "asm/macros.inc"

	.section .rodata
	.align 1


gbs_sfx_item_Ch5:
	gbs_switch 4
	toggle_sfx
	tempo 108
	volume 7, 7
	vibrato 8, 2, 7
	duty_cycle 2
	note_type 8, 11, 2
	octave 4
	note C_, 6
	note C_, 2
	note F_, 2
	note C_, 2
	note G_, 4
	note G_, 4
	note G_, 4
	note F_, 12
	sound_ret

gbs_sfx_item_Ch6:
	gbs_switch 5
	toggle_sfx
	vibrato 8, 2, 7
	duty_cycle 2
	note_type 8, 12, 3
	octave 4
	note A_, 6
	note A_, 2
	note A_, 2
	note A_, 2
	note As, 4
	note As, 4
	note As, 4
	note A_, 12
	sound_ret

gbs_sfx_item_Ch7:
	gbs_switch 6
	toggle_sfx
	note_type 8, 2, 5
	octave 4
	note F_, 4
	rest 2
	note F_, 1
	rest 1
	note F_, 1
	rest 1
	note F_, 1
	rest 1
	note Ds, 2
	rest 2
	note Ds, 2
	rest 2
	note E_, 2
	rest 2
	note F_, 6
	volume_envelope 3, 5
	note F_, 4
	rest 2
	sound_ret

gbs_sfx_item_Ch8:
	gbs_switch 7
	toggle_sfx
	sfx_toggle_noise 4
	drum_speed 12
	note C_, 16
	rest 4
	sound_ret

	.align 4
	.global gbs_sfx_item_Header
gbs_sfx_item_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_sfx_item_Ch5
	.int gbs_sfx_item_Ch6
	.int gbs_sfx_item_Ch7
	.int gbs_sfx_item_Ch8
