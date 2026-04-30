	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_route30_Ch1:
	gbs_switch 0
	tempo 144
	volume 7, 7
	duty_cycle 3
	pitch_offset 1
	vibrato 16, 1, 5
	stereo_panning TRUE, FALSE
	note_type 12, 11, 2
	octave 3
	note D_, 6
	note D_, 1
	note D_, 1
	note D_, 2
	note D_, 2
	note D_, 4
	note D_, 6
	note D_, 1
	note D_, 1
	note D_, 2
	note D_, 2
	volume_envelope 4, -6
	note C_, 4
gbs_route30_Ch1.mainloop:
	volume_envelope 11, 6
	note D_, 6
	volume_envelope 11, 4
	octave 2
	note B_, 2
	octave 3
	note F_, 2
	note E_, 2
	note D_, 2
	note E_, 2
	volume_envelope 11, 6
	note F_, 6
	volume_envelope 11, 4
	note C_, 2
	note A_, 2
	note G_, 2
	note F_, 2
	note C_, 2
	note D_, 2
	note G_, 2
	note A_, 2
	note G_, 2
	note F_, 2
	note E_, 2
	note D_, 2
	note E_, 2
	note B_, 1
	octave 4
	note C_, 1
	octave 3
	note B_, 1
	octave 4
	note C_, 1
	volume_envelope 11, 7
	octave 3
	note B_, 12
	volume_envelope 11, 5
	note F_, 6
	note C_, 2
	note A_, 2
	note G_, 2
	note F_, 2
	note C_, 2
	octave 4
	note D_, 2
	note C_, 2
	octave 3
	note B_, 2
	note A_, 2
	octave 4
	note C_, 2
	octave 3
	note B_, 2
	note A_, 2
	note G_, 2
	note D_, 1
	note E_, 1
	note D_, 1
	note E_, 1
	volume_envelope 11, 6
	note D_, 4
	note G_, 4
	note D_, 4
	volume_envelope 11, 3
	octave 2
	note B_, 1
	octave 3
	note C_, 1
	octave 2
	note B_, 1
	octave 3
	note C_, 1
	volume_envelope 11, 6
	octave 2
	note B_, 4
	octave 3
	note D_, 4
	octave 2
	note B_, 4
	volume_envelope 11, 4
	octave 3
	note F_, 2
	note E_, 2
	note D_, 2
	note C_, 2
	note A_, 2
	note G_, 2
	note F_, 2
	note E_, 2
	volume_envelope 11, 6
	note A_, 4
	note B_, 4
	octave 4
	note C_, 4
	note E_, 4
	note D_, 2
	octave 3
	note G_, 4
	note A_, 4
	note B_, 4
	octave 4
	note C_, 2
	octave 3
	note G_, 2
	volume_envelope 11, 7
	note D_, 14
	volume_envelope 11, 6
	note F_, 2
	note E_, 2
	note D_, 2
	note C_, 2
	note A_, 2
	note G_, 2
	note F_, 2
	note G_, 2
	octave 4
	note C_, 2
	octave 3
	note B_, 2
	note A_, 2
	note B_, 2
	octave 4
	note C_, 2
	note E_, 2
	note F_, 2
	note A_, 2
	octave 3
	note G_, 2
	octave 4
	note C_, 2
	note D_, 2
	octave 3
	note G_, 2
	octave 4
	note C_, 2
	note D_, 2
	octave 3
	note G_, 2
	octave 4
	note D_, 2
	volume_envelope 11, 5
	octave 3
	note B_, 2
	octave 4
	note D_, 2
	octave 3
	note B_, 2
	octave 4
	note D_, 4
	octave 3
	note G_, 2
	note B_, 2
	octave 4
	note D_, 2
	sound_loop 0, gbs_route30_Ch1.mainloop

gbs_route30_Ch2:
	gbs_switch 1
	duty_cycle 3
	vibrato 18, 3, 6
	stereo_panning FALSE, TRUE
	note_type 12, 12, 2
	octave 3
	note G_, 6
	note G_, 1
	note G_, 1
	note G_, 2
	note G_, 2
	note G_, 4
	note G_, 6
	note G_, 1
	note G_, 1
	note G_, 2
	note G_, 2
	volume_envelope 12, 4
	note D_, 1
	note E_, 1
	note F_, 1
	note Fs, 1
gbs_route30_Ch2.mainloop:
	volume_envelope 12, 7
	note G_, 10
	octave 4
	note D_, 2
	octave 3
	note B_, 2
	note G_, 2
	octave 4
	note F_, 10
	note E_, 2
	note D_, 2
	note C_, 2
	note D_, 1
	note E_, 1
	note D_, 1
	note E_, 1
	volume_envelope 11, 0
	note D_, 4
	volume_envelope 11, 7
	note D_, 8
	volume_envelope 3, -7
	note D_, 8
	volume_envelope 11, 7
	note D_, 8
	volume_envelope 12, 7
	note C_, 10
	note C_, 2
	octave 3
	note A_, 2
	note F_, 2
	octave 4
	note F_, 10
	note E_, 2
	note D_, 2
	note C_, 2
	octave 3
	note B_, 6
	note G_, 2
	octave 4
	note D_, 8
	octave 3
	note G_, 6
	note D_, 2
	note B_, 8
	note C_, 2
	note A_, 4
	note B_, 4
	octave 4
	note C_, 4
	note D_, 2
	note F_, 8
	note A_, 8
	note G_, 2
	volume_envelope 11, 0
	note D_, 4
	volume_envelope 11, 7
	note D_, 10
	volume_envelope 12, 7
	note C_, 4
	octave 3
	note B_, 4
	note A_, 4
	note G_, 4
	note A_, 4
	note B_, 4
	octave 4
	note C_, 4
	note D_, 4
	note F_, 8
	octave 5
	note C_, 8
	octave 4
	note B_, 2
	volume_envelope 11, 0
	note G_, 6
	volume_envelope 11, 7
	note G_, 8
	volume_envelope 12, 7
	note B_, 2
	volume_envelope 11, 0
	note G_, 4
	volume_envelope 11, 7
	note G_, 8
	volume_envelope 10, 7
	octave 3
	note Fs, 2
	sound_loop 0, gbs_route30_Ch2.mainloop

gbs_route30_Ch3:
	gbs_switch 2
	note_type 12, 2, 7
	octave 2
	note G_, 1
	rest 5
	note G_, 1
	note G_, 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note G_, 1
	rest 3
	note G_, 1
	rest 5
	note G_, 1
	note G_, 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
gbs_route30_Ch3.mainloop:
	note G_, 1
	rest 1
	note B_, 2
	rest 2
	note G_, 1
	note G_, 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note F_, 1
	rest 1
	octave 3
	note D_, 2
	note A_, 2
	octave 2
	note F_, 1
	note F_, 1
	note F_, 1
	rest 1
	octave 3
	note C_, 2
	octave 2
	note F_, 1
	rest 1
	note Fs, 1
	rest 1
	note G_, 1
	rest 1
	note B_, 2
	octave 3
	note D_, 2
	octave 2
	note G_, 1
	note G_, 1
	note G_, 1
	rest 1
	octave 3
	note D_, 2
	octave 2
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 3
	note E_, 2
	note D_, 2
	octave 2
	note G_, 1
	note G_, 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note F_, 1
	rest 1
	octave 3
	note C_, 2
	octave 2
	note A_, 2
	note F_, 1
	note F_, 1
	note F_, 1
	rest 1
	octave 3
	note C_, 2
	octave 2
	note F_, 1
	rest 1
	note F_, 1
	rest 1
	note F_, 1
	rest 1
	octave 3
	note C_, 2
	note F_, 2
	octave 2
	note F_, 1
	note F_, 1
	note F_, 1
	rest 1
	octave 3
	note E_, 2
	octave 2
	note F_, 2
	note Fs, 2
	note G_, 1
	rest 1
	note B_, 2
	octave 3
	note G_, 2
	octave 2
	note G_, 1
	note G_, 1
	note G_, 1
	rest 1
	note B_, 2
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 4
	note D_, 2
	octave 3
	note B_, 2
	octave 2
	note G_, 1
	note G_, 1
	note G_, 1
	rest 1
	octave 3
	note G_, 2
	octave 2
	note G_, 2
	note Gs, 2
	note A_, 1
	rest 1
	octave 3
	note C_, 2
	octave 2
	note B_, 2
	note A_, 1
	note A_, 1
	note A_, 1
	rest 1
	octave 3
	note D_, 2
	octave 2
	note A_, 1
	rest 1
	note B_, 1
	rest 1
	octave 3
	note C_, 1
	rest 1
	note F_, 2
	note E_, 2
	note C_, 1
	note C_, 1
	note C_, 1
	rest 1
	note A_, 2
	note C_, 1
	rest 1
	note C_, 1
	rest 1
	octave 2
	note B_, 1
	rest 1
	octave 3
	note E_, 2
	note D_, 2
	octave 2
	note B_, 1
	note B_, 1
	note B_, 1
	rest 1
	note B_, 1
	rest 1
	note B_, 1
	rest 1
	note B_, 1
	rest 1
	note G_, 1
	rest 1
	note B_, 2
	note A_, 2
	note G_, 1
	note G_, 1
	note G_, 1
	rest 1
	note B_, 2
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note A_, 1
	rest 1
	octave 3
	note C_, 2
	octave 2
	note B_, 2
	note A_, 1
	note A_, 1
	note A_, 1
	rest 1
	octave 3
	note D_, 2
	octave 2
	note A_, 1
	rest 1
	note B_, 1
	rest 1
	octave 3
	note C_, 1
	rest 1
	note F_, 2
	note E_, 2
	note C_, 1
	note C_, 1
	note C_, 1
	rest 1
	note A_, 2
	note C_, 1
	rest 1
	note C_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 3
	note C_, 2
	note D_, 2
	octave 2
	note G_, 1
	note G_, 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 3
	note E_, 2
	note D_, 2
	octave 2
	note G_, 1
	note G_, 1
	note G_, 1
	rest 1
	octave 3
	note D_, 2
	octave 2
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	sound_loop 0, gbs_route30_Ch3.mainloop

gbs_route30_Ch4:
	gbs_switch 3
	toggle_noise 3
	drum_speed 12
	sound_call gbs_route30_Ch4.sub1
	sound_call gbs_route30_Ch4.sub2
gbs_route30_Ch4.mainloop:
	sound_call gbs_route30_Ch4.sub3
	sound_call gbs_route30_Ch4.sub4
	sound_call gbs_route30_Ch4.sub4
	sound_call gbs_route30_Ch4.sub5
	sound_call gbs_route30_Ch4.sub4
	sound_call gbs_route30_Ch4.sub3
	sound_call gbs_route30_Ch4.sub4
	sound_call gbs_route30_Ch4.sub5
	sound_call gbs_route30_Ch4.sub4
	sound_call gbs_route30_Ch4.sub4
	sound_call gbs_route30_Ch4.sub3
	sound_call gbs_route30_Ch4.sub4
	sound_call gbs_route30_Ch4.sub4
	sound_call gbs_route30_Ch4.sub4
	sound_call gbs_route30_Ch4.sub3
	sound_call gbs_route30_Ch4.sub5
	sound_loop 0, gbs_route30_Ch4.mainloop

gbs_route30_Ch4.sub1:
	drum_note 3, 2
	drum_note 7, 2
	drum_note 7, 2
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 2
	drum_note 3, 2
	drum_note 3, 4
	sound_ret

gbs_route30_Ch4.sub2:
	drum_note 3, 2
	drum_note 7, 2
	drum_note 7, 2
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 2
	drum_note 3, 2
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 1
	sound_ret

gbs_route30_Ch4.sub3:
	drum_note 3, 2
	drum_note 7, 2
	drum_note 7, 2
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 3, 2
	sound_ret

gbs_route30_Ch4.sub4:
	drum_note 3, 2
	drum_note 7, 2
	drum_note 7, 2
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 3, 2
	sound_ret

gbs_route30_Ch4.sub5:
	drum_note 3, 2
	drum_note 7, 2
	drum_note 7, 2
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 2
	drum_note 3, 2
	drum_speed 6
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 1
	drum_speed 12
	sound_ret

	.align 4
	.global gbs_route30_Header
gbs_route30_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_route30_Ch1
	.int gbs_route30_Ch2
	.int gbs_route30_Ch3
	.int gbs_route30_Ch4
