	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_ssaqua_Ch1:
	gbs_switch 0
	tempo 117
	volume 7, 7
	stereo_panning FALSE, TRUE
	pitch_offset 1
	vibrato 18, 3, 3
	duty_cycle 2
	note_type 6, 9, 7
	octave 2
	note G_, 1
	rest 1
	note G_, 1
	rest 1
gbs_ssaqua_Ch1.mainloop:
	octave 2
	note G_, 16
	rest 8
	note G_, 2
	rest 2
	note_type 12, 9, 7
	note G_, 2
	note G_, 10
	rest 4
	note_type 6, 9, 7
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note G_, 16
	rest 8
	note G_, 2
	rest 2
	note_type 12, 9, 7
	note G_, 2
	note G_, 8
	rest 8
	duty_cycle 1
	volume_envelope 6, 1
	sound_call gbs_ssaqua_Ch2.sub4
	octave 5
	note G_, 1
	octave 4
	note B_, 1
	note A_, 1
	note G_, 1
	octave 5
	note G_, 1
	octave 4
	note B_, 1
	note A_, 1
	note G_, 1
	octave 5
	note G_, 1
	octave 4
	note B_, 1
	note A_, 1
	note G_, 1
	octave 5
	note G_, 1
	octave 4
	note B_, 1
	note A_, 1
	note G_, 1
	sound_call gbs_ssaqua_Ch2.sub4
	sound_call gbs_ssaqua_Ch2.sub5
	rest 16
	rest 16
	rest 16
	volume_envelope 9, 7
	rest 14
	note_type 6, 9, 7
	note D_, 1
	rest 1
	octave 3
	note As, 1
	rest 1
	note_type 12, 9, 7
	rest 16
	rest 16
	volume_envelope 9, 5
	rest 2
	octave 4
	note C_, 1
	note E_, 1
	note G_, 1
	rest 1
	note E_, 1
	note C_, 1
	octave 3
	note E_, 1
	note C_, 1
	note E_, 1
	note G_, 1
	octave 4
	note C_, 1
	note E_, 1
	note G_, 1
	octave 5
	note C_, 1
	octave 4
	note E_, 6
	note D_, 2
	note C_, 1
	note D_, 1
	note Fs, 1
	note A_, 1
	octave 5
	note C_, 1
	note D_, 1
	octave 4
	note G_, 1
	note Fs, 1
	duty_cycle 2
	volume_envelope 9, 7
	note G_, 8
	note Fs, 8
	note E_, 8
	note D_, 8
	octave 3
	note B_, 8
	note As, 2
	rest 2
	note B_, 1
	rest 1
	octave 4
	note Fs, 2
	volume_envelope 7, 5
	octave 5
	note A_, 4
	note Fs, 4
	note D_, 4
	octave 4
	note As, 2
	note_type 6, 9, 7
	note D_, 1
	rest 1
	octave 3
	note As, 1
	rest 1
	volume_envelope 9, 7
	note G_, 16
	note A_, 16
	note B_, 4
	rest 4
	note B_, 4
	rest 4
	octave 4
	note E_, 8
	note G_, 8
	note Fs, 1
	vibrato 0, 0, 0
	volume_envelope 8, 8
	note G_, 10
	vibrato 2, 2, 3
	volume_envelope 8, 7
	note G_, 9
	vibrato 8, 3, 3
	note C_, 4
	note E_, 4
	note C_, 4
	note D_, 12
	note Fs, 12
	rest 8
	octave 2
	note B_, 2
	octave 3
	note D_, 2
	note Fs, 2
	note A_, 2
	note D_, 2
	note Fs, 2
	note A_, 2
	octave 4
	note D_, 2
	note Fs, 2
	note_type 12, 9, 7
	rest 7
	rest 16
	rest 16
	note G_, 8
	note Fs, 1
	note D_, 1
	octave 3
	note A_, 1
	octave 4
	note D_, 1
	octave 3
	note A_, 1
	note Fs, 1
	note D_, 1
	octave 2
	note A_, 1
	note B_, 1
	octave 3
	note D_, 1
	note Fs, 1
	note A_, 1
	note D_, 1
	note Fs, 1
	note A_, 1
	octave 4
	note D_, 1
	note Fs, 1
	rest 7
	rest 16
	rest 2
	note E_, 2
	note G_, 1
	rest 1
	note E_, 1
	note_type 6, 9, 7
	rest 1
	note C_, 1
	note Cs, 4
	octave 3
	note B_, 2
	rest 2
	note A_, 3
	rest 1
	note G_, 2
	rest 2
	note Fs, 2
	note D_, 2
	octave 2
	note A_, 2
	octave 3
	note D_, 2
	note A_, 2
	note Fs, 2
	note D_, 2
	note A_, 2
	octave 4
	note D_, 2
	octave 3
	note A_, 2
	note Fs, 2
	note A_, 2
	octave 4
	note C_, 2
	note D_, 2
	note Fs, 2
	note A_, 2
	sound_loop 0, gbs_ssaqua_Ch1.mainloop

gbs_ssaqua_Ch2:
	gbs_switch 1
	stereo_panning TRUE, FALSE
	duty_cycle 2
	vibrato 8, 3, 3
	note_type 12, 11, 7
	rest 2
gbs_ssaqua_Ch2.mainloop:
	note_type 12, 11, 7
	duty_cycle 1
	volume_envelope 6, 1
	sound_call gbs_ssaqua_Ch2.sub4
	sound_call gbs_ssaqua_Ch2.sub5
	duty_cycle 2
	volume_envelope 13, 7
	sound_call gbs_ssaqua_Ch2.sub3
	note B_, 1
	rest 1
	note G_, 1
	rest 3
	octave 3
	note G_, 6
	note G_, 1
	note B_, 1
	octave 4
	note Cs, 1
	note E_, 1
	transpose 0, 12
	sound_call gbs_ssaqua_Ch2.sub3
	transpose 0, 0
	octave 3
	note B_, 1
	rest 1
	note G_, 1
	rest 3
	octave 4
	note G_, 6
	rest 2
	duty_cycle 3
	volume_envelope 11, 7
	octave 3
	note B_, 1
	octave 4
	note C_, 1
	sound_call gbs_ssaqua_Ch2.sub1
	note G_, 4
	rest 4
	note G_, 8
	note A_, 8
	note B_, 8
	note_type 12, 11, 7
	octave 5
	note C_, 10
	note D_, 2
	note C_, 2
	octave 4
	note G_, 2
	note B_, 6
	note A_, 6
	rest 2
	octave 3
	note B_, 1
	octave 4
	note C_, 1
	sound_call gbs_ssaqua_Ch2.sub1
	note G_, 4
	rest 4
	note G_, 8
	note A_, 8
	note B_, 8
	octave 5
	note Ds, 1
	vibrato 0, 0, 0
	volume_envelope 9, 8
	note E_, 10
	vibrato 4, 2, 3
	volume_envelope 9, 7
	note E_, 9
	vibrato 8, 2, 3
	note D_, 4
	note C_, 4
	octave 4
	note G_, 4
	note B_, 12
	note A_, 12
	rest 4
	duty_cycle 0
	note B_, 2
	note A_, 2
	sound_call gbs_ssaqua_Ch2.sub2
	note_type 6, 11, 7
	note Gs, 1
	note A_, 11
	note G_, 2
	note Fs, 2
	note G_, 12
	rest 4
	rest 4
	note E_, 2
	rest 2
	note E_, 2
	rest 2
	note G_, 2
	rest 2
	note A_, 2
	rest 2
	note E_, 2
	rest 2
	note Fs, 2
	rest 2
	note G_, 2
	rest 2
	note A_, 16
	note As, 12
	note B_, 2
	note A_, 2
	sound_call gbs_ssaqua_Ch2.sub2
	note_type 6, 11, 7
	note Gs, 1
	note A_, 11
	note B_, 4
	note G_, 12
	rest 4
	rest 4
	octave 5
	note C_, 4
	note D_, 2
	rest 2
	note C_, 2
	rest 1
	octave 4
	note As, 1
	note B_, 4
	note A_, 2
	rest 2
	note G_, 4
	note E_, 2
	rest 2
	note Fs, 8
	note G_, 8
	note A_, 8
	rest 8
	sound_loop 0, gbs_ssaqua_Ch2.mainloop

gbs_ssaqua_Ch2.sub1:
	note D_, 6
	octave 3
	note B_, 1
	octave 4
	note C_, 1
	note D_, 2
	octave 3
	note B_, 1
	octave 4
	note C_, 1
	note D_, 2
	octave 3
	note B_, 1
	octave 4
	note C_, 1
	note D_, 2
	rest 2
	note G_, 2
	rest 2
	note A_, 2
	rest 2
	note As, 2
	rest 2
	note B_, 6
	note Fs, 6
	rest 4
	duty_cycle 1
	note_type 6, 11, 7
	octave 3
	note A_, 1
	rest 1
	octave 4
	note D_, 1
	rest 1
	note Fs, 1
	rest 1
	note A_, 1
	rest 1
	note D_, 1
	rest 1
	note Fs, 1
	rest 1
	note A_, 1
	rest 1
	octave 5
	note D_, 1
	rest 1
	note Fs, 1
	rest 1
	note D_, 1
	rest 1
	octave 4
	note As, 1
	rest 1
	note Fs, 1
	rest 1
	note As, 1
	rest 1
	note Fs, 1
	rest 1
	duty_cycle 3
	note E_, 2
	note Fs, 2
	note G_, 12
	note E_, 2
	note Fs, 2
	note G_, 4
	note E_, 2
	note Fs, 2
	note G_, 4
	note E_, 2
	note Fs, 2
	sound_ret

gbs_ssaqua_Ch2.sub2:
	note_type 12, 11, 7
	note B_, 10
	note Fs, 1
	rest 1
	note B_, 1
	rest 1
	note Fs, 1
	rest 1
	sound_ret

gbs_ssaqua_Ch2.sub3:
	octave 3
	note D_, 10
	note E_, 1
	rest 3
	note D_, 1
	rest 1
	note Cs, 12
	octave 2
	note A_, 1
	rest 1
	note B_, 1
	rest 1
	octave 3
	note C_, 8
	rest 2
	octave 2
	note B_, 1
	rest 3
	note A_, 1
	rest 1
	sound_ret

gbs_ssaqua_Ch2.sub4:
	octave 5
	note G_, 1
	note D_, 1
	octave 4
	note B_, 1
	note G_, 1
	octave 5
	note G_, 1
	note D_, 1
	octave 4
	note B_, 1
	note G_, 1
	octave 5
	note G_, 1
	note D_, 1
	octave 4
	note B_, 1
	note G_, 1
	octave 5
	note G_, 1
	note D_, 1
	octave 4
	note B_, 1
	note G_, 1
	octave 5
	note G_, 1
	note Cs, 1
	octave 4
	note As, 1
	note G_, 1
	octave 5
	note G_, 1
	note Cs, 1
	octave 4
	note As, 1
	note G_, 1
	octave 5
	note G_, 1
	note Cs, 1
	octave 4
	note As, 1
	note G_, 1
	octave 5
	note G_, 1
	note Cs, 1
	octave 4
	note As, 1
	note G_, 1
	octave 5
	note G_, 1
	note C_, 1
	octave 4
	note A_, 1
	note G_, 1
	octave 5
	note G_, 1
	note C_, 1
	octave 4
	note A_, 1
	note G_, 1
	octave 5
	note G_, 1
	note C_, 1
	octave 4
	note A_, 1
	note G_, 1
	octave 5
	note G_, 1
	note C_, 1
	octave 4
	note A_, 1
	note G_, 1
	sound_ret

gbs_ssaqua_Ch2.sub5:
	octave 5
	note G_, 1
	octave 4
	note B_, 1
	note A_, 1
	note G_, 1
	octave 5
	note G_, 1
	octave 4
	note B_, 1
	note A_, 1
	note G_, 1
	octave 5
	note G_, 1
	note D_, 1
	octave 4
	note B_, 1
	note G_, 1
	note B_, 1
	note G_, 1
	note Cs, 1
	octave 3
	note G_, 1
	sound_ret

gbs_ssaqua_Ch3:
	gbs_switch 2
	stereo_panning TRUE, TRUE
	vibrato 8, 3, 4
	note_type 6, 1, 5
	octave 2
	note G_, 1
	rest 1
	note G_, 1
	rest 1
gbs_ssaqua_Ch3.mainloop:
	note G_, 16
	rest 8
	note G_, 2
	rest 2
	note_type 12, 1, 5
	note G_, 2
	note G_, 10
	rest 4
	note_type 6, 1, 5
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note G_, 16
	rest 8
	note G_, 2
	rest 2
	note_type 12, 1, 5
	note G_, 2
	note G_, 8
	note B_, 1
	octave 3
	note Cs, 1
	note D_, 1
	note G_, 1
	note D_, 1
	note G_, 1
	note B_, 1
	octave 4
	note E_, 1
	sound_call gbs_ssaqua_Ch3.sub1
	sound_call gbs_ssaqua_Ch3.sub1
gbs_ssaqua_Ch3.loop1:
	note G_, 2
	rest 2
	octave 3
	note G_, 1
	rest 3
	octave 2
	note G_, 2
	rest 2
	octave 3
	note G_, 1
	rest 3
	octave 2
	note G_, 2
	rest 2
	octave 3
	note G_, 1
	rest 3
	octave 2
	note G_, 2
	rest 2
	octave 3
	note G_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	sound_loop 4, gbs_ssaqua_Ch3.loop1
	sound_call gbs_ssaqua_Ch3.sub2
	sound_call gbs_ssaqua_Ch3.sub2
	sound_call gbs_ssaqua_Ch3.sub3
	octave 3
	note E_, 2
	rest 2
	octave 4
	note E_, 1
	rest 3
	octave 3
	note Ds, 2
	rest 2
	octave 4
	note Ds, 1
	rest 3
	octave 3
	note D_, 2
	rest 2
	octave 4
	note D_, 1
	rest 3
	octave 3
	note Ds, 2
	rest 2
	octave 4
	note Ds, 1
	rest 3
	octave 2
	note A_, 2
	rest 2
	octave 4
	note C_, 1
	rest 3
	octave 2
	note A_, 2
	rest 2
	octave 4
	note C_, 1
	rest 3
	octave 2
	note A_, 2
	rest 2
	octave 4
	note Cs, 1
	rest 3
	octave 2
	note A_, 2
	rest 2
	octave 4
	note Cs, 1
	rest 3
	octave 3
	note D_, 2
	rest 2
	octave 4
	note G_, 1
	rest 3
	octave 3
	note D_, 2
	rest 2
	octave 4
	note G_, 1
	rest 3
	octave 3
	note D_, 2
	rest 2
	octave 4
	note Fs, 1
	rest 3
	octave 3
	note D_, 2
	rest 2
	octave 4
	note Fs, 1
	rest 3
	sound_call gbs_ssaqua_Ch3.sub3
	octave 3
	note E_, 2
	rest 2
	octave 4
	note E_, 1
	rest 3
	octave 3
	note E_, 2
	rest 2
	octave 4
	note Ds, 1
	rest 3
	octave 2
	note A_, 2
	rest 2
	octave 4
	note Cs, 1
	rest 3
	octave 2
	note A_, 2
	rest 2
	octave 4
	note Cs, 1
	rest 3
	octave 3
	note C_, 2
	rest 2
	octave 4
	note G_, 1
	rest 3
	octave 3
	note C_, 2
	rest 2
	octave 4
	note G_, 1
	rest 3
	octave 3
	note Cs, 2
	rest 2
	octave 4
	note G_, 1
	rest 3
	octave 3
	note Cs, 2
	rest 2
	octave 4
	note G_, 1
	rest 3
	octave 3
	note D_, 2
	rest 2
	octave 4
	note G_, 1
	rest 3
	octave 3
	note D_, 2
	rest 2
	octave 4
	note G_, 1
	rest 3
	octave 3
	note D_, 2
	rest 2
	octave 4
	note Fs, 1
	rest 3
	octave 3
	note D_, 2
	rest 2
	octave 2
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	sound_loop 0, gbs_ssaqua_Ch3.mainloop

gbs_ssaqua_Ch3.sub1:
	note_type 6, 1, 5
	octave 2
	note G_, 2
	rest 6
	note G_, 2
	rest 6
	note G_, 2
	rest 2
	octave 3
	note G_, 2
	rest 2
	octave 2
	note G_, 2
	rest 4
	note G_, 1
	rest 1
	note G_, 2
	rest 6
	note G_, 2
	rest 2
	octave 3
	note G_, 1
	rest 3
	octave 2
	note G_, 2
	rest 2
	octave 3
	note G_, 1
	rest 3
	octave 2
	note G_, 2
	rest 4
	note G_, 1
	rest 1
	sound_ret

gbs_ssaqua_Ch3.sub2:
	octave 2
	note G_, 2
	rest 2
	octave 4
	note D_, 1
	rest 3
	octave 2
	note G_, 2
	rest 2
	octave 4
	note D_, 1
	rest 3
	octave 2
	note G_, 2
	rest 2
	octave 4
	note E_, 1
	rest 3
	octave 2
	note G_, 2
	rest 2
	octave 4
	note E_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	note G_, 2
	rest 2
	octave 4
	note Fs, 1
	rest 3
	octave 2
	note G_, 2
	rest 2
	octave 4
	note Fs, 1
	rest 3
	octave 2
	note G_, 2
	rest 2
	octave 4
	note G_, 4
	note Fs, 4
	note E_, 2
	rest 2
	octave 2
	note B_, 2
	rest 2
	octave 4
	note Fs, 1
	rest 3
	octave 2
	note B_, 2
	rest 2
	octave 4
	note Fs, 1
	rest 3
	octave 2
	note As, 2
	rest 2
	octave 3
	note As, 1
	rest 3
	octave 2
	note As, 2
	rest 2
	octave 3
	note As, 1
	rest 3
	octave 2
	note A_, 2
	rest 2
	octave 3
	note A_, 1
	rest 3
	octave 2
	note A_, 2
	rest 2
	octave 3
	note A_, 1
	rest 3
	octave 2
	note As, 2
	rest 2
	octave 3
	note As, 1
	rest 3
	octave 2
	note As, 2
	rest 2
	octave 3
	note As, 1
	rest 1
	note Ds, 1
	rest 1
	note E_, 2
	rest 2
	octave 4
	note E_, 1
	rest 3
	octave 3
	note E_, 2
	rest 2
	octave 4
	note E_, 1
	rest 3
	octave 3
	note Ds, 2
	rest 2
	octave 4
	note Ds, 1
	rest 3
	octave 3
	note Ds, 2
	rest 2
	octave 4
	note Ds, 1
	rest 1
	octave 3
	note Cs, 1
	rest 1
	note D_, 2
	rest 2
	octave 4
	note D_, 1
	rest 3
	octave 3
	note D_, 2
	rest 2
	octave 4
	note D_, 1
	rest 3
	octave 3
	note Cs, 2
	rest 2
	octave 4
	note B_, 4
	note G_, 4
	note E_, 2
	rest 2
	octave 3
	note C_, 2
	rest 2
	octave 4
	note G_, 1
	rest 3
	octave 3
	note C_, 2
	rest 2
	octave 4
	note G_, 1
	rest 3
	octave 2
	note A_, 2
	rest 2
	octave 4
	note E_, 1
	rest 3
	octave 2
	note A_, 2
	rest 2
	octave 4
	note E_, 1
	rest 3
	octave 3
	note D_, 2
	rest 2
	octave 4
	note G_, 1
	rest 3
	octave 3
	note D_, 2
	rest 2
	octave 4
	note G_, 1
	rest 3
	octave 3
	note D_, 2
	rest 2
	octave 4
	note Fs, 1
	rest 3
	octave 3
	note D_, 2
	rest 2
	octave 4
	note Fs, 1
	rest 3
	sound_ret

gbs_ssaqua_Ch3.sub3:
	octave 2
	note B_, 2
	rest 2
	octave 4
	note Fs, 1
	rest 3
	octave 2
	note B_, 2
	rest 2
	octave 4
	note Fs, 1
	rest 3
	octave 2
	note B_, 2
	rest 2
	octave 4
	note Ds, 1
	rest 3
	octave 2
	note B_, 2
	rest 2
	octave 4
	note Ds, 1
	rest 3
	sound_ret

gbs_ssaqua_Ch4:
	gbs_switch 3
	toggle_noise 3
	drum_speed 12
	rest 2
gbs_ssaqua_Ch4.mainloop:
gbs_ssaqua_Ch4.loop1:
	drum_note 9, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 9, 1
	drum_note 8, 1
	sound_loop 12, gbs_ssaqua_Ch4.loop1
	sound_call gbs_ssaqua_Ch4.sub1
	sound_call gbs_ssaqua_Ch4.sub1
	sound_call gbs_ssaqua_Ch4.sub1
	sound_call gbs_ssaqua_Ch4.sub2
	sound_call gbs_ssaqua_Ch4.sub1
	sound_call gbs_ssaqua_Ch4.sub1
	sound_call gbs_ssaqua_Ch4.sub1
	sound_call gbs_ssaqua_Ch4.sub2
	sound_call gbs_ssaqua_Ch4.sub1
	sound_call gbs_ssaqua_Ch4.sub1
	sound_call gbs_ssaqua_Ch4.sub1
	sound_call gbs_ssaqua_Ch4.sub2
	sound_call gbs_ssaqua_Ch4.sub1
	sound_call gbs_ssaqua_Ch4.sub1
	sound_call gbs_ssaqua_Ch4.sub1
	sound_call gbs_ssaqua_Ch4.sub3
	sound_call gbs_ssaqua_Ch4.sub1
	sound_call gbs_ssaqua_Ch4.sub1
	sound_call gbs_ssaqua_Ch4.sub1
	sound_call gbs_ssaqua_Ch4.sub2
	sound_call gbs_ssaqua_Ch4.sub1
	sound_call gbs_ssaqua_Ch4.sub1
	sound_call gbs_ssaqua_Ch4.sub1
	sound_call gbs_ssaqua_Ch4.sub3
	sound_loop 0, gbs_ssaqua_Ch4.mainloop

gbs_ssaqua_Ch4.sub1:
	drum_note 11, 2
	drum_note 8, 1
	drum_note 8, 1
	drum_note 3, 2
	drum_note 8, 1
	drum_note 8, 1
	drum_note 11, 2
	drum_note 8, 1
	drum_note 8, 1
	drum_note 3, 2
	drum_note 8, 1
	drum_note 8, 1
	sound_ret

gbs_ssaqua_Ch4.sub2:
	drum_note 11, 2
	drum_note 8, 1
	drum_note 8, 1
	drum_note 3, 2
	drum_note 8, 1
	drum_note 8, 1
	drum_note 11, 2
	drum_note 8, 1
	drum_note 8, 1
	drum_note 3, 2
	drum_note 7, 2
	sound_ret

gbs_ssaqua_Ch4.sub3:
	drum_note 11, 2
	drum_note 8, 1
	drum_note 8, 1
	drum_note 3, 2
	drum_note 8, 1
	drum_note 8, 1
	drum_note 3, 1
	drum_note 3, 1
	drum_note 3, 2
	drum_note 3, 2
	drum_note 1, 2
	sound_ret

	.align 4
	.global gbs_ssaqua_Header
gbs_ssaqua_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_ssaqua_Ch1
	.int gbs_ssaqua_Ch2
	.int gbs_ssaqua_Ch3
	.int gbs_ssaqua_Ch4
