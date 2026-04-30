	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_showmearound_Ch1:
	gbs_switch 0
	tempo 144
	volume 7, 7
	stereo_panning FALSE, TRUE
	duty_cycle 2
	note_type 12, 11, 1
	octave 4
	note B_, 2
	note A_, 2
	note Gs, 2
	note A_, 2
	note Gs, 2
	note Fs, 2
	note E_, 2
	note D_, 2
	octave 3
	note B_, 4
	note Gs, 1
	note B_, 1
	octave 4
	note D_, 1
	note E_, 1
	note Gs, 8
gbs_showmearound_Ch1.mainloop:
	rest 16
	rest 16
	rest 16
	rest 16
	sound_call gbs_showmearound_Ch2.sub3
	sound_call gbs_showmearound_Ch1.sub1
	sound_call gbs_showmearound_Ch2.sub3
	sound_call gbs_showmearound_Ch1.sub1
	sound_loop 0, gbs_showmearound_Ch1.mainloop

gbs_showmearound_Ch1.sub1:
	rest 4
	octave 3
	note Cs, 1
	rest 5
	note D_, 4
	note C_, 1
	rest 1
	rest 4
	octave 2
	note E_, 1
	rest 1
	note Gs, 1
	rest 1
	octave 4
	note E_, 1
	rest 1
	note E_, 1
	rest 1
	note E_, 1
	rest 3
	sound_ret

gbs_showmearound_Ch2:
	gbs_switch 1
	stereo_panning TRUE, TRUE
	duty_cycle 2
	note_type 12, 11, 1
	octave 5
	note E_, 2
	note D_, 2
	note Cs, 2
	note D_, 2
	note Cs, 2
	octave 4
	note B_, 2
	note A_, 2
	note Gs, 2
	note E_, 4
	note E_, 1
	note Gs, 1
	note B_, 1
	octave 5
	note D_, 1
	note E_, 8
	duty_cycle 1
gbs_showmearound_Ch2.mainloop:
	sound_call gbs_showmearound_Ch2.sub3
	sound_call gbs_showmearound_Ch2.sub3
	sound_call gbs_showmearound_Ch2.sub1
	note A_, 4
	octave 3
	note A_, 2
	octave 4
	note Cs, 2
	note E_, 4
	note D_, 2
	note Cs, 2
	octave 3
	note B_, 4
	sound_call gbs_showmearound_Ch2.sub1
	note A_, 2
	note A_, 2
	note Gs, 2
	note E_, 2
	note Fs, 2
	note Gs, 2
	note A_, 2
	note A_, 2
	note A_, 4
	sound_call gbs_showmearound_Ch2.sub2
	note A_, 4
	octave 5
	note Cs, 2
	octave 4
	note A_, 2
	note A_, 4
	note Gs, 1
	note G_, 1
	note Fs, 1
	note F_, 1
	note E_, 1
	rest 1
	note Ds, 1
	note E_, 1
	sound_call gbs_showmearound_Ch2.sub2
	note A_, 2
	octave 5
	note E_, 2
	note D_, 2
	octave 4
	note B_, 2
	note A_, 2
	note Gs, 2
	note A_, 2
	note A_, 2
	note A_, 4
	sound_loop 0, gbs_showmearound_Ch2.mainloop

gbs_showmearound_Ch2.sub1:
	octave 3
	note A_, 2
	octave 4
	note Cs, 2
	note E_, 4
	note D_, 2
	note Fs, 2
	sound_ret

gbs_showmearound_Ch2.sub2:
	octave 5
	note Cs, 2
	octave 4
	note A_, 2
	note A_, 4
	octave 5
	note Fs, 2
	octave 4
	note A_, 2
	sound_ret

gbs_showmearound_Ch2.sub3:
	rest 4
	octave 3
	note Cs, 1
	rest 5
	note D_, 4
	note C_, 1
	rest 1
	rest 2
	note Cs, 1
	rest 5
	octave 2
	note E_, 1
	rest 3
	note As, 2
	note B_, 1
	rest 1
	sound_ret

gbs_showmearound_Ch3:
	gbs_switch 2
	stereo_panning TRUE, FALSE
	vibrato 16, 2, 2
	note_type 6, 2, 5
	octave 2
	note B_, 1
	rest 3
	octave 3
	note D_, 1
	rest 3
	note E_, 1
	rest 3
	note Gs, 1
	rest 3
	note B_, 1
	rest 3
	octave 4
	note D_, 1
	rest 3
	note E_, 1
	rest 3
	note Gs, 1
	rest 3
	note D_, 2
	rest 6
	note D_, 2
	octave 3
	note B_, 2
	note Gs, 2
	note B_, 2
	note E_, 2
	rest 6
	volume_envelope 1, 4
	octave 2
	note B_, 1
	note As, 1
	note A_, 1
	note Gs, 1
	note G_, 1
	note F_, 1
	note E_, 2
	volume_envelope 1, 4
gbs_showmearound_Ch3.mainloop:
	sound_call gbs_showmearound_Ch3.sub1
	sound_call gbs_showmearound_Ch3.sub1
	sound_call gbs_showmearound_Ch3.sub1
	sound_call gbs_showmearound_Ch3.sub2
	sound_call gbs_showmearound_Ch3.sub1
	sound_call gbs_showmearound_Ch3.sub2
	sound_loop 0, gbs_showmearound_Ch3.mainloop

gbs_showmearound_Ch3.sub1:
	octave 2
	note A_, 2
	rest 6
	octave 4
	note E_, 2
	rest 2
	octave 2
	note A_, 2
	rest 2
	octave 3
	note D_, 2
	rest 2
	octave 4
	note Fs, 8
	note Ds, 2
	rest 2
	octave 2
	note A_, 2
	rest 2
	octave 4
	note E_, 2
	rest 6
	octave 2
	note A_, 2
	rest 2
	octave 4
	note D_, 2
	rest 6
	note Cs, 4
	note D_, 2
	rest 2
	sound_ret

gbs_showmearound_Ch3.sub2:
	octave 2
	note A_, 2
	rest 6
	octave 4
	note E_, 2
	rest 2
	octave 2
	note A_, 2
	rest 2
	octave 3
	note D_, 2
	rest 2
	octave 4
	note Fs, 8
	note Ds, 2
	rest 2
	octave 2
	note Gs, 2
	rest 6
	octave 4
	note D_, 2
	rest 2
	octave 3
	note B_, 2
	rest 2
	note Cs, 2
	rest 2
	note E_, 2
	rest 2
	octave 2
	note A_, 2
	rest 6
	sound_ret

gbs_showmearound_Ch4:
	gbs_switch 3
	toggle_noise 3
	drum_speed 12
	rest 16
	rest 8
	drum_note 3, 2
	drum_note 4, 2
	drum_note 7, 4
gbs_showmearound_Ch4.mainloop:
	sound_call gbs_showmearound_Ch4.sub1
	sound_call gbs_showmearound_Ch4.sub1
	sound_call gbs_showmearound_Ch4.sub1
	sound_call gbs_showmearound_Ch4.sub2
	sound_call gbs_showmearound_Ch4.sub1
	sound_call gbs_showmearound_Ch4.sub2
	sound_loop 0, gbs_showmearound_Ch4.mainloop

gbs_showmearound_Ch4.sub1:
	drum_note 4, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 8, 2
	drum_note 8, 2
	drum_note 7, 4
	drum_note 3, 2
	drum_note 4, 2
	drum_note 7, 4
	drum_note 3, 2
	drum_note 8, 2
	drum_note 8, 2
	drum_note 3, 2
	drum_note 4, 2
	sound_ret

gbs_showmearound_Ch4.sub2:
	drum_note 4, 2
	drum_note 7, 2
	drum_note 3, 2
	drum_note 8, 2
	drum_note 8, 2
	drum_note 7, 4
	drum_note 3, 2
	drum_note 4, 2
	drum_note 7, 4
	drum_note 3, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 7, 2
	sound_ret

	.align 4
	.global gbs_showmearound_Header
gbs_showmearound_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_showmearound_Ch1
	.int gbs_showmearound_Ch2
	.int gbs_showmearound_Ch3
	.int gbs_showmearound_Ch4
