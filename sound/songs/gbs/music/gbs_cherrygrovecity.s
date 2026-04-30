	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_cherrygrovecity_Ch1:
	gbs_switch 0
	tempo 152
	volume 7, 7
	duty_cycle 3
	pitch_offset 1
	vibrato 8, 1, 5
	stereo_panning TRUE, FALSE
	note_type 12, 11, 5
	rest 10
	octave 3
	note C_, 2
	note D_, 2
	note E_, 2
gbs_cherrygrovecity_Ch1.mainloop:
	note A_, 4
	note Gs, 2
	note A_, 2
	note As, 2
	note A_, 2
	note G_, 2
	note F_, 2
	note A_, 6
	note F_, 2
	note C_, 2
	octave 2
	note As, 2
	octave 3
	note C_, 2
	note E_, 2
	note G_, 4
	note Fs, 2
	note G_, 2
	note A_, 2
	note G_, 2
	note F_, 2
	note E_, 2
	note G_, 6
	note E_, 2
	note C_, 2
	octave 2
	note As, 2
	note A_, 2
	octave 3
	note C_, 2
	volume_envelope 11, 7
	octave 2
	note As, 6
	octave 3
	note D_, 6
	note As, 4
	note A_, 6
	note F_, 2
	note C_, 8
	octave 2
	note As, 6
	octave 3
	note D_, 6
	volume_envelope 11, 5
	note A_, 4
	note G_, 4
	note E_, 4
	note D_, 4
	note E_, 4
	octave 2
	note As, 6
	octave 3
	note D_, 6
	note As, 4
	note A_, 6
	note F_, 2
	note C_, 4
	octave 2
	note B_, 4
	note As, 6
	octave 3
	note Cs, 2
	octave 2
	note As, 4
	note G_, 4
	note A_, 4
	octave 3
	note C_, 4
	octave 2
	note A_, 4
	octave 3
	note C_, 4
	sound_loop 0, gbs_cherrygrovecity_Ch1.mainloop

gbs_cherrygrovecity_Ch2:
	gbs_switch 1
	duty_cycle 3
	vibrato 16, 3, 6
	stereo_panning FALSE, TRUE
	note_type 12, 12, 3
	octave 3
	note C_, 2
	note D_, 2
	note E_, 2
	note D_, 2
	note E_, 2
	note G_, 2
	note A_, 2
	note As, 2
gbs_cherrygrovecity_Ch2.mainloop:
	volume_envelope 12, 6
	octave 4
	note C_, 6
	note D_, 4
	volume_envelope 11, 3
	note D_, 2
	note C_, 2
	octave 3
	note As, 2
	volume_envelope 12, 7
	octave 4
	note C_, 6
	octave 3
	note A_, 2
	note F_, 8
	volume_envelope 12, 6
	note As, 6
	octave 4
	note C_, 4
	volume_envelope 11, 3
	note C_, 2
	octave 3
	note As, 2
	note A_, 2
	volume_envelope 12, 7
	note As, 6
	note G_, 2
	note E_, 8
	volume_envelope 10, 0
	note D_, 6
	note F_, 6
	octave 4
	note D_, 4
	note C_, 6
	volume_envelope 10, 5
	octave 3
	note A_, 2
	volume_envelope 12, 7
	note F_, 8
	volume_envelope 10, 0
	note D_, 6
	note F_, 6
	octave 4
	note D_, 4
	volume_envelope 12, 7
	note C_, 16
	volume_envelope 11, 5
	octave 3
	note D_, 6
	note F_, 6
	octave 4
	note D_, 4
	note C_, 6
	octave 3
	note A_, 2
	note F_, 8
	note Cs, 6
	note F_, 6
	note G_, 4
	volume_envelope 10, 0
	note F_, 8
	volume_envelope 10, 7
	note F_, 8
	sound_loop 0, gbs_cherrygrovecity_Ch2.mainloop

gbs_cherrygrovecity_Ch3:
	gbs_switch 2
	note_type 12, 1, 6
	rest 4
	octave 4
	note C_, 2
	octave 3
	note As, 2
	note A_, 2
	note G_, 2
	note F_, 2
	note E_, 2
gbs_cherrygrovecity_Ch3.mainloop:
	note A_, 2
	note F_, 2
	note A_, 2
	octave 4
	note C_, 4
	octave 3
	note F_, 2
	note G_, 2
	note A_, 2
	note A_, 2
	note F_, 2
	note A_, 2
	octave 4
	note C_, 4
	octave 3
	note F_, 2
	note G_, 2
	note A_, 2
	note As, 2
	note G_, 2
	note As, 2
	octave 4
	note C_, 4
	octave 3
	note F_, 2
	note G_, 2
	note A_, 2
	note As, 4
	octave 4
	note C_, 2
	octave 3
	note As, 2
	note A_, 2
	note G_, 2
	note F_, 2
	note E_, 2
	note D_, 2
	note F_, 4
	note As, 2
	note F_, 2
	note As, 2
	note A_, 2
	note G_, 2
	note F_, 2
	note A_, 4
	note F_, 2
	note A_, 2
	note F_, 2
	note E_, 2
	note Ds, 2
	note D_, 2
	note F_, 4
	note As, 2
	note F_, 2
	note As, 2
	note A_, 2
	note G_, 2
	note E_, 2
	note G_, 2
	note As, 2
	octave 4
	note C_, 2
	octave 3
	note As, 2
	note A_, 2
	note G_, 2
	note F_, 2
	note D_, 2
	note F_, 4
	note As, 2
	note F_, 2
	note As, 2
	note A_, 2
	note G_, 2
	note F_, 2
	note A_, 4
	note F_, 2
	note A_, 2
	note F_, 2
	note E_, 2
	note Ds, 2
	note Cs, 2
	note F_, 4
	note As, 2
	note F_, 2
	note As, 2
	note A_, 2
	note G_, 2
	note F_, 2
	note A_, 2
	note F_, 2
	note A_, 2
	note F_, 2
	note A_, 2
	note F_, 2
	note A_, 2
	sound_loop 0, gbs_cherrygrovecity_Ch3.mainloop

gbs_cherrygrovecity_Ch4:
	gbs_switch 3
	toggle_noise 3
	drum_speed 12
	rest 16
gbs_cherrygrovecity_Ch4.mainloop:
	drum_note 2, 2
	rest 2
	drum_note 8, 2
	drum_note 2, 2
	drum_note 2, 2
	drum_note 7, 2
	drum_note 2, 4
	drum_note 2, 2
	rest 2
	drum_note 8, 2
	drum_note 2, 1
	drum_note 2, 1
	drum_note 7, 4
	drum_note 2, 2
	drum_note 8, 2
	sound_loop 0, gbs_cherrygrovecity_Ch4.mainloop

	.align 4
	.global gbs_cherrygrovecity_Header
gbs_cherrygrovecity_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_cherrygrovecity_Ch1
	.int gbs_cherrygrovecity_Ch2
	.int gbs_cherrygrovecity_Ch3
	.int gbs_cherrygrovecity_Ch4
