	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_aftertherivalfight_Ch1:
	gbs_switch 0
	tempo 112
	volume 7, 7
	duty_cycle 0
	pitch_offset 1
	vibrato 8, 1, 4
	stereo_panning TRUE, FALSE
	note_type 12, 11, 2
	octave 2
	note Gs, 4
	note Gs, 4
	volume_envelope 8, 2
	octave 3
	note Gs, 2
	note Gs, 2
	note Gs, 2
	note Gs, 2
	sound_loop 0, gbs_lookrival_Ch1.mainloop

gbs_aftertherivalfight_Ch2:
	gbs_switch 1
	duty_cycle 1
	vibrato 6, 3, 5
	stereo_panning FALSE, TRUE
	note_type 12, 12, 2
	octave 4
	note Gs, 4
	note Gs, 4
	volume_envelope 10, 2
	note Gs, 2
	note Gs, 2
	note Gs, 2
	note Gs, 2
	sound_loop 0, gbs_lookrival_Ch2.mainloop

gbs_aftertherivalfight_Ch3:
	gbs_switch 2
	note_type 12, 2, 8
	octave 3
	note Ds, 2
	rest 2
	note Ds, 2
	rest 2
	note Gs, 2
	note Fs, 2
	note F_, 2
	note Ds, 2
	sound_loop 0, gbs_lookrival_Ch3.mainloop

gbs_aftertherivalfight_Ch4:
	gbs_switch 3
	toggle_noise 3
	stereo_panning FALSE, TRUE
	drum_speed 12
	drum_note 3, 4
	drum_note 3, 4
	drum_note 4, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 3, 2
	sound_loop 0, gbs_lookrival_Ch4.mainloop

	.align 4
	.global gbs_aftertherivalfight_Header
gbs_aftertherivalfight_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_aftertherivalfight_Ch1
	.int gbs_aftertherivalfight_Ch2
	.int gbs_aftertherivalfight_Ch3
	.int gbs_aftertherivalfight_Ch4
