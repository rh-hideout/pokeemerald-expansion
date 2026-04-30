	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_ruinsofalphradio_Ch1:
	gbs_switch 0
	tempo 160
	volume 7, 7
	duty_cycle 0
	pitch_offset 280
	vibrato 0, 15, 0
	stereo_panning TRUE, FALSE
gbs_ruinsofalphradio_Ch1.mainloop:
	note_type 6, 7, 1
	sound_call gbs_ruinsofalphradio_Ch1.sub1
	note_type 12, 10, 1
	rest 16
	rest 16
	sound_call gbs_ruinsofalphradio_Ch1.sub2
	note_type 12, 10, 1
	rest 16
	rest 16
	sound_call gbs_ruinsofalphradio_Ch1.sub1
	note_type 12, 10, 1
	rest 16
	sound_loop 0, gbs_ruinsofalphradio_Ch1.mainloop

gbs_ruinsofalphradio_Ch1.sub1:
	octave 4
	note G_, 1
	note Fs, 1
	note G_, 1
	note Fs, 1
	note C_, 8
	sound_ret

gbs_ruinsofalphradio_Ch1.sub2:
	octave 4
	note G_, 1
	note Fs, 1
	note G_, 1
	note Fs, 1
	note C_, 4
	note G_, 1
	octave 5
	note C_, 8
	sound_ret

gbs_ruinsofalphradio_Ch2:
	gbs_switch 1
	duty_cycle 1
	vibrato 1, 14, 0
gbs_ruinsofalphradio_Ch2.mainloop:
	stereo_panning FALSE, TRUE
	note_type 6, 8, 1
	sound_call gbs_ruinsofalphradio_Ch1.sub1
	note_type 12, 10, 1
	rest 16
	rest 16
	note_type 6, 8, 1
	sound_call gbs_ruinsofalphradio_Ch1.sub2
	note_type 12, 10, 1
	rest 16
	sound_loop 0, gbs_ruinsofalphradio_Ch2.mainloop

gbs_ruinsofalphradio_Ch3:
	gbs_switch 2
	note_type 6, 2, 6
gbs_ruinsofalphradio_Ch3.mainloop:
	octave 2
	note C_, 1
	note Cs, 1
	note C_, 1
	rest 16
	sound_loop 0, gbs_ruinsofalphradio_Ch3.mainloop

	.align 4
	.global gbs_ruinsofalphradio_Header
gbs_ruinsofalphradio_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_ruinsofalphradio_Ch1
	.int gbs_ruinsofalphradio_Ch2
	.int gbs_ruinsofalphradio_Ch3
