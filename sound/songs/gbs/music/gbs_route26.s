	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_route26_Ch1:
	gbs_switch 0
	stereo_panning FALSE, TRUE
	vibrato 18, 2, 3
	tempo 151
	volume 7, 7
	vibrato 20, 2, 3
	duty_cycle 0
	note_type 12, 10, 7
	octave 3
	note D_, 4
	rest 4
	note Ds, 4
	rest 4
	note Fs, 4
	rest 4
	note Gs, 12
	note_type 8, 10, 7
	octave 4
	note C_, 2
	octave 3
	note Gs, 2
	note Fs, 2
gbs_route26_Ch1.mainloop:
	duty_cycle 0
	note_type 12, 10, 7
	octave 3
	note F_, 1
	rest 2
	note Cs, 1
	note F_, 3
	note G_, 1
	note Gs, 1
	rest 2
	note F_, 1
	octave 4
	note Cs, 4
	note Ds, 4
	octave 3
	note B_, 4
	note A_, 4
	note Fs, 4
	note F_, 1
	rest 1
	note Cs, 1
	note F_, 1
	note Gs, 3
	note G_, 1
	note Gs, 1
	rest 1
	note F_, 1
	note Gs, 1
	octave 4
	note Cs, 4
	note E_, 4
	note Ds, 4
	octave 3
	note A_, 4
	note B_, 4
	note As, 1
	rest 1
	note F_, 1
	note As, 1
	octave 4
	note Cs, 1
	rest 1
	octave 3
	note As, 1
	octave 4
	note Cs, 1
	note F_, 4
	note Cs, 1
	rest 1
	octave 3
	note A_, 1
	rest 1
	note As, 4
	rest 2
	note_type 6, 10, 7
	note As, 1
	rest 1
	note As, 1
	rest 1
	note As, 2
	rest 2
	note As, 2
	rest 2
	note G_, 2
	rest 2
	note G_, 2
	rest 2
	note_type 8, 10, 5
	note Gs, 2
	octave 4
	note Cs, 2
	note Ds, 2
	note Gs, 6
	note Fs, 6
	note Ds, 6
	note Cs, 6
	octave 3
	note As, 6
	octave 4
	note C_, 6
	octave 3
	note Gs, 6
	duty_cycle 2
	note_type 12, 10, 5
	note A_, 3
	note Gs, 3
	note Fs, 4
	note Cs, 2
	note Ds, 2
	note E_, 2
	note Fs, 2
	note B_, 4
	note A_, 2
	note Gs, 2
	note Fs, 2
	note Gs, 2
	note A_, 2
	note Gs, 4
	note Fs, 4
	note E_, 4
	note Ds, 4
	octave 4
	note Cs, 2
	octave 3
	note B_, 2
	note Gs, 2
	note F_, 4
	note Fs, 2
	note_type 6, 10, 5
	note Gs, 7
	octave 4
	note C_, 1
	note Cs, 8
	note_type 8, 10, 5
	octave 3
	note Cs, 1
	rest 1
	note Cs, 1
	rest 1
	note Cs, 1
	rest 1
	note Cs, 6
	note_type 6, 10, 5
	rest 7
	octave 4
	note Ds, 1
	note E_, 8
	note_type 8, 10, 5
	octave 3
	note E_, 1
	rest 1
	note E_, 1
	rest 1
	note E_, 1
	rest 1
	note E_, 6
	rest 6
	note_type 12, 10, 5
	octave 2
	note B_, 1
	note Fs, 1
	note B_, 1
	octave 3
	note E_, 1
	note Fs, 1
	note E_, 1
	note Fs, 1
	note B_, 1
	octave 4
	note E_, 1
	octave 3
	note B_, 1
	octave 4
	note E_, 1
	note Fs, 1
	note B_, 1
	note Fs, 1
	note E_, 1
	octave 3
	note B_, 1
	note Fs, 4
	note Ds, 4
	octave 2
	note B_, 4
	rest 4
	sound_loop 0, gbs_route26_Ch1.mainloop

gbs_route26_Ch2:
	gbs_switch 1
	stereo_panning TRUE, FALSE
	vibrato 20, 2, 3
	duty_cycle 2
	note_type 12, 12, 7
	octave 1
	note As, 4
	rest 2
	note_type 6, 12, 7
	note As, 1
	rest 1
	octave 2
	note As, 1
	rest 1
	octave 1
	note Gs, 8
	rest 4
	note Gs, 1
	rest 1
	octave 2
	note Gs, 1
	rest 1
	octave 1
	note Fs, 8
	rest 4
	note Fs, 1
	rest 1
	octave 2
	note Fs, 1
	rest 1
	note_type 12, 12, 7
	octave 1
	note Gs, 12
	note_type 8, 12, 7
	note Gs, 2
	octave 2
	note C_, 2
	note Ds, 2
gbs_route26_Ch2.mainloop:
	duty_cycle 2
	note_type 12, 12, 2
	octave 2
	note Cs, 6
	note Cs, 1
	note Gs, 1
	note Cs, 2
	note Cs, 2
	note Gs, 2
	note Cs, 2
	octave 1
	note B_, 6
	note B_, 1
	octave 2
	note A_, 1
	octave 1
	note B_, 2
	note B_, 2
	note B_, 2
	note B_, 2
	sound_call gbs_route26_Ch2.sub1
	note A_, 6
	note A_, 1
	octave 2
	note B_, 1
	note_type 8, 12, 2
	octave 1
	note B_, 2
	note B_, 2
	note B_, 2
	octave 2
	note B_, 2
	note B_, 2
	note B_, 2
	note_type 12, 12, 2
	sound_call gbs_route26_Ch2.sub1
	volume_envelope 12, 7
	octave 2
	note Fs, 4
	rest 2
	note_type 6, 12, 2
	note Fs, 2
	note Fs, 2
	note Fs, 4
	note Fs, 4
	note Ds, 4
	note Ds, 4
	note_type 8, 12, 2
gbs_route26_Ch2.loop1:
	octave 2
	note Gs, 2
	note Gs, 2
	note Gs, 2
	octave 1
	note Gs, 6
	sound_loop 3, gbs_route26_Ch2.loop1
	octave 2
	note Gs, 2
	note Gs, 2
	note Gs, 2
	note_type 12, 12, 7
	note Fs, 1
	note Ds, 1
	note C_, 1
	octave 1
	note Gs, 1
	duty_cycle 3
	octave 4
	note Cs, 6
	note Ds, 6
	note E_, 4
	note Fs, 6
	note B_, 4
	note A_, 2
	note Gs, 2
	note A_, 2
	note Gs, 6
	note Ds, 2
	rest 2
	note Ds, 2
	note Gs, 2
	note Ds, 2
	note F_, 2
	rest 2
	note F_, 2
	note Fs, 6
	note Gs, 4
	note A_, 8
	rest 2
	note A_, 2
	note Gs, 2
	note Fs, 2
	note A_, 8
	rest 4
	note Gs, 2
	note A_, 2
	note B_, 12
	rest 4
	note Ds, 12
	note Ds, 1
	note Cs, 1
	note C_, 1
	note Ds, 1
	sound_loop 0, gbs_route26_Ch2.mainloop

gbs_route26_Ch2.sub1:
	note As, 6
	note As, 1
	octave 2
	note As, 1
	octave 1
	note As, 2
	note As, 2
	octave 2
	note As, 2
	octave 1
	note As, 2
	sound_ret

gbs_route26_Ch3:
	gbs_switch 2
	stereo_panning TRUE, TRUE
	vibrato 18, 2, 3
	note_type 12, 1, 4
	vibrato 24, 2, 3
	octave 4
	note As, 4
	rest 2
	note_type 6, 1, 4
	note F_, 1
	rest 1
	note As, 1
	rest 1
	octave 5
	note C_, 8
	rest 4
	octave 4
	note Gs, 1
	rest 1
	octave 5
	note C_, 1
	rest 1
	note Cs, 8
	rest 4
	octave 4
	note As, 1
	rest 1
	octave 5
	note Cs, 1
	rest 1
	note_type 12, 1, 4
	note Ds, 12
	note_type 8, 1, 4
	note Fs, 2
	note F_, 2
	note Ds, 2
gbs_route26_Ch3.mainloop:
	vibrato 24, 2, 3
	note_type 12, 1, 4
	octave 5
	note Cs, 1
	rest 2
	octave 4
	note Gs, 1
	sound_call gbs_route26_Ch3.sub1
	vibrato 37, 1, 3
	note Cs, 1
	rest 1
	octave 4
	note Gs, 1
	octave 5
	note Cs, 1
	sound_call gbs_route26_Ch3.sub1
	note F_, 1
	rest 1
	note Cs, 1
	note F_, 1
	note As, 8
	note As, 1
	rest 1
	octave 6
	note C_, 1
	rest 1
	note Cs, 12
	note Ds, 4
	note Cs, 8
	note C_, 8
	octave 5
	note As, 8
	octave 6
	note C_, 4
	note Gs, 1
	note Ds, 1
	note C_, 1
	octave 5
	note Gs, 1
	volume_envelope 1, 5
	octave 2
	note A_, 1
	rest 1
	note A_, 1
	rest 3
	note_type 6, 1, 5
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note A_, 2
	rest 2
	note A_, 2
	rest 2
	octave 3
	note A_, 2
	rest 2
	octave 2
	note A_, 4
	note B_, 2
	rest 2
	note B_, 2
	rest 6
	note B_, 1
	rest 1
	note B_, 1
	rest 1
	note B_, 2
	rest 2
	note B_, 2
	rest 2
	octave 3
	note B_, 2
	rest 2
	note A_, 4
	note Gs, 2
	rest 2
	octave 2
	note Gs, 2
	rest 6
	note Gs, 1
	rest 1
	note Gs, 1
	rest 1
	note Gs, 2
	rest 2
	note Gs, 2
	rest 2
	octave 3
	note Gs, 2
	rest 2
	octave 2
	note Gs, 2
	rest 2
	octave 3
	note Cs, 2
	rest 10
	note Cs, 1
	rest 1
	note Cs, 1
	rest 1
	note Cs, 2
	rest 2
	note Cs, 2
	rest 2
	octave 4
	note F_, 2
	rest 2
	note Cs, 4
	octave 3
	note Fs, 8
	note_type 8, 1, 5
	octave 2
	note Fs, 1
	rest 1
	note Fs, 1
	rest 1
	note Fs, 1
	rest 1
	note Fs, 6
	rest 6
	octave 4
	note C_, 6
	octave 3
	note C_, 1
	rest 1
	note C_, 1
	rest 1
	note C_, 1
	rest 1
	note C_, 6
	rest 6
	note_type 12, 1, 5
	octave 2
	note B_, 16
	note B_, 8
	octave 3
	note Fs, 4
	note Ds, 1
	rest 1
	octave 2
	note Gs, 1
	octave 3
	note C_, 1
	sound_loop 0, gbs_route26_Ch3.mainloop

gbs_route26_Ch3.sub1:
	octave 5
	note F_, 8
	note Cs, 2
	note F_, 2
	note Gs, 4
	note Fs, 4
	note Cs, 4
	note Ds, 4
	sound_ret

gbs_route26_Ch4:
	gbs_switch 3
	toggle_noise 4
	drum_speed 12
gbs_route26_Ch4.loop1:
	drum_note 12, 6
	drum_note 3, 1
	drum_note 3, 1
	sound_loop 3, gbs_route26_Ch4.loop1
	sound_call gbs_route26_Ch4.sub3
gbs_route26_Ch4.mainloop:
	drum_speed 6
	sound_call gbs_route26_Ch4.sub1
	sound_call gbs_route26_Ch4.sub1
	sound_call gbs_route26_Ch4.sub2
	drum_note 3, 12
	drum_note 3, 2
	drum_note 3, 2
	drum_speed 8
	drum_note 3, 2
	drum_note 2, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 5, 2
	drum_speed 6
	sound_call gbs_route26_Ch4.sub1
	sound_call gbs_route26_Ch4.sub1
	drum_speed 8
gbs_route26_Ch4.loop2:
	drum_note 3, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 12, 6
	sound_loop 4, gbs_route26_Ch4.loop2
	drum_speed 6
	sound_call gbs_route26_Ch4.sub2
	sound_call gbs_route26_Ch4.sub2
	sound_call gbs_route26_Ch4.sub1
	sound_call gbs_route26_Ch4.sub2
gbs_route26_Ch4.loop3:
	drum_speed 6
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 1
	drum_speed 8
	drum_note 3, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 12, 12
	sound_loop 2, gbs_route26_Ch4.loop3
	drum_speed 12
	drum_note 12, 16
	sound_call gbs_route26_Ch4.sub3
	sound_loop 0, gbs_route26_Ch4.mainloop

gbs_route26_Ch4.sub1:
	drum_note 5, 12
	drum_note 3, 2
	drum_note 3, 2
	drum_note 3, 4
	drum_note 3, 4
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	sound_ret

gbs_route26_Ch4.sub2:
	drum_note 5, 12
	drum_note 3, 2
	drum_note 3, 2
	drum_note 3, 4
	drum_note 3, 4
	drum_note 5, 4
	drum_note 3, 4
	sound_ret

gbs_route26_Ch4.sub3:
	drum_speed 6
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_speed 8
	drum_note 3, 2
	drum_note 3, 2
	drum_note 5, 2
	sound_ret

	.align 4
	.global gbs_route26_Header
gbs_route26_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_route26_Ch1
	.int gbs_route26_Ch2
	.int gbs_route26_Ch3
	.int gbs_route26_Ch4
