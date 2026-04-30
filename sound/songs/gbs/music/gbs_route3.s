	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_route3_Ch1:
	gbs_switch 0
	stereo_panning FALSE, TRUE
	tempo 160
	volume 7, 7
	note_type 12, 9, 1
	rest 10
	duty_cycle 0
	vibrato 20, 0, 6
	octave 3
	note Cs, 1
	note E_, 1
	note Cs, 1
	note E_, 1
	note A_, 1
	note E_, 1
	note Cs, 1
	note E_, 1
	note A_, 1
	note E_, 1
	note Cs, 1
	note E_, 1
	note Cs, 1
	note E_, 1
	note Cs, 1
	note E_, 1
	note A_, 1
	note F_, 1
	note D_, 1
	note F_, 1
	note D_, 1
	note F_, 1
	note D_, 1
	note F_, 1
	note Cs, 1
	note E_, 1
	note A_, 1
	note E_, 1
	note Cs, 1
	note E_, 1
	note Fs, 1
	note Gs, 1
gbs_route3_Ch1.mainloop:
	sound_call gbs_route3_Ch1.sub1
	note G_, 1
	note D_, 1
	octave 2
	note B_, 1
	octave 3
	note D_, 1
	note G_, 1
	note D_, 1
	octave 2
	note B_, 1
	octave 3
	note D_, 1
	note G_, 1
	note D_, 1
	octave 2
	note B_, 1
	octave 3
	note D_, 1
	octave 2
	note B_, 1
	octave 3
	note D_, 1
	octave 2
	note B_, 1
	octave 3
	note D_, 1
	note A_, 1
	note E_, 1
	note Cs, 1
	note E_, 1
	note A_, 1
	note E_, 1
	note Cs, 1
	note E_, 1
	note A_, 1
	note E_, 1
	note Cs, 1
	note E_, 1
	note Cs, 1
	note E_, 1
	note Cs, 1
	note E_, 1
	note A_, 1
	note E_, 1
	note Cs, 1
	note E_, 1
	note A_, 1
	note E_, 1
	note Cs, 1
	note E_, 1
	note A_, 1
	note E_, 1
	note Cs, 1
	note E_, 1
	note Cs, 1
	note E_, 1
	note Cs, 1
	note E_, 1
	note G_, 1
	note D_, 1
	octave 2
	note B_, 1
	octave 3
	note D_, 1
	note G_, 1
	note D_, 1
	octave 2
	note B_, 1
	octave 3
	note D_, 1
	note G_, 1
	note D_, 1
	octave 2
	note B_, 1
	octave 3
	note D_, 1
	octave 2
	note B_, 1
	octave 3
	note D_, 1
	octave 2
	note B_, 1
	octave 3
	note D_, 1
	volume_envelope 6, -7
	note G_, 1
	note D_, 1
	volume_envelope 7, 7
	octave 2
	note B_, 1
	octave 3
	note D_, 1
	note G_, 1
	note D_, 1
	note E_, 1
	note Gs, 1
	note B_, 4
	volume_envelope 6, -7
	octave 3
	note Gs, 2
	note E_, 2
	note A_, 2
	note Gs, 2
	note A_, 2
	note E_, 8
	note Ds, 1
	note E_, 1
	note Gs, 2
	octave 2
	note B_, 4
	octave 3
	note D_, 2
	note E_, 2
	note Gs, 2
	note B_, 2
	note A_, 1
	note Gs, 1
	note F_, 3
	note E_, 3
	note D_, 2
	octave 2
	note A_, 2
	octave 3
	note D_, 2
	note E_, 2
	note F_, 2
	volume_envelope 9, 1
	note Fs, 1
	note D_, 1
	octave 2
	note A_, 1
	octave 3
	note D_, 1
	note Fs, 1
	note A_, 1
	note Fs, 1
	note A_, 1
	note B_, 1
	note Gs, 1
	note E_, 1
	note Gs, 1
	note E_, 1
	note Gs, 1
	note B_, 1
	octave 4
	note D_, 1
	sound_loop 0, gbs_route3_Ch1.mainloop

gbs_route3_Ch1.sub1:
gbs_route3_Ch1.sub1loop1:
	octave 3
	note A_, 1
	note E_, 1
	note Cs, 1
	note E_, 1
	sound_loop 3, gbs_route3_Ch1.sub1loop1
	note Cs, 1
	note E_, 1
	note Cs, 1
	note E_, 1
gbs_route3_Ch1.sub1loop2:
	note A_, 1
	note E_, 1
	note Cs, 1
	note E_, 1
	sound_loop 3, gbs_route3_Ch1.sub1loop2
	note Cs, 1
	note E_, 1
	note Cs, 1
	note E_, 1
gbs_route3_Ch1.sub1loop3:
	note G_, 1
	note D_, 1
	octave 2
	note B_, 1
	octave 3
	note D_, 1
	sound_loop 3, gbs_route3_Ch1.sub1loop3
	octave 2
	note B_, 1
	octave 3
	note D_, 1
	octave 2
	note B_, 1
	octave 3
	note D_, 1
	sound_ret

gbs_route3_Ch2:
	gbs_switch 1
	stereo_panning TRUE, FALSE
	note_type 12, 5, -6
	duty_cycle 2
	vibrato 6, 0, 3
	octave 4
	note E_, 1
	note G_, 1
	note Gs, 6
	volume_envelope 8, 7
	note Fs, 1
	note Gs, 1
	note A_, 1
	rest 7
	note Cs, 4
	note E_, 4
	note D_, 4
	octave 3
	note B_, 4
	octave 4
	note Cs, 4
	volume_envelope 10, 7
	duty_cycle 2
	octave 3
	note A_, 1
	octave 4
	note Cs, 1
	note E_, 1
	note Gs, 1
gbs_route3_Ch2.mainloop:
	volume_envelope 7, -5
	sound_call gbs_route3_Ch2.sub1
	note G_, 1
	note B_, 10
	volume_envelope 11, 7
	note B_, 6
	volume_envelope 7, -5
	rest 4
	duty_cycle 3
	note Gs, 4
	sound_call gbs_route3_Ch2.sub1
	note B_, 1
	volume_envelope 7, -5
	octave 5
	note D_, 5
	volume_envelope 11, 7
	octave 5
	note D_, 5
	duty_cycle 0
	octave 3
	note D_, 1
	note G_, 1
	note B_, 1
	rest 1
	note G_, 1
	note B_, 1
	octave 4
	note D_, 4
	volume_envelope 8, -7
	duty_cycle 2
	octave 4
	note E_, 2
	note D_, 2
	note Cs, 2
	octave 3
	note B_, 2
	octave 4
	note Cs, 2
	octave 3
	note A_, 8
	note Gs, 1
	note A_, 1
	note B_, 2
	note E_, 4
	octave 4
	note E_, 8
	note D_, 1
	note Cs, 1
	note D_, 3
	note Cs, 3
	octave 3
	note A_, 10
	duty_cycle 2
	octave 4
	note Fs, 6
	note E_, 1
	note Fs, 1
	note Gs, 6
	note Fs, 1
	note Gs, 1
	sound_loop 0, gbs_route3_Ch2.mainloop

gbs_route3_Ch2.sub1:
	note A_, 6
	note E_, 1
	note A_, 1
	octave 5
	note Cs, 7
	volume_envelope 11, 7
	octave 5
	note Cs, 3
	volume_envelope 7, -5
	octave 4
	note E_, 2
	note A_, 2
	octave 5
	note E_, 2
	note D_, 2
	note Cs, 2
	octave 4
	note B_, 2
	note A_, 2
	note G_, 6
	note D_, 1
	sound_ret

gbs_route3_Ch3:
	gbs_switch 2
	stereo_panning TRUE, TRUE
	vibrato 6, 0, 3
	note_type 12, 1, 3
	octave 3
	note B_, 1
	octave 4
	note D_, 1
	note E_, 6
	note D_, 1
	octave 3
	note B_, 1
	volume_envelope 1, 4
	octave 3
	note A_, 1
	rest 1
	octave 2
	note A_, 2
	rest 2
	note A_, 1
	note A_, 1
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note Gs, 2
	sound_call gbs_route3_Ch3.sub1
gbs_route3_Ch3.mainloop:
	volume_envelope 1, 4
	sound_call gbs_route3_Ch3.sub1
	sound_call gbs_route3_Ch3.sub1
	sound_call gbs_route3_Ch3.sub2
	sound_call gbs_route3_Ch3.sub1
	sound_call gbs_route3_Ch3.sub1
	sound_call gbs_route3_Ch3.sub2
	note A_, 2
	octave 3
	note Cs, 2
	note E_, 2
	note A_, 6
	note Gs, 2
	note Fs, 2
	note E_, 2
	note D_, 2
	octave 2
	note B_, 2
	note Gs, 2
	note E_, 1
	rest 1
	note E_, 2
	note B_, 2
	octave 3
	note E_, 2
	note F_, 6
	note E_, 2
	note D_, 2
	octave 2
	note B_, 2
	octave 3
	note C_, 2
	note Cs, 2
	note D_, 1
	rest 1
	note D_, 2
	rest 2
	note D_, 1
	note D_, 1
	note E_, 1
	rest 1
	note E_, 2
	rest 2
	note Fs, 1
	note Gs, 1
	sound_loop 0, gbs_route3_Ch3.mainloop

gbs_route3_Ch3.sub1:
	octave 3
	note A_, 1
	rest 1
	octave 2
	note A_, 2
	rest 2
	note A_, 1
	note A_, 1
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	octave 3
	note A_, 2
	octave 2
	note Gs, 2
	sound_ret

gbs_route3_Ch3.sub2:
	octave 3
	note G_, 1
	rest 1
	octave 2
	note A_, 2
	rest 2
	note A_, 1
	note A_, 1
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	octave 3
	note D_, 2
	note G_, 2
	note G_, 1
	rest 1
	octave 2
	note G_, 2
	rest 2
	note G_, 1
	note G_, 1
	note E_, 1
	rest 1
	note E_, 1
	rest 1
	note Gs, 2
	note B_, 2
	sound_ret

gbs_route3_Ch4:
	gbs_switch 3
	toggle_noise 4
	drum_speed 12
	rest 10
gbs_route3_Ch4.mainloop:
	drum_speed 12
	drum_note 3, 2
	drum_note 3, 4
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 2
	drum_note 3, 2
	drum_speed 6
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	sound_loop 0, gbs_route3_Ch4.mainloop

	.align 4
	.global gbs_route3_Header
gbs_route3_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_route3_Ch1
	.int gbs_route3_Ch2
	.int gbs_route3_Ch3
	.int gbs_route3_Ch4
