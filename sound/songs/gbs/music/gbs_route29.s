	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_route29_Ch1:
	gbs_switch 0
	tempo 146
	volume 7, 7
	duty_cycle 3
	pitch_offset 1
	vibrato 16, 1, 5
	stereo_panning FALSE, TRUE
	note_type 12, 11, 2
	rest 2
gbs_route29_Ch1.mainloop:
	rest 2
	octave 4
	note C_, 2
	note E_, 2
	note C_, 4
	octave 3
	note A_, 2
	octave 4
	note C_, 2
	octave 3
	note G_, 4
	note A_, 2
	note Fs, 2
	note C_, 4
	octave 4
	note D_, 2
	octave 3
	note B_, 2
	note D_, 4
	octave 4
	note C_, 2
	note E_, 2
	note C_, 4
	octave 3
	note A_, 2
	octave 4
	note C_, 2
	octave 3
	note A_, 4
	note A_, 2
	note C_, 2
	note D_, 2
	note G_, 2
	note C_, 2
	note C_, 4
	note G_, 2
	octave 4
	note C_, 2
	note E_, 2
	note C_, 2
	octave 3
	note E_, 2
	note A_, 2
	octave 4
	note C_, 2
	octave 3
	note G_, 2
	note F_, 1
	note G_, 1
	note A_, 2
	note C_, 2
	note Fs, 2
	note D_, 2
	octave 4
	note D_, 2
	octave 3
	note B_, 4
	note E_, 2
	octave 4
	note C_, 2
	note E_, 2
	note E_, 2
	octave 3
	note E_, 2
	note G_, 2
	octave 4
	note C_, 2
	octave 3
	note G_, 2
	note D_, 1
	note G_, 1
	octave 4
	note C_, 2
	octave 3
	note B_, 2
	note G_, 2
	note E_, 1
	note F_, 1
	note G_, 2
	note G_, 2
	note F_, 8
	volume_envelope 11, 4
	note A_, 4
	octave 4
	note C_, 2
	octave 3
	note A_, 10
	note E_, 4
	note G_, 2
	note E_, 2
	volume_envelope 11, 2
	note G_, 6
	volume_envelope 11, 4
	note F_, 4
	note A_, 2
	note G_, 2
	note F_, 2
	volume_envelope 11, 2
	note A_, 4
	volume_envelope 11, 4
	note Cs, 4
	note E_, 2
	note G_, 4
	volume_envelope 11, 3
	note E_, 8
	volume_envelope 11, 4
	note A_, 2
	note G_, 2
	note A_, 2
	octave 4
	note C_, 4
	volume_envelope 11, 2
	octave 3
	note A_, 6
	volume_envelope 11, 4
	note G_, 2
	note E_, 2
	note G_, 2
	octave 4
	note C_, 4
	octave 3
	note G_, 2
	octave 4
	note D_, 2
	note C_, 2
	octave 3
	note B_, 2
	note A_, 2
	volume_envelope 11, 2
	note G_, 4
	note B_, 4
	volume_envelope 11, 4
	note G_, 2
	note E_, 2
	octave 4
	note C_, 2
	octave 3
	note E_, 4
	note E_, 2
	octave 4
	note C_, 2
	octave 3
	note E_, 2
	note G_, 4
	octave 4
	note C_, 2
	octave 3
	note E_, 2
	volume_envelope 11, 2
	note C_, 2
	note G_, 2
	note G_, 4
	sound_loop 0, gbs_route29_Ch1.mainloop

gbs_route29_Ch2:
	gbs_switch 1
	duty_cycle 3
	vibrato 18, 3, 6
	note_type 12, 12, 2
	octave 4
	note C_, 1
	note D_, 1
gbs_route29_Ch2.mainloop:
	sound_call gbs_route29_Ch2.sub1
	note F_, 1
	note E_, 1
	note D_, 2
	note D_, 2
	octave 3
	note B_, 2
	octave 4
	note C_, 2
	octave 3
	note E_, 2
	note E_, 2
	octave 4
	note C_, 1
	note D_, 1
	sound_call gbs_route29_Ch2.sub1
	note F_, 1
	note E_, 1
	note D_, 2
	note D_, 2
	octave 3
	note B_, 2
	volume_envelope 12, 4
	octave 4
	note C_, 8
	octave 3
	note A_, 2
	note A_, 2
	octave 4
	note C_, 2
	note C_, 2
	note F_, 2
	note A_, 2
	note G_, 2
	note F_, 2
	octave 3
	note G_, 2
	note G_, 2
	octave 4
	note C_, 2
	note C_, 2
	note E_, 2
	note G_, 2
	note F_, 2
	note E_, 2
	octave 3
	note F_, 2
	note F_, 2
	note A_, 2
	note A_, 2
	octave 4
	note D_, 2
	note F_, 2
	note E_, 2
	note D_, 2
	note E_, 2
	note D_, 2
	note Cs, 2
	note D_, 2
	note Cs, 2
	octave 3
	note As, 2
	note A_, 2
	note G_, 2
	note A_, 2
	note A_, 2
	octave 4
	note C_, 2
	note C_, 2
	note F_, 2
	note A_, 2
	note G_, 2
	note F_, 2
	octave 3
	note G_, 2
	note G_, 2
	octave 4
	note C_, 2
	note C_, 2
	note E_, 2
	note G_, 2
	note F_, 2
	note E_, 2
	note F_, 2
	note E_, 2
	note D_, 2
	note F_, 2
	volume_envelope 12, 2
	note E_, 4
	note D_, 4
	volume_envelope 12, 4
	note C_, 2
	octave 3
	note G_, 2
	octave 4
	note E_, 2
	octave 3
	note G_, 2
	octave 4
	note C_, 2
	octave 3
	note G_, 2
	octave 4
	note E_, 2
	octave 3
	note G_, 2
	octave 4
	note C_, 2
	octave 3
	note G_, 2
	octave 4
	note E_, 2
	octave 3
	note G_, 2
	volume_envelope 12, 2
	octave 4
	note C_, 2
	note C_, 2
	note C_, 2
	octave 4
	note C_, 1
	note D_, 1
	sound_loop 0, gbs_route29_Ch2.mainloop

gbs_route29_Ch2.sub1:
	note E_, 2
	note E_, 2
	note G_, 2
	note G_, 2
	note C_, 2
	note D_, 2
	note E_, 2
	note C_, 2
	note F_, 1
	note E_, 1
	note D_, 2
	octave 3
	note B_, 2
	note A_, 2
	note G_, 2
	octave 4
	note A_, 2
	note G_, 2
	note C_, 1
	note D_, 1
	note E_, 2
	note E_, 2
	note G_, 2
	note G_, 2
	note C_, 2
	note D_, 2
	note E_, 2
	note C_, 2
	sound_ret

gbs_route29_Ch3:
	gbs_switch 2
	stereo_panning TRUE, FALSE
	note_type 12, 2, 5
	vibrato 9, 2, 7
	rest 2
gbs_route29_Ch3.mainloop:
	rest 2
	octave 3
	note G_, 1
	rest 1
	octave 4
	note C_, 1
	rest 1
	note E_, 1
	rest 3
	note E_, 1
	rest 1
	octave 3
	note A_, 1
	rest 1
	octave 4
	note E_, 1
	rest 1
	octave 3
	note F_, 1
	rest 1
	octave 4
	note C_, 1
	rest 3
	octave 3
	note A_, 1
	rest 1
	note G_, 1
	rest 1
	octave 4
	note C_, 1
	rest 1
	octave 3
	note B_, 1
	rest 1
	note G_, 1
	rest 1
	octave 4
	note C_, 1
	rest 1
	octave 3
	note G_, 1
	rest 1
	octave 4
	note C_, 1
	rest 1
	note E_, 1
	rest 3
	note C_, 1
	rest 1
	note E_, 1
	rest 1
	note E_, 1
	rest 1
	octave 3
	note F_, 1
	rest 1
	octave 4
	note C_, 1
	rest 1
	octave 3
	note G_, 1
	rest 1
	note B_, 1
	rest 1
	octave 4
	note E_, 1
	rest 1
	octave 3
	note G_, 1
	rest 1
	note G_, 1
	rest 3
	note E_, 4
	note G_, 4
	octave 4
	note C_, 4
	octave 3
	note G_, 4
	note F_, 4
	note Fs, 4
	octave 4
	note C_, 4
	octave 3
	note B_, 4
	note E_, 4
	note G_, 4
	octave 4
	note C_, 4
	octave 3
	note G_, 2
	note E_, 2
	note G_, 2
	octave 4
	note C_, 2
	octave 3
	note B_, 2
	note G_, 2
	octave 4
	note C_, 2
	octave 3
	note B_, 2
	octave 4
	note C_, 2
	note D_, 2
	note C_, 6
	octave 3
	note F_, 6
	note A_, 4
	octave 4
	note C_, 6
	octave 3
	note G_, 6
	note A_, 2
	note As, 2
	note B_, 6
	note G_, 6
	octave 4
	note D_, 2
	note F_, 2
	octave 3
	note A_, 6
	note E_, 2
	octave 4
	note E_, 2
	note Cs, 2
	octave 3
	note A_, 2
	note G_, 2
	note A_, 6
	octave 4
	note C_, 6
	octave 3
	note A_, 4
	note G_, 6
	octave 4
	note C_, 6
	note F_, 2
	note E_, 2
	note F_, 6
	note F_, 2
	note E_, 2
	rest 2
	note D_, 2
	octave 3
	note B_, 2
	octave 4
	note C_, 6
	octave 3
	note G_, 6
	octave 4
	note C_, 4
	note E_, 4
	note C_, 4
	octave 3
	note G_, 1
	rest 1
	octave 4
	note C_, 1
	rest 1
	note C_, 1
	rest 3
	sound_loop 0, gbs_route29_Ch3.mainloop

gbs_route29_Ch4:
	gbs_switch 3
	stereo_panning FALSE, TRUE
	toggle_noise 0
	drum_speed 12
	rest 2
gbs_route29_Ch4.mainloop:
	rest 2
	drum_note 6, 2
	drum_note 6, 6
	drum_note 6, 2
	drum_note 6, 2
	drum_note 6, 2
	rest 2
	drum_note 6, 4
	drum_note 6, 4
	drum_note 6, 2
	drum_note 6, 4
	sound_loop 0, gbs_route29_Ch4.mainloop

	.align 4
	.global gbs_route29_Header
gbs_route29_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_route29_Ch1
	.int gbs_route29_Ch2
	.int gbs_route29_Ch3
	.int gbs_route29_Ch4
