	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_gym_Ch1:
	gbs_switch 0
	tempo 156
	volume 7, 7
	stereo_panning FALSE, TRUE
	vibrato 18, 2, 4
	duty_cycle 1
	note_type 12, 11, 7
gbs_gym_Ch1.mainloop:
	octave 4
	note Fs, 2
	octave 2
	note A_, 1
	note A_, 1
	note A_, 1
	rest 3
	octave 4
	note E_, 2
	octave 2
	note G_, 1
	note G_, 1
	note G_, 1
	rest 3
	octave 4
	note D_, 2
	octave 2
	note D_, 1
	note D_, 1
	note D_, 1
	rest 1
	octave 3
	note D_, 1
	note D_, 1
	note B_, 1
	note G_, 1
	note D_, 1
	note B_, 1
	octave 4
	note Cs, 1
	octave 3
	note A_, 1
	note E_, 1
	octave 4
	note E_, 1
	octave 3
	note A_, 12
	note Fs, 2
	note A_, 2
	note G_, 1
	rest 2
	note E_, 1
	note E_, 2
	note C_, 2
	octave 4
	note C_, 2
	octave 3
	note B_, 2
	note A_, 2
	note G_, 2
	note Fs, 8
	note A_, 4
	note Fs, 2
	note A_, 2
	note E_, 1
	rest 1
	note E_, 1
	note Fs, 1
	note G_, 4
	octave 4
	note C_, 2
	octave 3
	note B_, 2
	note A_, 2
	octave 4
	note C_, 2
	note D_, 6
	octave 3
	note A_, 2
	note Fs, 2
	note E_, 2
	note G_, 2
	note A_, 2
	note B_, 1
	rest 2
	note G_, 1
	note G_, 4
	octave 4
	note E_, 1
	rest 2
	note C_, 1
	note C_, 2
	octave 3
	note B_, 1
	note As, 1
	note A_, 12
	note Fs, 2
	note A_, 2
	octave 4
	note C_, 2
	octave 3
	note G_, 1
	octave 4
	note C_, 1
	note E_, 2
	note C_, 2
	note E_, 2
	note C_, 1
	note E_, 1
	note G_, 4
	note D_, 6
	octave 3
	note A_, 1
	rest 3
	note A_, 1
	rest 1
	note A_, 1
	octave 4
	note Fs, 3
	note G_, 4
	note Fs, 4
	note E_, 4
	note C_, 4
	note D_, 1
	rest 1
	note D_, 1
	note E_, 1
	rest 2
	octave 3
	note B_, 4
	note Fs, 2
	note D_, 2
	note Fs, 2
	note As, 1
	note A_, 1
	note G_, 1
	note F_, 1
	octave 4
	note D_, 4
	note C_, 1
	octave 3
	note As, 1
	note A_, 1
	note G_, 1
	octave 4
	note E_, 4
	note Fs, 6
	octave 3
	note A_, 1
	rest 3
	note A_, 1
	rest 1
	note A_, 1
	octave 4
	note Fs, 3
	note A_, 4
	note G_, 4
	note Fs, 4
	note E_, 4
	note D_, 1
	octave 3
	note B_, 1
	note Fs, 1
	octave 4
	note E_, 1
	note Fs, 4
	note E_, 1
	note C_, 1
	octave 3
	note G_, 1
	octave 4
	note Fs, 1
	note G_, 4
	note A_, 1
	note G_, 1
	note Fs, 1
	note E_, 1
	note A_, 4
	octave 5
	note D_, 4
	octave 4
	note A_, 1
	note G_, 1
	note Fs, 1
	note E_, 1
	sound_loop 0, gbs_gym_Ch1.mainloop

gbs_gym_Ch2:
	gbs_switch 1
	duty_cycle 1
	stereo_panning TRUE, FALSE
gbs_gym_Ch2.mainloop:
	note_type 12, 12, 3
	octave 2
	note D_, 2
	octave 1
	note D_, 1
	note D_, 1
	note D_, 2
	note A_, 1
	octave 2
	note Fs, 1
	note C_, 2
	octave 1
	note C_, 1
	note C_, 1
	note C_, 2
	octave 2
	note G_, 1
	note E_, 1
	octave 1
	note G_, 2
	octave 1
	note G_, 1
	note G_, 1
	note G_, 2
	octave 1
	note G_, 1
	note G_, 1
	note A_, 4
	octave 2
	note A_, 2
	octave 3
	note C_, 1
	note Cs, 1
	sound_call gbs_gym_Ch2.sub1
	octave 3
	note E_, 2
	note C_, 1
	note Cs, 1
	sound_call gbs_gym_Ch2.sub1
	octave 3
	note C_, 1
	note E_, 1
	note G_, 1
	octave 4
	note C_, 1
	volume_envelope 13, 2
	sound_call gbs_gym_Ch2.sub2
	octave 1
	note Fs, 1
	note B_, 1
	note Fs, 2
	octave 2
	note Fs, 2
	octave 1
	note B_, 2
	note As, 4
	note As, 2
	note F_, 1
	note F_, 1
	note G_, 1
	octave 2
	note C_, 1
	octave 1
	note G_, 2
	octave 2
	note G_, 2
	note E_, 2
	sound_call gbs_gym_Ch2.sub2
	octave 1
	note G_, 1
	octave 2
	note C_, 1
	octave 1
	note G_, 2
	octave 2
	note E_, 2
	note C_, 2
	note D_, 4
	note D_, 2
	octave 1
	note A_, 1
	note A_, 1
	note A_, 1
	octave 2
	note D_, 1
	octave 1
	note A_, 2
	octave 2
	note Fs, 2
	note D_, 2
	sound_loop 0, gbs_gym_Ch2.mainloop

gbs_gym_Ch2.sub1:
	octave 3
	note D_, 3
	octave 2
	note D_, 3
	note D_, 2
	note D_, 1
	note D_, 1
	note D_, 2
	octave 3
	note D_, 2
	octave 2
	note A_, 2
	octave 3
	note C_, 3
	octave 2
	note C_, 3
	note C_, 2
	note C_, 1
	note C_, 1
	note C_, 2
	octave 3
	note E_, 2
	note C_, 1
	note Cs, 1
	note D_, 3
	octave 2
	note D_, 3
	note D_, 2
	note D_, 1
	note D_, 1
	note D_, 2
	octave 3
	note D_, 2
	octave 2
	note A_, 2
	octave 3
	note C_, 3
	octave 2
	note C_, 3
	note C_, 2
	note C_, 1
	note C_, 1
	note C_, 2
	sound_ret

gbs_gym_Ch2.sub2:
	octave 2
	note D_, 4
	note D_, 2
	octave 1
	note A_, 1
	note A_, 1
	note A_, 1
	octave 2
	note D_, 1
	octave 1
	note A_, 2
	octave 2
	note A_, 2
	note D_, 2
	note C_, 4
	note C_, 2
	octave 1
	note G_, 1
	note G_, 1
	note G_, 1
	octave 2
	note C_, 1
	octave 1
	note G_, 2
	octave 2
	note G_, 2
	note C_, 2
	octave 1
	note B_, 2
	rest 2
	note B_, 2
	note Fs, 1
	note Fs, 1
	sound_ret

gbs_gym_Ch3:
	gbs_switch 2
	vibrato 20, 2, 3
	stereo_panning TRUE, TRUE
gbs_gym_Ch3.mainloop:
	note_type 12, 1, 4
	octave 6
	note D_, 2
	octave 4
	note D_, 1
	note D_, 1
	note D_, 1
	rest 1
	octave 5
	note A_, 1
	octave 6
	note D_, 1
	note C_, 2
	octave 4
	note C_, 1
	note C_, 1
	note C_, 1
	rest 1
	octave 5
	note A_, 1
	octave 6
	note C_, 1
	octave 5
	note B_, 2
	octave 3
	note G_, 1
	note G_, 1
	note G_, 1
	rest 1
	octave 5
	note B_, 1
	note B_, 1
	note B_, 4
	octave 6
	note Cs, 4
	octave 5
	note D_, 12
	octave 4
	note A_, 2
	octave 5
	note D_, 2
	note E_, 1
	rest 2
	note C_, 1
	note C_, 4
	note G_, 4
	note E_, 4
	note D_, 12
	octave 4
	note A_, 2
	octave 5
	note D_, 2
	note C_, 1
	rest 1
	note C_, 1
	note D_, 1
	note E_, 8
	rest 4
	note Fs, 12
	note E_, 2
	note Fs, 2
	note G_, 1
	rest 2
	note E_, 1
	note E_, 4
	octave 6
	note C_, 1
	rest 2
	octave 5
	note G_, 1
	note G_, 4
	note Fs, 12
	note E_, 2
	note Fs, 2
	note G_, 2
	note E_, 1
	note G_, 1
	octave 6
	note C_, 8
	octave 5
	note B_, 4
	volume_envelope 1, 3
	sound_call gbs_gym_Ch3.sub1
	rest 2
	note A_, 2
	octave 6
	note D_, 2
	octave 5
	note A_, 2
	octave 6
	note C_, 4
	octave 5
	note As, 4
	note A_, 4
	note G_, 4
	sound_call gbs_gym_Ch3.sub1
	note A_, 1
	rest 1
	note A_, 1
	note B_, 1
	octave 6
	note C_, 4
	note D_, 1
	rest 1
	note D_, 1
	note E_, 1
	note Fs, 8
	note E_, 4
	sound_loop 0, gbs_gym_Ch3.mainloop

gbs_gym_Ch3.sub1:
	octave 5
	note A_, 6
	octave 6
	note D_, 6
	octave 5
	note A_, 4
	octave 6
	note C_, 4
	octave 5
	note B_, 4
	note A_, 4
	note G_, 4
	note Fs, 1
	rest 1
	note Fs, 1
	note G_, 1
	note A_, 4
	sound_ret

gbs_gym_Ch4:
	gbs_switch 3
	toggle_noise 4
gbs_gym_Ch4.mainloop:
	drum_speed 12
	drum_note 3, 2
	drum_note 2, 1
	drum_note 2, 1
	drum_note 12, 4
	drum_note 3, 2
	drum_note 2, 1
	drum_note 2, 1
	drum_note 12, 4
	drum_note 3, 2
	drum_note 2, 1
	drum_note 2, 1
	drum_note 3, 2
	drum_note 2, 1
	drum_note 2, 1
	drum_note 11, 1
	drum_note 4, 1
	drum_note 4, 1
	drum_note 4, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 3, 1
	drum_note 3, 1
	drum_speed 6
gbs_gym_Ch4.loop1:
	drum_note 3, 6
	drum_note 3, 6
	drum_note 3, 4
	drum_note 3, 2
	drum_note 3, 2
	drum_note 3, 4
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 3, 6
	drum_note 3, 6
	drum_note 3, 4
	drum_note 3, 2
	drum_note 3, 2
	drum_note 3, 4
	drum_note 12, 8
	sound_loop 4, gbs_gym_Ch4.loop1
gbs_gym_Ch4.loop2:
	drum_note 4, 4
	drum_note 7, 4
	drum_note 3, 4
	drum_note 4, 2
	drum_note 3, 2
	drum_note 4, 2
	drum_note 3, 2
	drum_note 4, 4
	drum_note 3, 4
	drum_note 7, 4
	sound_loop 8, gbs_gym_Ch4.loop2
	sound_loop 0, gbs_gym_Ch4.mainloop

	.align 4
	.global gbs_gym_Header
gbs_gym_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_gym_Ch1
	.int gbs_gym_Ch2
	.int gbs_gym_Ch3
	.int gbs_gym_Ch4
