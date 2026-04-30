	.include "asm/macros.inc"

	.section .rodata
	.align 1

gbs_lakeofragerocketradio_Ch1:
	gbs_switch 0
	tempo 160
	volume 7, 7
	duty_cycle 1
	pitch_offset 4376
	vibrato 0, 15, 0
	stereo_panning TRUE, FALSE
gbs_lakeofragerocketradio_Ch1.mainloop:
	note_type 12, 10, 7
	octave 7
	note G_, 4
	note Fs, 4
	note G_, 4
	note Fs, 4
	rest 16
	sound_loop 0, gbs_lakeofragerocketradio_Ch1.mainloop

gbs_lakeofragerocketradio_Ch2:
	gbs_switch 1
	duty_cycle 1
	vibrato 19, 14, 8
	note_type 12, 10, 7
	rest 2
	stereo_panning FALSE, TRUE
	sound_loop 0, gbs_lakeofragerocketradio_Ch1.mainloop

gbs_lakeofragerocketradio_Ch3:
	gbs_switch 2
	note_type 12, 2, 6
	vibrato 16, 4, 4
	rest 4
	sound_loop 0, gbs_lakeofragerocketradio_Ch1.mainloop

	.align 4
	.global gbs_lakeofragerocketradio_Header
gbs_lakeofragerocketradio_Header:
	.byte 3	@ NumTrks
	.byte 0	@ NumBlks
	.byte 0	@ Priority
	.byte 0	@ Reverb

	.int voicegroup000

	.int gbs_lakeofragerocketradio_Ch1
	.int gbs_lakeofragerocketradio_Ch2
	.int gbs_lakeofragerocketradio_Ch3
