	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_mobileadapter_Ch1:
	gbs_switch 0
	tempo 132
	volume 7, 7
	pitch_offset 1
	stereo_panning FALSE, TRUE
	duty_cycle 2
	note_type 12, 8, 4
	rest 2
	rest 6
	octave 3
	note G_, 1
	octave 4
	note D_, 1
	note E_, 1
	rest 1
	note D_, 1
	rest 1
	note Cs, 4
gbs_mobileadapter_Ch1.mainloop:
	sound_call gbs_mobileadapter_Ch1.sub1
	note D_, 1
	note Cs, 1
	note D_, 2
	octave 3
	note A_, 1
	note G_, 1
	note A_, 2
	note Fs, 1
	note E_, 1
	note Fs, 2
	note D_, 1
	note Cs, 1
	note D_, 2
	sound_call gbs_mobileadapter_Ch1.sub1
	note D_, 1
	note Cs, 1
	octave 3
	note B_, 1
	octave 4
	note D_, 1
	note Fs, 1
	note E_, 1
	note D_, 1
	note Cs, 1
	volume_envelope 9, 4
	note D_, 2
	octave 3
	note A_, 2
	octave 4
	note D_, 4
	octave 5
	note Cs, 1
	rest 1
	note Cs, 1
	rest 1
	note Cs, 1
	rest 1
	octave 4
	note Cs, 8
	volume_envelope 9, 2
	note Fs, 1
	note G_, 1
	note A_, 2
	note Gs, 2
	note A_, 2
	volume_envelope 9, 4
	note E_, 3
	octave 3
	note A_, 3
	note E_, 4
	octave 4
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 3
	note B_, 8
	volume_envelope 9, 2
	octave 4
	note B_, 1
	octave 5
	note C_, 1
	note Cs, 2
	octave 4
	note B_, 2
	note A_, 2
	octave 5
	note Cs, 3
	volume_envelope 9, 4
	octave 4
	note Cs, 3
	octave 3
	note A_, 4
	octave 4
	note Fs, 1
	rest 1
	note Fs, 1
	rest 1
	note Fs, 1
	rest 1
	octave 3
	note Fs, 10
	octave 4
	note D_, 1
	rest 1
	note D_, 1
	rest 1
	note D_, 1
	rest 1
	octave 3
	note D_, 10
	octave 4
	note A_, 8
	volume_envelope 10, 1
	octave 3
	note Cs, 1
	note D_, 1
	note E_, 1
	note Fs, 1
	note G_, 1
	note A_, 1
	note B_, 1
	octave 4
	note Cs, 1
	note D_, 1
	note Cs, 1
	note D_, 2
	octave 3
	note A_, 1
	note G_, 1
	note A_, 2
	volume_envelope 9, 4
	note Fs, 2
	octave 2
	note A_, 2
	octave 3
	note D_, 4
	volume_envelope 7, 7
	sound_call gbs_mobileadapter_Ch3.sub5
	sound_loop 0, gbs_mobileadapter_Ch1.mainloop

gbs_mobileadapter_Ch1.sub1:
	volume_envelope 9, 4
	octave 4
	note Fs, 1
	rest 1
	note Fs, 1
	rest 1
	note Fs, 2
	octave 3
	note Fs, 10
	octave 4
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note G_, 2
	octave 3
	note G_, 8
	volume_envelope 10, 1
	note B_, 1
	octave 4
	note D_, 1
	note E_, 1
	note D_, 1
	note Cs, 1
	note E_, 1
	note D_, 1
	note Cs, 1
	octave 3
	note B_, 1
	note A_, 1
	note E_, 1
	note Fs, 1
	note G_, 1
	note Fs, 1
	note E_, 1
	note A_, 1
	note B_, 1
	octave 4
	note Cs, 1
	sound_ret

gbs_mobileadapter_Ch2:
	gbs_switch 1
	note_type 12, 12, 1
	vibrato 16, 2, 3
	duty_cycle 2
	octave 3
	note G_, 1
	note B_, 1
	octave 4
	note D_, 1
	note Cs, 1
	note D_, 2
	octave 3
	note B_, 1
	note As, 1
	note B_, 2
	octave 4
	note Cs, 2
	octave 3
	note B_, 2
	note A_, 2
	volume_envelope 11, 4
	octave 4
	note D_, 1
	note Fs, 1
gbs_mobileadapter_Ch2.mainloop:
	sound_call gbs_mobileadapter_Ch2.sub1
	note A_, 4
	note G_, 4
	note A_, 4
	note E_, 4
	note Fs, 12
	rest 2
	note D_, 1
	note Fs, 1
	sound_call gbs_mobileadapter_Ch2.sub1
	octave 5
	note Cs, 4
	octave 4
	note A_, 4
	octave 5
	note Fs, 4
	note E_, 4
	note D_, 12
	rest 2
	note Cs, 1
	note D_, 1
	note E_, 1
	rest 1
	note E_, 1
	rest 1
	note E_, 1
	rest 1
	note G_, 4
	note Fs, 2
	note E_, 2
	note D_, 2
	note Cs, 9
	volume_envelope 10, 2
	octave 3
	note E_, 3
	note Cs, 2
	volume_envelope 11, 4
	octave 5
	note D_, 1
	note Cs, 1
	octave 4
	note B_, 1
	rest 1
	note B_, 1
	rest 1
	note B_, 1
	rest 1
	octave 5
	note Cs, 4
	note D_, 2
	note E_, 2
	note Fs, 2
	note E_, 9
	volume_envelope 10, 2
	octave 3
	note A_, 3
	note E_, 2
	volume_envelope 11, 4
	octave 5
	note Fs, 1
	note G_, 1
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note G_, 4
	note Fs, 2
	note E_, 2
	note D_, 1
	note Cs, 1
	octave 4
	note B_, 1
	rest 1
	note B_, 1
	rest 1
	note B_, 1
	rest 1
	octave 5
	note G_, 4
	note Fs, 2
	note D_, 2
	octave 4
	note As, 1
	note B_, 1
	octave 5
	note Cs, 12
	note E_, 4
	note D_, 16
	duty_cycle 1
	volume_envelope 7, 1
	sound_call gbs_mobileadapter_Ch2.sub2
	octave 4
	note E_, 1
	note A_, 1
	octave 5
	note Cs, 1
	note E_, 1
	sound_call gbs_mobileadapter_Ch2.sub2
	rest 2
	duty_cycle 2
	volume_envelope 11, 4
	octave 4
	note D_, 1
	note Fs, 1
	sound_loop 0, gbs_mobileadapter_Ch2.mainloop

gbs_mobileadapter_Ch2.sub1:
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note A_, 2
	octave 5
	note D_, 4
	note Cs, 2
	octave 4
	note B_, 2
	note G_, 1
	note A_, 1
	note B_, 1
	rest 1
	note B_, 1
	rest 1
	note B_, 2
	octave 5
	note E_, 4
	note D_, 2
	note Cs, 2
	octave 4
	note B_, 2
	sound_ret

gbs_mobileadapter_Ch2.sub2:
	octave 5
	note Fs, 1
	note D_, 1
	octave 4
	note A_, 1
	note Fs, 1
	octave 5
	note Fs, 1
	note D_, 1
	octave 4
	note A_, 1
	note Fs, 1
	octave 5
	note Fs, 1
	note D_, 1
	octave 4
	note As, 1
	note Fs, 1
	octave 5
	note Fs, 1
	note D_, 1
	octave 4
	note As, 1
	note Fs, 1
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
	note Cs, 4
	sound_ret

gbs_mobileadapter_Ch3:
	gbs_switch 2
	note_type 12, 1, 4
	rest 2
	octave 3
	note G_, 1
	rest 1
	note B_, 1
	rest 1
	note G_, 1
	rest 1
	note B_, 1
	note G_, 1
	note A_, 1
	rest 1
	note E_, 1
	rest 1
	note A_, 4
gbs_mobileadapter_Ch3.mainloop:
	sound_call gbs_mobileadapter_Ch3.sub1
	sound_call gbs_mobileadapter_Ch3.sub2
	sound_call gbs_mobileadapter_Ch3.sub3
	note D_, 1
	rest 1
	octave 2
	note A_, 1
	rest 1
	note B_, 1
	rest 1
	octave 3
	note Cs, 1
	rest 1
	sound_call gbs_mobileadapter_Ch3.sub1
	sound_call gbs_mobileadapter_Ch3.sub2
	sound_call gbs_mobileadapter_Ch3.sub3
	note D_, 2
	octave 2
	note A_, 2
	octave 3
	note D_, 4
	sound_call gbs_mobileadapter_Ch3.sub2
	sound_call gbs_mobileadapter_Ch3.sub4
	note B_, 1
	rest 1
	octave 3
	note G_, 1
	rest 1
	octave 2
	note B_, 1
	rest 1
	octave 3
	note D_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	octave 3
	note D_, 1
	rest 1
	octave 2
	note G_, 1
	rest 1
	note B_, 1
	rest 1
	sound_call gbs_mobileadapter_Ch3.sub4
	octave 3
	note D_, 1
	rest 1
	note A_, 1
	rest 1
	note D_, 1
	rest 1
	note A_, 1
	rest 1
	note Cs, 1
	rest 1
	note A_, 1
	rest 1
	note Cs, 1
	rest 1
	note A_, 1
	rest 1
	octave 2
	note B_, 1
	rest 1
	octave 3
	note G_, 1
	rest 1
	octave 2
	note B_, 1
	rest 1
	octave 3
	note G_, 1
	rest 1
	octave 2
	note As, 1
	rest 1
	octave 3
	note G_, 1
	rest 1
	octave 2
	note As, 1
	rest 1
	octave 3
	note G_, 1
	rest 1
	sound_call gbs_mobileadapter_Ch3.sub2
	note D_, 1
	rest 1
	note A_, 1
	rest 1
	note D_, 1
	rest 1
	note A_, 1
	rest 1
	note Fs, 2
	octave 2
	note A_, 2
	octave 3
	note D_, 4
	sound_call gbs_mobileadapter_Ch3.sub5
	sound_loop 0, gbs_mobileadapter_Ch3.mainloop

gbs_mobileadapter_Ch3.sub1:
gbs_mobileadapter_Ch3.sub1loop1:
	octave 3
	note D_, 1
	rest 1
	note A_, 1
	rest 1
	sound_loop 4, gbs_mobileadapter_Ch3.sub1loop1
gbs_mobileadapter_Ch3.sub1loop2:
	octave 2
	note G_, 1
	rest 1
	octave 3
	note D_, 1
	rest 1
	sound_loop 4, gbs_mobileadapter_Ch3.sub1loop2
	sound_ret

gbs_mobileadapter_Ch3.sub2:
gbs_mobileadapter_Ch3.sub2loop1:
	octave 2
	note A_, 1
	rest 1
	octave 3
	note E_, 1
	rest 1
	sound_loop 4, gbs_mobileadapter_Ch3.sub2loop1
	sound_ret

gbs_mobileadapter_Ch3.sub3:
	note D_, 1
	rest 1
	note A_, 1
	rest 1
	note D_, 1
	rest 1
	note A_, 1
	rest 1
	sound_ret

gbs_mobileadapter_Ch3.sub4:
	octave 2
	note A_, 1
	rest 1
	octave 3
	note Cs, 1
	rest 1
	note E_, 1
	rest 1
	note Cs, 1
	rest 1
	octave 2
	note A_, 1
	octave 3
	note E_, 2
	rest 1
	octave 2
	note A_, 4
	sound_ret

gbs_mobileadapter_Ch3.sub5:
gbs_mobileadapter_Ch3.sub5loop1:
	octave 2
	note A_, 1
	rest 1
	octave 3
	note D_, 2
	octave 2
	note A_, 1
	octave 3
	note D_, 3
	octave 2
	note As, 1
	rest 1
	octave 3
	note D_, 2
	octave 2
	note As, 1
	octave 3
	note D_, 3
	octave 2
	note B_, 1
	rest 1
	octave 3
	note D_, 2
	octave 2
	note B_, 1
	octave 3
	note D_, 3
	octave 2
	note A_, 2
	rest 6
	sound_loop 2, gbs_mobileadapter_Ch3.sub5loop1
	sound_ret

gbs_mobileadapter_Ch4:
	gbs_switch 3
	toggle_noise 3
	stereo_panning TRUE, FALSE
	drum_speed 12
	rest 2
	rest 10
	drum_note 3, 2
	drum_note 3, 2
	drum_note 3, 1
	drum_note 3, 1
gbs_mobileadapter_Ch4.mainloop:
	sound_call gbs_mobileadapter_Ch4.sub1
	sound_call gbs_mobileadapter_Ch4.sub1
gbs_mobileadapter_Ch4.loop1:
	rest 4
	drum_note 3, 8
	drum_note 3, 8
	drum_note 3, 4
	drum_note 3, 1
	drum_note 3, 3
	drum_note 3, 4
	sound_loop 2, gbs_mobileadapter_Ch4.loop1
gbs_mobileadapter_Ch4.loop2:
	rest 4
	drum_note 3, 4
	sound_loop 11, gbs_mobileadapter_Ch4.loop2
	rest 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 3, 1
	drum_note 3, 1
	rest 4
	drum_note 3, 8
	drum_note 3, 8
	drum_note 3, 6
	drum_note 3, 2
	drum_note 3, 2
	drum_note 3, 1
	drum_note 3, 1
	sound_loop 0, gbs_mobileadapter_Ch4.mainloop

gbs_mobileadapter_Ch4.sub1:
gbs_mobileadapter_Ch4.sub1loop1:
	rest 4
	drum_note 3, 4
	sound_loop 7, gbs_mobileadapter_Ch4.sub1loop1
	rest 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 3, 1
	drum_note 3, 1
	sound_ret

	.align 4
	.global gbs_mobileadapter_Header
gbs_mobileadapter_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_mobileadapter_Ch1
	.int gbs_mobileadapter_Ch2
	.int gbs_mobileadapter_Ch3
	.int gbs_mobileadapter_Ch4
