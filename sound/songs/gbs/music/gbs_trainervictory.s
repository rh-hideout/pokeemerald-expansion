	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_trainervictory_Ch1:
	gbs_switch 0
	tempo 120
	volume 7, 7
	duty_cycle 2
	pitch_offset 1
	note_type 8, 11, 1
	octave 4
	note E_, 2
	note E_, 2
	note E_, 2
	note E_, 2
	note Fs, 2
	note G_, 2
	volume_envelope 11, 6
	note A_, 12
	stereo_panning FALSE, TRUE
gbs_trainervictory_Ch1.mainloop:
gbs_trainervictory_Ch1.loop1:
	volume_envelope 7, 2
	sound_call gbs_trainervictory_Ch1.sub1
	volume_envelope 5, 1
	note Cs, 2
	note E_, 2
	note Fs, 2
	note A_, 2
	note B_, 2
	octave 4
	note Cs, 2
	volume_envelope 7, 2
	octave 3
	note A_, 2
	rest 2
	octave 4
	note Cs, 2
	note E_, 6
	sound_loop 2, gbs_trainervictory_Ch1.loop1
	sound_call gbs_trainervictory_Ch1.sub1
	note A_, 2
	rest 2
	note F_, 2
	note A_, 6
	note As, 2
	rest 2
	note G_, 2
	note As, 6
gbs_trainervictory_Ch1.loop2:
	volume_envelope 7, 2
	octave 4
	note D_, 2
	note Cs, 2
	octave 3
	note A_, 2
	sound_loop 3, gbs_trainervictory_Ch1.loop2
	note Fs, 2
	note A_, 2
	octave 4
	note D_, 2
gbs_trainervictory_Ch1.loop3:
	octave 4
	note Cs, 2
	octave 3
	note B_, 2
	note A_, 2
	sound_loop 3, gbs_trainervictory_Ch1.loop3
	note E_, 2
	note Fs, 2
	note G_, 2
	sound_loop 0, gbs_trainervictory_Ch1.mainloop

gbs_trainervictory_Ch1.sub1:
	octave 3
	note Fs, 2
	rest 2
	note D_, 2
	note Fs, 6
	note G_, 2
	rest 2
	note E_, 2
	note G_, 6
	sound_ret

gbs_trainervictory_Ch2:
	gbs_switch 1
	vibrato 18, 3, 4
	duty_cycle 3
	note_type 8, 13, 1
	octave 4
	note A_, 2
	note A_, 2
	note A_, 2
	note A_, 2
	note B_, 2
	octave 5
	note Cs, 2
	volume_envelope 13, 6
	note D_, 12
	stereo_panning TRUE, FALSE
gbs_trainervictory_Ch2.mainloop:
gbs_trainervictory_Ch2.loop1:
	note_type 8, 8, 2
	sound_call gbs_trainervictory_Ch2.sub1
	note Fs, 2
	rest 2
	note G_, 2
	note A_, 6
	note E_, 2
	rest 2
	note Fs, 2
	note G_, 6
	sound_loop 2, gbs_trainervictory_Ch2.loop1
	sound_call gbs_trainervictory_Ch2.sub1
	note F_, 2
	rest 2
	note C_, 2
	note F_, 6
	note G_, 2
	rest 2
	note D_, 2
	note G_, 6
	note_type 12, 8, 8
	note Fs, 16
	note E_, 16
	sound_loop 0, gbs_trainervictory_Ch2.mainloop

gbs_trainervictory_Ch2.sub1:
	octave 4
	note D_, 2
	rest 2
	octave 3
	note A_, 2
	octave 4
	note D_, 6
	note E_, 2
	rest 2
	octave 3
	note B_, 2
	octave 4
	note E_, 6
	sound_ret

gbs_trainervictory_Ch3:
	gbs_switch 2
	note_type 8, 2, 5
	octave 3
	note G_, 6
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	note Fs, 6
	note D_, 2
	note Cs, 2
	octave 2
	note B_, 2
gbs_trainervictory_Ch3.mainloop:
gbs_trainervictory_Ch3.loop1:
	sound_call gbs_trainervictory_Ch3.sub1
	octave 3
	note Cs, 2
	rest 2
	note Cs, 2
	note A_, 2
	note Fs, 2
	note Cs, 2
	octave 2
	note A_, 2
	rest 2
	octave 3
	note A_, 1
	rest 1
	note A_, 6
	sound_loop 2, gbs_trainervictory_Ch3.loop1
	sound_call gbs_trainervictory_Ch3.sub1
	octave 3
	note C_, 2
	rest 2
	note C_, 2
	note A_, 2
	note F_, 2
	note C_, 2
	note D_, 2
	rest 2
	note D_, 2
	octave 4
	note D_, 2
	octave 3
	note As, 2
	note G_, 2
	note D_, 2
	note Fs, 2
	note A_, 2
	octave 4
	note D_, 12
	octave 3
	note A_, 2
	note Fs, 2
	note D_, 2
	octave 2
	note A_, 2
	octave 3
	note D_, 2
	note E_, 2
	note A_, 12
	note G_, 2
	note E_, 2
	note Cs, 2
	sound_loop 0, gbs_trainervictory_Ch3.mainloop

gbs_trainervictory_Ch3.sub1:
	octave 2
	note A_, 2
	rest 2
	note A_, 2
	octave 3
	note Fs, 2
	note D_, 2
	octave 2
	note A_, 2
	note B_, 2
	rest 2
	note B_, 2
	octave 3
	note G_, 2
	note E_, 2
	octave 2
	note B_, 2
	sound_ret

	.align 4
	.global gbs_trainervictory_Header
gbs_trainervictory_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_trainervictory_Ch1
	.int gbs_trainervictory_Ch2
	.int gbs_trainervictory_Ch3
