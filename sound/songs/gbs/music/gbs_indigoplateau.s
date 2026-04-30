	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_indigoplateau_Ch1:
	gbs_switch 0
	tempo 128
	volume 7, 7
	duty_cycle 3
	pitch_offset 2
	stereo_panning FALSE, TRUE
gbs_indigoplateau_Ch1.mainloop:
	sound_call gbs_indigoplateau_Ch1.sub1
	octave 3
	note D_, 4
	sound_call gbs_indigoplateau_Ch1.sub1
	octave 3
	note Ds, 4
	sound_call gbs_indigoplateau_Ch1.sub1
	octave 3
	note Ds, 4
	sound_call gbs_indigoplateau_Ch1.sub1
	note As, 4
	sound_loop 0, gbs_indigoplateau_Ch1.mainloop

gbs_indigoplateau_Ch1.sub1:
	note_type 12, 11, 6
	octave 2
	note A_, 4
	volume_envelope 11, 2
	note A_, 2
	note A_, 2
	note A_, 2
	note A_, 2
	note A_, 4
	note A_, 2
	note A_, 2
	volume_envelope 10, 0
	sound_ret

gbs_indigoplateau_Ch2:
	gbs_switch 1
	duty_cycle 3
	vibrato 16, 2, 2
	stereo_panning TRUE, FALSE
gbs_indigoplateau_Ch2.mainloop:
	sound_call gbs_indigoplateau_Ch2.sub1
	note A_, 4
	sound_call gbs_indigoplateau_Ch2.sub1
	note As, 4
	sound_call gbs_indigoplateau_Ch2.sub1
	note A_, 4
	sound_call gbs_indigoplateau_Ch2.sub1
	note Cs, 4
	volume_envelope 12, 7
	note A_, 6
	note D_, 2
	note G_, 2
	note As, 2
	note A_, 8
	volume_envelope 11, 0
	note A_, 4
	sound_call gbs_indigoplateau_Ch2.sub1
	note As, 4
	volume_envelope 12, 7
	octave 4
	note D_, 6
	note Ds, 2
	note C_, 4
	note D_, 8
	volume_envelope 11, 0
	octave 3
	note A_, 4
	sound_call gbs_indigoplateau_Ch2.sub1
	note Cs, 4
	volume_envelope 12, 7
	octave 4
	note C_, 6
	octave 3
	note As, 2
	note A_, 2
	note G_, 2
	note Fs, 8
	volume_envelope 11, 0
	note A_, 4
	sound_call gbs_indigoplateau_Ch2.sub1
	note As, 4
	volume_envelope 12, 7
	octave 4
	note D_, 6
	note Ds, 2
	note F_, 4
	note Fs, 8
	volume_envelope 11, 0
	octave 3
	note A_, 4
	sound_call gbs_indigoplateau_Ch2.sub1
	note Cs, 4
	sound_loop 0, gbs_indigoplateau_Ch2.mainloop

gbs_indigoplateau_Ch2.sub1:
	note_type 12, 12, 6
	octave 3
	note D_, 4
	volume_envelope 12, 2
	note D_, 2
	note D_, 2
	note D_, 2
	note D_, 2
	note D_, 4
	note D_, 2
	note D_, 2
	volume_envelope 11, 0
	sound_ret

gbs_indigoplateau_Ch3:
	gbs_switch 2
	note_type 12, 1, 9
gbs_indigoplateau_Ch3.mainloop:
	sound_call gbs_indigoplateau_Ch3.sub1
	octave 3
	note A_, 4
	sound_call gbs_indigoplateau_Ch3.sub1
	octave 3
	note A_, 4
	sound_call gbs_indigoplateau_Ch3.sub1
	octave 3
	note A_, 4
	sound_call gbs_indigoplateau_Ch3.sub1
	octave 3
	note Fs, 4
	sound_loop 0, gbs_indigoplateau_Ch3.mainloop

gbs_indigoplateau_Ch3.sub1:
	octave 3
	note D_, 1
	rest 3
	octave 2
	note A_, 1
	rest 3
	octave 3
	note C_, 1
	rest 3
	note D_, 1
	rest 3
	octave 2
	note A_, 1
	rest 3
	sound_ret

gbs_indigoplateau_Ch4:
	gbs_switch 3
	stereo_panning TRUE, FALSE
	toggle_noise 0
	drum_speed 12
gbs_indigoplateau_Ch4.mainloop:
	drum_note 4, 4
	drum_note 3, 2
	drum_note 4, 2
	drum_note 4, 2
	drum_note 4, 2
	drum_note 3, 4
	drum_note 3, 2
	drum_note 3, 2
	drum_speed 6
	drum_note 3, 1
	drum_note 3, 1
	drum_note 4, 1
	drum_note 4, 1
	drum_note 4, 1
	drum_note 4, 1
	drum_note 3, 1
	drum_note 3, 1
	drum_speed 12
	drum_note 4, 4
	drum_note 3, 2
	drum_note 4, 2
	drum_note 4, 2
	drum_note 3, 2
	drum_note 2, 4
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 4
	sound_loop 0, gbs_indigoplateau_Ch4.mainloop

	.align 4
	.global gbs_indigoplateau_Header
gbs_indigoplateau_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_indigoplateau_Ch1
	.int gbs_indigoplateau_Ch2
	.int gbs_indigoplateau_Ch3
	.int gbs_indigoplateau_Ch4
