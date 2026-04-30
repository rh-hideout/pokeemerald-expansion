	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_mtmoonsquare_Ch1:
	gbs_switch 0
	tempo 112
	volume 7, 7
	duty_cycle 2
	pitch_offset 1
	rest 1
gbs_mtmoonsquare_Ch1.mainloop:
	note_type 12, 4, 4
gbs_mtmoonsquare_Ch1.loop1:
	octave 4
	note D_, 2
	note E_, 2
	note Fs, 4
	note Fs, 2
	note A_, 2
	octave 5
	note D_, 4
	sound_loop 2, gbs_mtmoonsquare_Ch1.loop1
gbs_mtmoonsquare_Ch1.loop2:
	octave 4
	note E_, 2
	note Fs, 2
	note Gs, 4
	note Gs, 2
	note B_, 2
	octave 5
	note E_, 4
	sound_loop 2, gbs_mtmoonsquare_Ch1.loop2
gbs_mtmoonsquare_Ch1.loop3:
	octave 4
	note Cs, 2
	note D_, 2
	note E_, 4
	note E_, 2
	note G_, 2
	octave 5
	note Cs, 4
	sound_loop 2, gbs_mtmoonsquare_Ch1.loop3
gbs_mtmoonsquare_Ch1.loop4:
	octave 4
	note D_, 2
	note E_, 2
	note Fs, 4
	note Fs, 2
	note A_, 2
	octave 5
	note D_, 4
	sound_loop 2, gbs_mtmoonsquare_Ch1.loop4
	sound_loop 0, gbs_mtmoonsquare_Ch1.mainloop

gbs_mtmoonsquare_Ch2:
	gbs_switch 1
	duty_cycle 2
	vibrato 24, 2, 4
gbs_mtmoonsquare_Ch2.mainloop:
	note_type 12, 8, 2
gbs_mtmoonsquare_Ch2.loop1:
	octave 4
	note D_, 2
	note E_, 2
	note Fs, 4
	note Fs, 2
	note A_, 2
	octave 5
	note D_, 4
	note_type 12, 6, 2
	sound_loop 2, gbs_mtmoonsquare_Ch2.loop1
	note_type 12, 8, 2
gbs_mtmoonsquare_Ch2.loop2:
	octave 4
	note E_, 2
	note Fs, 2
	note Gs, 4
	note Gs, 2
	note B_, 2
	octave 5
	note E_, 4
	note_type 12, 6, 2
	sound_loop 2, gbs_mtmoonsquare_Ch2.loop2
	note_type 12, 8, 2
gbs_mtmoonsquare_Ch2.loop3:
	octave 4
	note Cs, 2
	note D_, 2
	note E_, 4
	note E_, 2
	note G_, 2
	octave 5
	note Cs, 4
	note_type 12, 6, 2
	sound_loop 2, gbs_mtmoonsquare_Ch2.loop3
	note_type 12, 8, 2
gbs_mtmoonsquare_Ch2.loop4:
	octave 4
	note D_, 2
	note E_, 2
	note Fs, 4
	note Fs, 2
	note A_, 2
	octave 5
	note D_, 4
	note_type 12, 6, 2
	sound_loop 2, gbs_mtmoonsquare_Ch2.loop4
	sound_loop 0, gbs_mtmoonsquare_Ch2.mainloop

	.align 4
	.global gbs_mtmoonsquare_Header
gbs_mtmoonsquare_Header:
	.byte 2	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_mtmoonsquare_Ch1
	.int gbs_mtmoonsquare_Ch2
