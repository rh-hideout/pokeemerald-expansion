	.include "asm/macros.inc"

	.section .rodata
	.align 1


gbs_newbarktown_Ch1:
	gbs_switch 0
	tempo 187
	volume 7, 7
	stereo_panning FALSE, TRUE
	vibrato 18, 2, 3
	note_type 12, 8, 7
	rest 4
gbs_newbarktown_Ch1.mainloop:
	duty_cycle 0
	sound_call gbs_newbarktown_Ch1.sub1
	octave 3
	note Cs, 1
	rest 1
	octave 2
	note A_, 1
	rest 1
	octave 3
	note G_, 2
	note Fs, 2
	duty_cycle 2
	volume_envelope 8, 2
	note E_, 1
	note Fs, 1
	note E_, 1
	note D_, 1
	note Cs, 1
	octave 2
	note B_, 1
	note A_, 1
	note G_, 1
	duty_cycle 0
	volume_envelope 8, 7
	sound_call gbs_newbarktown_Ch1.sub1
	octave 3
	note Cs, 1
	rest 1
	octave 2
	note A_, 1
	rest 1
	octave 3
	note E_, 2
	duty_cycle 2
	volume_envelope 8, 2
	note Cs, 1
	rest 1
	octave 2
	note A_, 1
	octave 3
	note Cs, 1
	note E_, 1
	note G_, 1
	note A_, 1
	octave 4
	note Cs, 1
	note E_, 1
	note A_, 1
	duty_cycle 1
	volume_envelope 5, -6
	sound_call gbs_newbarktown_Ch1.sub2
	sound_call gbs_newbarktown_Ch1.sub2
	sound_call gbs_newbarktown_Ch1.sub2
	octave 2
	note G_, 2
	note B_, 2
	octave 3
	note D_, 2
	note Fs, 4
	note G_, 4
	note D_, 2
	octave 2
	note A_, 2
	octave 3
	note Cs, 2
	note E_, 2
	note G_, 4
	note A_, 4
	note B_, 2
	volume_envelope 8, 7
	sound_loop 0, gbs_newbarktown_Ch1.mainloop

gbs_newbarktown_Ch1.sub1:
	octave 3
	note Fs, 1
	rest 1
	note D_, 1
	rest 1
	note A_, 2
	note D_, 1
	rest 1
	note Fs, 1
	rest 1
	note D_, 1
	rest 1
	note As, 2
	note D_, 1
	rest 1
	note Fs, 1
	rest 1
	note D_, 1
	rest 1
	note B_, 2
	note Fs, 1
	rest 1
	note Fs, 1
	rest 1
	note D_, 1
	rest 1
	octave 4
	note C_, 2
	octave 3
	note D_, 1
	rest 1
	octave 2
	note B_, 1
	rest 1
	note G_, 1
	rest 1
	octave 3
	note G_, 2
	octave 2
	note B_, 1
	rest 1
	note B_, 1
	rest 1
	note Gs, 1
	rest 1
	octave 3
	note E_, 2
	octave 2
	note B_, 1
	rest 1
	sound_ret

gbs_newbarktown_Ch1.sub2:
	octave 2
	note G_, 2
	note B_, 2
	octave 3
	note D_, 2
	note Fs, 4
	note G_, 4
	note D_, 2
	octave 2
	note A_, 2
	octave 3
	note Cs, 2
	note E_, 2
	note G_, 4
	note A_, 4
	note E_, 2
	sound_ret

gbs_newbarktown_Ch2:
	gbs_switch 1
	stereo_panning TRUE, TRUE
	vibrato 18, 2, 3
	note_type 6, 10, 7
	rest 8
gbs_newbarktown_Ch2.mainloop:
	duty_cycle 2
	note_type 6, 10, 7
	sound_call gbs_newbarktown_Ch2.sub1
	sound_call gbs_newbarktown_Ch2.sub1
	sound_call gbs_newbarktown_Ch2.sub2
	volume_envelope 8, 7
	octave 5
	note B_, 6
	note A_, 6
	volume_envelope 7, 7
	octave 6
	note D_, 4
	note Cs, 16
	sound_call gbs_newbarktown_Ch2.sub2
	volume_envelope 8, 7
	octave 5
	note B_, 6
	note A_, 6
	volume_envelope 7, 7
	octave 6
	note D_, 4
	note E_, 16
	sound_loop 0, gbs_newbarktown_Ch2.mainloop

gbs_newbarktown_Ch2.sub1:
	octave 2
	note D_, 4
	rest 8
	note D_, 1
	rest 1
	note D_, 1
	rest 1
	note D_, 2
	rest 2
	note D_, 8
	note As, 2
	rest 2
	note D_, 4
	rest 8
	note D_, 1
	rest 1
	note D_, 1
	rest 1
	note D_, 2
	rest 2
	note D_, 8
	octave 3
	note C_, 2
	rest 2
	octave 2
	note G_, 4
	rest 8
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	octave 1
	note Gs, 2
	rest 2
	note Gs, 8
	octave 2
	note D_, 2
	rest 2
	note A_, 4
	rest 8
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	octave 1
	note A_, 2
	rest 2
	note A_, 8
	octave 2
	note Cs, 4
	sound_ret

gbs_newbarktown_Ch2.sub2:
	note_type 6, 9, 7
	duty_cycle 2
	octave 4
	note B_, 12
	note A_, 12
	note G_, 8
	note_type 12, 9, 7
	note E_, 16
	sound_ret

gbs_newbarktown_Ch3:
	gbs_switch 2
	stereo_panning TRUE, FALSE
	note_type 12, 1, 0
	octave 5
	note D_, 2
	note E_, 2
gbs_newbarktown_Ch3.mainloop:
	vibrato 22, 2, 3
	note Fs, 4
	note A_, 4
	note G_, 2
	note Fs, 2
	note E_, 2
	note G_, 2
	note Fs, 6
	note D_, 2
	octave 4
	note A_, 6
	note G_, 1
	note A_, 1
	note B_, 4
	octave 5
	note D_, 4
	note E_, 2
	note D_, 2
	note Cs, 2
	note D_, 2
	note E_, 6
	note Fs, 2
	note E_, 4
	rest 2
	note D_, 1
	note E_, 1
	note Fs, 4
	note A_, 4
	note As, 2
	note A_, 2
	note G_, 2
	note As, 2
	note A_, 6
	octave 6
	note Cs, 2
	note D_, 6
	octave 5
	note E_, 1
	note Fs, 1
	note G_, 6
	note A_, 2
	note B_, 8
	note A_, 6
	note G_, 1
	note Fs, 1
	note E_, 4
	rest 4
	volume_envelope 2, 5
	vibrato 18, 5, 3
	octave 2
	note G_, 16
	note A_, 16
	note G_, 16
	note A_, 16
	note G_, 16
	note A_, 16
	note G_, 16
	note A_, 14
	volume_envelope 1, 0
	vibrato 22, 2, 3
	octave 5
	note D_, 1
	note E_, 1
	sound_loop 0, gbs_newbarktown_Ch3.mainloop

	.align 4
	.global gbs_newbarktown_Header
gbs_newbarktown_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_newbarktown_Ch1
	.int gbs_newbarktown_Ch2
	.int gbs_newbarktown_Ch3
