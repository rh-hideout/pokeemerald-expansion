	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_elmslab_Ch1:
	gbs_switch 0
	tempo 144
	volume 7, 7
	duty_cycle 3
	pitch_offset 1
	vibrato 16, 1, 5
	stereo_panning TRUE, FALSE
	note_type 12, 11, 2
	octave 2
	note F_, 2
	note G_, 2
	note A_, 2
	note B_, 2
	volume_envelope 11, 6
	octave 3
	note C_, 8
	volume_envelope 11, 2
	octave 2
	note As, 2
	note A_, 2
	note G_, 2
	octave 3
	note C_, 8
	note F_, 4
	note F_, 4
	note F_, 8
	note A_, 4
	note A_, 4
	note A_, 2
gbs_elmslab_Ch1.mainloop:
	rest 2
	note A_, 2
	note Gs, 2
	note A_, 2
	volume_envelope 11, 7
	octave 4
	note C_, 4
	volume_envelope 11, 5
	octave 3
	note B_, 2
	octave 4
	note C_, 2
	volume_envelope 11, 4
	note F_, 8
	volume_envelope 11, 5
	octave 3
	note A_, 2
	note Gs, 2
	note A_, 2
	note F_, 2
	volume_envelope 11, 7
	note F_, 8
	volume_envelope 11, 5
	note A_, 2
	note G_, 2
	note F_, 2
	volume_envelope 11, 2
	note G_, 4
	volume_envelope 11, 5
	note A_, 2
	note Gs, 2
	note A_, 2
	volume_envelope 11, 7
	note F_, 4
	volume_envelope 11, 5
	note C_, 4
	volume_envelope 11, 7
	note D_, 8
	volume_envelope 11, 4
	note F_, 2
	note E_, 2
	note D_, 2
	note F_, 2
	volume_envelope 11, 7
	note E_, 8
	volume_envelope 11, 4
	note G_, 2
	note F_, 2
	note E_, 2
	note G_, 2
	volume_envelope 11, 7
	note F_, 8
	volume_envelope 11, 4
	note G_, 2
	note A_, 2
	note As, 2
	note A_, 2
	volume_envelope 11, 2
	note G_, 4
	volume_envelope 11, 4
	note F_, 2
	note A_, 2
	note G_, 2
	note F_, 2
	note E_, 2
	volume_envelope 11, 2
	note G_, 6
	volume_envelope 11, 7
	note F_, 4
	octave 4
	note C_, 2
	octave 3
	note F_, 4
	note D_, 2
	note As, 4
	note A_, 4
	volume_envelope 11, 4
	note G_, 2
	note F_, 2
	note G_, 2
	volume_envelope 11, 2
	note A_, 6
	volume_envelope 11, 7
	note E_, 4
	note As, 2
	note E_, 6
	volume_envelope 11, 3
	note F_, 2
	note E_, 2
	note F_, 2
	note G_, 2
	note A_, 2
	note A_, 2
	note G_, 2
	volume_envelope 11, 2
	note E_, 6
	volume_envelope 11, 4
	note F_, 4
	octave 4
	note C_, 4
	octave 3
	note F_, 2
	octave 4
	note C_, 2
	note D_, 2
	note C_, 2
	octave 3
	note As, 2
	note A_, 2
	volume_envelope 11, 7
	note As, 8
	octave 4
	note E_, 4
	note D_, 4
	note C_, 4
	octave 3
	note As, 4
	octave 4
	note C_, 4
	note D_, 4
	note Ds, 4
	note E_, 4
	volume_envelope 11, 4
	octave 3
	note A_, 2
	note F_, 2
	octave 4
	note C_, 2
	octave 3
	note F_, 2
	note A_, 2
	note F_, 2
	octave 4
	note C_, 2
	octave 3
	note F_, 2
	note A_, 2
	note F_, 2
	octave 4
	note C_, 2
	octave 3
	note F_, 2
	note A_, 2
	volume_envelope 11, 2
	note F_, 2
	note F_, 4
	sound_loop 0, gbs_elmslab_Ch1.mainloop

gbs_elmslab_Ch2:
	gbs_switch 1
	duty_cycle 3
	vibrato 16, 2, 6
	stereo_panning FALSE, TRUE
	note_type 12, 12, 3
	octave 4
	note F_, 2
	note E_, 2
	note D_, 2
	octave 3
	note B_, 2
	volume_envelope 12, 5
	octave 4
	note C_, 8
	volume_envelope 12, 3
	octave 3
	note As, 2
	note A_, 2
	note G_, 2
	note E_, 2
	volume_envelope 12, 2
	note F_, 6
	octave 4
	note C_, 4
	note C_, 4
	note C_, 8
	note C_, 4
	note C_, 4
	note C_, 2
	stereo_panning TRUE, TRUE
gbs_elmslab_Ch2.mainloop:
	volume_envelope 12, 6
	octave 4
	note F_, 6
	volume_envelope 12, 2
	note E_, 2
	note F_, 2
	note E_, 2
	note F_, 2
	note G_, 2
	volume_envelope 12, 7
	note A_, 6
	volume_envelope 12, 2
	note F_, 2
	volume_envelope 12, 7
	note C_, 8
	volume_envelope 12, 7
	note D_, 6
	volume_envelope 12, 3
	note Cs, 2
	note D_, 2
	note Cs, 2
	note D_, 2
	note E_, 2
	volume_envelope 12, 7
	note F_, 6
	volume_envelope 12, 3
	note C_, 2
	volume_envelope 12, 7
	octave 3
	note A_, 10
	volume_envelope 12, 3
	note As, 2
	note As, 2
	octave 4
	note D_, 2
	volume_envelope 12, 5
	note C_, 4
	octave 3
	note As, 6
	volume_envelope 12, 3
	octave 4
	note C_, 2
	note C_, 2
	note E_, 2
	volume_envelope 12, 4
	note D_, 4
	note C_, 6
	volume_envelope 12, 2
	note D_, 2
	note D_, 2
	note F_, 2
	note G_, 2
	note F_, 2
	note E_, 2
	note F_, 2
	volume_envelope 12, 2
	note G_, 4
	volume_envelope 12, 6
	note C_, 4
	note D_, 4
	volume_envelope 12, 4
	note E_, 6
	volume_envelope 12, 3
	note F_, 2
	note F_, 2
	note G_, 2
	volume_envelope 12, 7
	note A_, 4
	volume_envelope 12, 3
	note G_, 2
	note Fs, 2
	note G_, 2
	note Fs, 2
	note G_, 1
	note F_, 2
	volume_envelope 12, 7
	note D_, 11
	volume_envelope 12, 3
	note E_, 2
	note E_, 2
	note F_, 2
	volume_envelope 12, 7
	note G_, 4
	volume_envelope 12, 3
	note F_, 2
	note E_, 2
	note F_, 2
	note G_, 2
	note F_, 1
	note D_, 2
	volume_envelope 12, 7
	note C_, 11
	volume_envelope 12, 4
	note F_, 2
	note F_, 2
	note G_, 2
	volume_envelope 12, 7
	note A_, 4
	volume_envelope 12, 4
	note G_, 2
	note F_, 2
	note As, 2
	note A_, 2
	note As, 1
	octave 5
	note C_, 2
	note D_, 5
	volume_envelope 12, 3
	note E_, 2
	note D_, 2
	volume_envelope 12, 7
	note C_, 4
	octave 4
	note As, 4
	note A_, 4
	note G_, 4
	octave 5
	note C_, 4
	octave 4
	note As, 4
	note A_, 4
	note G_, 4
	volume_envelope 11, 0
	note F_, 8
	volume_envelope 10, 0
	note F_, 8
	volume_envelope 10, 7
	note F_, 10
	volume_envelope 12, 2
	note C_, 2
	note F_, 2
	volume_envelope 12, 4
	octave 3
	note E_, 2
	sound_loop 0, gbs_elmslab_Ch2.mainloop

gbs_elmslab_Ch3:
	gbs_switch 2
	stereo_panning FALSE, TRUE
	note_type 12, 2, 5
	rest 8
	rest 14
	octave 3
	note C_, 2
	note F_, 2
	note A_, 2
	note C_, 2
	note A_, 2
	note F_, 2
	note A_, 2
	note C_, 2
	note A_, 2
	note F_, 2
	note A_, 2
	note C_, 2
	note A_, 2
	note F_, 2
	note C_, 2
	note D_, 2
	note E_, 2
gbs_elmslab_Ch3.mainloop:
	note F_, 2
	note A_, 2
	note C_, 2
	note A_, 2
	note F_, 2
	note A_, 2
	note C_, 2
	note A_, 2
	note F_, 2
	note A_, 2
	note C_, 2
	note A_, 2
	note F_, 2
	note A_, 2
	note E_, 2
	octave 4
	note C_, 2
	octave 3
	note D_, 2
	note A_, 2
	octave 2
	note A_, 2
	octave 3
	note A_, 2
	note D_, 2
	note A_, 2
	note D_, 2
	note E_, 2
	note F_, 2
	note A_, 2
	note C_, 2
	note A_, 2
	note F_, 2
	note C_, 2
	note D_, 2
	note E_, 2
	note F_, 2
	note As, 2
	note D_, 2
	note As, 2
	note F_, 2
	note As, 2
	note D_, 2
	note As, 2
	note G_, 2
	octave 4
	note C_, 2
	octave 3
	note E_, 2
	octave 4
	note C_, 2
	octave 3
	note G_, 2
	octave 4
	note C_, 2
	octave 3
	note E_, 2
	note A_, 2
	note As, 2
	octave 4
	note D_, 2
	octave 3
	note F_, 2
	octave 4
	note D_, 2
	octave 3
	note As, 2
	octave 4
	note D_, 2
	octave 3
	note F_, 2
	note B_, 2
	octave 4
	note C_, 2
	rest 2
	note C_, 4
	octave 3
	note As, 4
	note G_, 4
	note F_, 2
	note A_, 2
	note C_, 2
	note A_, 2
	note F_, 2
	note A_, 2
	note C_, 2
	note A_, 2
	note G_, 2
	note As, 2
	note D_, 2
	note As, 2
	note G_, 2
	note As, 2
	note D_, 2
	note A_, 2
	note E_, 2
	note G_, 2
	note C_, 2
	note G_, 2
	note E_, 2
	note G_, 2
	note C_, 2
	note G_, 2
	note F_, 2
	note A_, 2
	note C_, 2
	note A_, 2
	note F_, 2
	note A_, 2
	note G_, 2
	note E_, 2
	note F_, 2
	note A_, 2
	note C_, 2
	note A_, 2
	note F_, 2
	note A_, 2
	note C_, 2
	note A_, 2
	note G_, 2
	note As, 2
	note D_, 2
	note As, 2
	note G_, 2
	note As, 2
	note A_, 2
	note G_, 2
	note C_, 4
	note D_, 4
	note E_, 4
	note G_, 4
	note E_, 4
	note F_, 4
	note Fs, 4
	note G_, 4
	note F_, 2
	note A_, 2
	note C_, 2
	note A_, 2
	note F_, 2
	note A_, 2
	note C_, 2
	note A_, 2
	note F_, 2
	note A_, 2
	note C_, 2
	note A_, 2
	note F_, 2
	note C_, 2
	note F_, 2
	note A_, 2
	sound_loop 0, gbs_elmslab_Ch3.mainloop

gbs_elmslab_Ch4:
	gbs_switch 3
	stereo_panning TRUE, FALSE
	toggle_noise 0
	drum_speed 12
	rest 16
	rest 2
gbs_elmslab_Ch4.mainloop:
	drum_note 8, 4
	sound_loop 0, gbs_elmslab_Ch4.mainloop

	.align 4
	.global gbs_elmslab_Header
gbs_elmslab_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_elmslab_Ch1
	.int gbs_elmslab_Ch2
	.int gbs_elmslab_Ch3
	.int gbs_elmslab_Ch4
