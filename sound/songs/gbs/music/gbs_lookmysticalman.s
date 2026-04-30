	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_lookmysticalman_Ch1:
	gbs_switch 0
	tempo 136
	volume 7, 7
	vibrato 10, 3, 4
	pitch_offset 1
	stereo_panning FALSE, TRUE
	note_type 12, 11, 3
	rest 8
gbs_lookmysticalman_Ch1.mainloop:
	duty_cycle 3
	note_type 6, 9, 6
	octave 3
	note Fs, 1
	rest 1
	note Fs, 1
	rest 1
	note E_, 2
	note Fs, 2
	rest 4
	note Fs, 2
	rest 9
	rest 9
	note E_, 1
	rest 1
	note E_, 1
	rest 1
	note D_, 2
	note E_, 2
	rest 4
	note E_, 2
	rest 9
	rest 9
	note E_, 1
	rest 1
	note E_, 1
	rest 1
	note Cs, 2
	note E_, 2
	rest 4
	note E_, 2
	rest 9
	rest 9
	note E_, 1
	rest 1
	note E_, 1
	rest 1
	note Cs, 2
	note E_, 2
	rest 3
	note F_, 1
	note Fs, 4
	rest 4
	note E_, 4
	rest 4
	note Cs, 4
	duty_cycle 2
	sound_call gbs_lookmysticalman_Ch1.sub1
	octave 4
	note Cs, 2
	rest 2
	octave 3
	note B_, 2
	rest 2
	note As, 2
	octave 4
	note Cs, 6
	rest 4
	octave 3
	note Fs, 4
	rest 4
	note E_, 4
	sound_call gbs_lookmysticalman_Ch1.sub1
	octave 4
	note Cs, 2
	rest 2
	note Cs, 2
	rest 2
	octave 3
	note As, 2
	note B_, 6
	note As, 4
	note Fs, 4
	volume_envelope 10, 5
	duty_cycle 0
	octave 4
	note Fs, 2
	note As, 6
	duty_cycle 2
	volume_envelope 7, 2
gbs_lookmysticalman_Ch1.loop1:
	octave 5
	note D_, 2
	octave 4
	note B_, 2
	note Fs, 2
	note D_, 2
	sound_loop 4, gbs_lookmysticalman_Ch1.loop1
	octave 5
	note D_, 2
	octave 4
	note B_, 2
	note Fs, 2
	note D_, 2
	octave 3
	note A_, 2
	note Fs, 2
	note D_, 2
	octave 2
	note A_, 2
	note B_, 2
	octave 3
	note D_, 2
	note Fs, 2
	note A_, 2
	note B_, 2
	octave 4
	note D_, 2
	note Fs, 2
	note B_, 2
gbs_lookmysticalman_Ch1.loop2:
	octave 5
	note D_, 2
	octave 4
	note Gs, 2
	note E_, 2
	octave 3
	note B_, 2
	sound_loop 4, gbs_lookmysticalman_Ch1.loop2
	octave 5
	note Cs, 2
	octave 4
	note As, 2
	note Fs, 2
	note Cs, 2
	octave 3
	note As, 2
	note Fs, 2
	note Cs, 2
	octave 2
	note As, 2
	octave 3
	note Cs, 2
	note E_, 2
	note Fs, 2
	note As, 2
	octave 4
	note Cs, 2
	note E_, 2
	note Fs, 2
	note As, 2
	sound_loop 0, gbs_lookmysticalman_Ch1.mainloop

gbs_lookmysticalman_Ch1.sub1:
	note D_, 16
	octave 4
	note D_, 2
	rest 2
	note E_, 2
	rest 2
	note Fs, 2
	note D_, 6
	octave 3
	note E_, 16
	note B_, 2
	rest 2
	octave 4
	note Cs, 2
	rest 2
	note D_, 2
	octave 3
	note B_, 6
	octave 4
	note E_, 2
	rest 2
	note E_, 2
	rest 2
	note D_, 2
	note Cs, 6
	note Cs, 2
	rest 2
	note Cs, 2
	rest 2
	octave 3
	note B_, 2
	note A_, 6
	sound_ret

gbs_lookmysticalman_Ch2:
	gbs_switch 1
	duty_cycle 3
	vibrato 10, 3, 4
	note_type 12, 11, 3
	rest 8
gbs_lookmysticalman_Ch2.mainloop:
	stereo_panning TRUE, FALSE
	note_type 6, 11, 8
	octave 3
	note B_, 1
	rest 1
	note B_, 1
	rest 1
	note A_, 2
	note B_, 2
	rest 4
	note B_, 2
	rest 6
	stereo_panning TRUE, TRUE
	note B_, 8
	note A_, 4
	stereo_panning TRUE, FALSE
	note Gs, 1
	rest 1
	note Gs, 1
	rest 1
	note Fs, 2
	note Gs, 2
	rest 4
	note Gs, 2
	rest 6
	stereo_panning TRUE, TRUE
	note Fs, 8
	note Gs, 4
	stereo_panning TRUE, FALSE
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note G_, 2
	note A_, 2
	rest 4
	note A_, 2
	rest 6
	stereo_panning TRUE, TRUE
	note A_, 8
	note G_, 4
	stereo_panning TRUE, FALSE
	note Fs, 1
	rest 1
	note Fs, 1
	rest 1
	note E_, 2
	note Fs, 2
	rest 3
	note A_, 1
	note As, 4
	rest 4
	note Fs, 4
	rest 4
	note E_, 4
	sound_call gbs_lookmysticalman_Ch2.sub1
	note Fs, 2
	rest 2
	note E_, 2
	rest 2
	note D_, 2
	note E_, 6
	sound_call gbs_lookmysticalman_Ch2.sub2
	sound_call gbs_lookmysticalman_Ch2.sub1
	note Fs, 2
	rest 2
	note Fs, 2
	rest 2
	note E_, 2
	note D_, 6
	sound_call gbs_lookmysticalman_Ch2.sub2
	note_type 12, 11, 7
	note B_, 2
	rest 2
	note B_, 2
	rest 2
	octave 4
	note D_, 2
	rest 1
	note Cs, 2
	rest 1
	octave 3
	note B_, 16
	rest 2
	note B_, 2
	rest 2
	octave 4
	note D_, 2
	rest 2
	note Cs, 2
	rest 1
	octave 3
	note B_, 2
	rest 1
	note As, 16
	rest 2
	sound_loop 0, gbs_lookmysticalman_Ch2.mainloop

gbs_lookmysticalman_Ch2.sub1:
	note B_, 2
	rest 2
	octave 4
	note D_, 2
	rest 2
	note Fs, 2
	note A_, 6
	note B_, 8
	rest 2
	note A_, 2
	note B_, 2
	octave 5
	note Cs, 2
	note D_, 2
	rest 2
	note Cs, 2
	rest 2
	note D_, 2
	note Cs, 6
	octave 4
	note B_, 12
	volume_envelope 8, 8
	note As, 1
	note A_, 1
	volume_envelope 6, 8
	note Gs, 1
	note Fs, 1
	volume_envelope 11, 8
	octave 5
	note Cs, 2
	rest 2
	note Cs, 2
	rest 2
	octave 4
	note B_, 2
	note A_, 6
	note G_, 2
	rest 2
	note G_, 2
	rest 2
	note Fs, 2
	note E_, 6
	sound_ret

gbs_lookmysticalman_Ch2.sub2:
	note Cs, 8
	volume_envelope 8, 8
	note C_, 1
	octave 3
	note B_, 1
	note As, 1
	volume_envelope 6, 8
	note Gs, 1
	note Fs, 1
	volume_envelope 4, 8
	note E_, 1
	note Cs, 1
	rest 1
	volume_envelope 11, 8
	sound_ret

gbs_lookmysticalman_Ch3:
	gbs_switch 2
	note_type 6, 1, 6
	rest 16
gbs_lookmysticalman_Ch3.mainloop:
	octave 2
	note B_, 4
	octave 3
	note A_, 2
	rest 2
	note Fs, 4
	octave 2
	note B_, 1
	rest 1
	note B_, 4
	note A_, 2
	note B_, 2
	octave 3
	note B_, 2
	octave 2
	note B_, 2
	octave 3
	note A_, 2
	octave 2
	note B_, 2
	octave 3
	note Fs, 2
	note E_, 4
	note Gs, 2
	rest 2
	note B_, 4
	note E_, 1
	rest 1
	note E_, 6
	octave 2
	note As, 2
	note B_, 6
	note Gs, 4
	note A_, 4
	octave 3
	note G_, 2
	rest 2
	note E_, 4
	octave 2
	note A_, 1
	rest 1
	note A_, 4
	note G_, 2
	note A_, 2
	octave 3
	note A_, 2
	octave 2
	note A_, 2
	octave 3
	note G_, 2
	octave 2
	note A_, 2
	octave 3
	note E_, 2
gbs_lookmysticalman_Ch3.loop1:
	octave 2
	note Fs, 4
	note As, 2
	rest 2
	octave 3
	note Cs, 4
	octave 2
	note Fs, 1
	rest 1
	note Fs, 6
	note Gs, 4
	rest 4
	note As, 4
	note B_, 4
	octave 3
	note A_, 2
	rest 2
	note Fs, 4
	octave 2
	note B_, 1
	rest 1
	note B_, 6
	octave 3
	note D_, 2
	rest 2
	note Fs, 2
	note D_, 6
	note E_, 4
	note Gs, 2
	rest 2
	note B_, 4
	note E_, 1
	rest 1
	note E_, 6
	note D_, 2
	rest 2
	octave 2
	note B_, 2
	note Gs, 6
	note A_, 4
	octave 3
	note Cs, 2
	rest 2
	note E_, 4
	octave 2
	note A_, 1
	rest 1
	note A_, 6
	octave 3
	note E_, 4
	note Cs, 2
	octave 2
	note E_, 6
	sound_loop 2, gbs_lookmysticalman_Ch3.loop1
	note Fs, 4
	note As, 2
	rest 2
	octave 3
	note Cs, 2
	note Fs, 6
	octave 2
	note Fs, 2
	rest 2
	octave 3
	note Cs, 4
	octave 2
	note As, 2
	octave 3
	note Fs, 6
	octave 2
	note B_, 4
	octave 3
	note B_, 4
	octave 2
	note B_, 4
	octave 3
	note Fs, 2
	note A_, 6
	octave 2
	note B_, 4
	octave 3
	note Fs, 4
	octave 2
	note B_, 4
	note A_, 4
	rest 2
	note As, 4
	rest 2
	note B_, 6
	rest 2
	note B_, 4
	note A_, 4
	note Fs, 4
	note E_, 4
	octave 3
	note E_, 4
	octave 2
	note E_, 4
	note Gs, 2
	octave 3
	note D_, 6
	octave 2
	note E_, 4
	note B_, 4
	octave 3
	note E_, 4
	note Fs, 4
	rest 2
	note E_, 4
	rest 2
	note Cs, 8
	octave 2
	note B_, 8
	note As, 4
	sound_loop 0, gbs_lookmysticalman_Ch3.mainloop

gbs_lookmysticalman_Ch4:
	gbs_switch 3
	toggle_noise 3
	drum_speed 12
	drum_note 4, 2
	drum_note 4, 2
	drum_note 3, 2
	drum_note 3, 1
	drum_note 3, 1
gbs_lookmysticalman_Ch4.mainloop:
gbs_lookmysticalman_Ch4.loop1:
	sound_call gbs_lookmysticalman_Ch4.sub1
	sound_call gbs_lookmysticalman_Ch4.sub2
	sound_call gbs_lookmysticalman_Ch4.sub1
	sound_call gbs_lookmysticalman_Ch4.sub3
	sound_loop 2, gbs_lookmysticalman_Ch4.loop1
	sound_call gbs_lookmysticalman_Ch4.sub1
	sound_call gbs_lookmysticalman_Ch4.sub2
	sound_call gbs_lookmysticalman_Ch4.sub1
	drum_note 3, 2
	drum_note 4, 2
	drum_note 3, 2
	drum_note 4, 1
	drum_note 3, 1
	drum_note 3, 2
	drum_note 4, 2
	drum_note 3, 2
	drum_note 3, 1
	drum_note 3, 1
gbs_lookmysticalman_Ch4.loop2:
	drum_note 3, 2
	drum_note 4, 2
	drum_note 3, 3
	drum_note 4, 1
	drum_note 4, 2
	drum_note 4, 2
	drum_note 3, 2
	drum_note 4, 2
	drum_note 3, 2
	drum_note 4, 2
	drum_note 3, 3
	drum_note 4, 1
	drum_note 4, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 3, 1
	drum_note 3, 1
	sound_loop 2, gbs_lookmysticalman_Ch4.loop2
	sound_loop 0, gbs_lookmysticalman_Ch4.mainloop

gbs_lookmysticalman_Ch4.sub1:
	drum_note 4, 4
	drum_note 3, 3
	drum_note 4, 3
	drum_note 4, 2
	drum_note 3, 4
	sound_ret

gbs_lookmysticalman_Ch4.sub2:
	drum_note 4, 4
	drum_note 3, 3
	drum_note 3, 3
	drum_note 4, 2
	drum_note 3, 4
	sound_ret

gbs_lookmysticalman_Ch4.sub3:
	drum_note 4, 4
	drum_note 3, 2
	drum_note 4, 1
	drum_note 3, 3
	drum_note 3, 2
	drum_note 4, 2
	drum_note 3, 1
	drum_note 3, 1
	sound_ret

	.align 4
	.global gbs_lookmysticalman_Header
gbs_lookmysticalman_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_lookmysticalman_Ch1
	.int gbs_lookmysticalman_Ch2
	.int gbs_lookmysticalman_Ch3
	.int gbs_lookmysticalman_Ch4
