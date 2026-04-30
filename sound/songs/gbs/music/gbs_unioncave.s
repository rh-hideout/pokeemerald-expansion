	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_unioncave_Ch1:
	gbs_switch 0
	tempo 160
	volume 7, 7
	duty_cycle 1
	pitch_offset 2
	vibrato 24, 3, 4
	stereo_panning FALSE, TRUE
gbs_unioncave_Ch1.mainloop:
	note_type 12, 11, 3
gbs_unioncave_Ch1.loop1:
	sound_call gbs_unioncave_Ch1.sub1
	sound_loop 4, gbs_unioncave_Ch1.loop1
gbs_unioncave_Ch1.loop2:
	octave 2
	note Gs, 2
	octave 3
	note Cs, 2
	note E_, 4
	note Cs, 2
	note E_, 2
	note F_, 4
	sound_loop 8, gbs_unioncave_Ch1.loop2
gbs_unioncave_Ch1.loop3:
	octave 2
	note A_, 2
	octave 3
	note D_, 2
	note F_, 4
	note D_, 2
	note F_, 2
	note Fs, 4
	sound_loop 4, gbs_unioncave_Ch1.loop3
	rest 4
	volume_envelope 8, 0
	note F_, 16
	note Fs, 16
	note G_, 16
	note Fs, 16
	note G_, 8
	note Fs, 8
	note F_, 8
	note E_, 8
	note G_, 8
	note Fs, 8
	octave 4
	note C_, 8
	octave 3
	note A_, 8
	volume_envelope 9, 5
	pitch_offset 4
	sound_call gbs_unioncave_Ch1.sub1
	pitch_offset 8
	sound_call gbs_unioncave_Ch1.sub1
	pitch_offset 12
	sound_call gbs_unioncave_Ch1.sub1
	pitch_offset 16
	sound_call gbs_unioncave_Ch1.sub1
	pitch_offset 2
	sound_loop 0, gbs_unioncave_Ch1.mainloop

gbs_unioncave_Ch1.sub1:
	octave 2
	note Gs, 2
	octave 3
	note Cs, 2
	note E_, 12
	sound_ret

gbs_unioncave_Ch2:
	gbs_switch 1
	duty_cycle 3
	vibrato 8, 2, 4
gbs_unioncave_Ch2.mainloop:
	note_type 12, 12, 4
	sound_call gbs_unioncave_Ch2.sub1
	volume_envelope 12, 5
	sound_call gbs_unioncave_Ch2.sub1
	volume_envelope 12, 7
	sound_call gbs_unioncave_Ch2.sub1
	volume_envelope 12, 4
	note Cs, 4
	octave 3
	note B_, 4
	octave 4
	note D_, 2
	note E_, 2
	note Cs, 2
	octave 3
	note B_, 2
	octave 4
	note Cs, 4
	octave 3
	note B_, 4
	octave 4
	note D_, 8
	octave 3
	note B_, 4
	octave 4
	note D_, 4
	note Fs, 2
	note F_, 2
	note Cs, 2
	octave 3
	note B_, 2
	octave 4
	note Cs, 8
	note D_, 4
	note Cs, 4
	rest 4
	volume_envelope 10, 0
	note C_, 16
	note Cs, 16
	note D_, 16
	note Cs, 16
	note E_, 16
	note Ds, 16
	note As, 16
	note A_, 16
	volume_envelope 10, 5
	vibrato 6, 4, 4
	sound_call gbs_unioncave_Ch2.sub2
	vibrato 4, 3, 3
	sound_call gbs_unioncave_Ch2.sub2
	vibrato 2, 2, 2
	sound_call gbs_unioncave_Ch2.sub2
	vibrato 1, 4, 1
	sound_call gbs_unioncave_Ch2.sub2
	vibrato 8, 2, 4
	sound_loop 0, gbs_unioncave_Ch2.mainloop

gbs_unioncave_Ch2.sub1:
	octave 4
	note C_, 4
	octave 3
	note As, 4
	octave 4
	note Cs, 2
	note Ds, 2
	note C_, 2
	octave 3
	note As, 2
	octave 4
	note C_, 4
	octave 3
	note As, 4
	octave 4
	note Cs, 8
	octave 3
	note As, 4
	octave 4
	note Cs, 4
	note F_, 2
	note E_, 2
	note C_, 2
	octave 3
	note As, 2
	octave 4
	note C_, 8
	note Cs, 4
	note C_, 4
	sound_ret

gbs_unioncave_Ch2.sub2:
	octave 2
	note Gs, 2
	octave 3
	note Cs, 2
	note E_, 12
	sound_ret

gbs_unioncave_Ch3:
	gbs_switch 2
	note_type 12, 1, 6
	stereo_panning TRUE, FALSE
gbs_unioncave_Ch3.mainloop:
gbs_unioncave_Ch3.loop1:
	rest 16
	sound_loop 7, gbs_unioncave_Ch3.loop1
	rest 14
	octave 4
	note C_, 2
gbs_unioncave_Ch3.loop2:
	rest 2
	octave 3
	note E_, 2
	rest 2
	note E_, 2
	note Gs, 2
	note E_, 2
	rest 2
	octave 4
	note C_, 2
	sound_loop 4, gbs_unioncave_Ch3.loop2
gbs_unioncave_Ch3.loop3:
	rest 2
	octave 3
	note F_, 2
	rest 2
	note F_, 2
	note A_, 2
	note F_, 2
	rest 2
	octave 4
	note Cs, 2
	sound_loop 4, gbs_unioncave_Ch3.loop3
	rest 4
	note C_, 8
	octave 3
	note B_, 8
	note As, 8
	note A_, 8
	octave 4
	note Cs, 8
	note C_, 8
	octave 3
	note B_, 8
	note As, 8
gbs_unioncave_Ch3.loop4:
	note A_, 4
	note G_, 4
	note As, 2
	octave 4
	note C_, 2
	octave 3
	note A_, 2
	note G_, 2
	sound_loop 3, gbs_unioncave_Ch3.loop4
	note A_, 4
	note G_, 4
	note As, 8
gbs_unioncave_Ch3.loop5:
	rest 16
	sound_loop 4, gbs_unioncave_Ch3.loop5
	sound_loop 0, gbs_unioncave_Ch3.mainloop

gbs_unioncave_Ch4:
	gbs_switch 3
	toggle_noise 1
	drum_speed 12
gbs_unioncave_Ch4.mainloop:
	stereo_panning TRUE, FALSE
	drum_note 5, 4
	stereo_panning TRUE, TRUE
	drum_note 6, 4
	stereo_panning FALSE, TRUE
	drum_note 9, 4
	rest 8
	stereo_panning FALSE, TRUE
	drum_note 5, 4
	stereo_panning TRUE, TRUE
	drum_note 6, 4
	stereo_panning TRUE, FALSE
	drum_note 9, 4
	rest 8
	sound_loop 0, gbs_unioncave_Ch4.mainloop

	sound_loop 0, gbs_unioncave_Ch4.mainloop @ unused

	.align 4
	.global gbs_unioncave_Header
gbs_unioncave_Header:
	.byte 4	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_unioncave_Ch1
	.int gbs_unioncave_Ch2
	.int gbs_unioncave_Ch3
	.int gbs_unioncave_Ch4
