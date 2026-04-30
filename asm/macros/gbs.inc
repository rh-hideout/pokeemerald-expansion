	.equ	TEMPO,	0xbb	@ tempo (BPM/2)
	.equ	KEYSH,	0xbc	@ key shift

	.set	TRUE,	1
	.set	FALSE,	0

	enum_start 1
	enum C_ @ 1
	enum Cs @ 2
	enum D_ @ 3
	enum Ds @ 4
	enum E_ @ 5
	enum F_ @ 6
	enum Fs @ 7
	enum G_ @ 8
	enum Gs @ 9
	enum A_ @ A
	enum As @ B
	enum B_ @ C

	.equ	GBP,			0xB6	@ switch to GBP engine
	.equ	GBP_TEMPO_BPM,	0x96	@ magic BPM

.macro gbs_switch channel:req
	.byte KEYSH, 0
	.if \channel == 0
		.byte TEMPO, GBP_TEMPO_BPM/2
	.endif
	.byte GBP, \channel
.endm

.macro note pitch:req, length:req
	.byte (\pitch << 4) | (\length - 1)
.endm

.macro drum_note instrument:req, length:req
	note \instrument, \length
.endm

.macro rest length:req
	note 0, \length
.endm

.macro square_note length:req, volume:req, fade:req, frequency:req
	.byte \length
	.if \fade < 0
		.byte (\volume << 4) | (\fade * -1) | 0b1000 @ volume envelope
	.else
		.byte (\volume << 4) | (\fade) @ volume envelope
	.endif
	.2byte \frequency
.endm

.macro noise_note length:req, volume:req, fade:req, frequency:req
	.byte \length
	.if \fade < 0
		.byte (\volume << 4) | (\fade * -1) | 0b1000 @ volume envelope
	.else
		.byte (\volume << 4) | (\fade) @ volume envelope
	.endif
	.byte \frequency
.endm

@ GBSCommands indexes (see include/gbs.h)
	enum_start 0xD0

	enum _octave @ 0xD0
.macro octave n:req
	@ assert 1 <= (\n) && (\n) <= 8, "octave must be 1-8"
    .if 1 <= (\n) && (\n) <= 8
        .byte _octave + 8 - (\n)
    .else
        .byte _octave
    .endif
.endm

	enum_start 0xD8 @ skip octave values

	enum _note_type @ 0xD8
.macro note_type length:req, volume, fade_wave
	.byte _note_type
	.byte \length
	.ifnb \volume
		.if \fade_wave < 0
			.byte (\volume << 4) | (\fade_wave * -1) | 0b1000 @ volume envelope
		.else
			.byte (\volume << 4) | (\fade_wave) @ volume envelope
		.endif
	.endif
.endm

@ only valid on the noise channel
.macro drum_speed length:req
	note_type \length
.endm

	enum _transpose @ 0xD9
.macro transpose num_octaves:req, num_pitches:req
	.byte _transpose
	.byte (\num_octaves << 4) | (\num_pitches)
.endm

	enum _tempo @ 0xDA
.macro tempo tempo:req
	.byte _tempo
	.2byte \tempo @ TODO: big endian
.endm

	enum _duty_cycle @ 0xDB
.macro duty_cycle cycle
	.byte _duty_cycle
	.byte \cycle
.endm

	enum _volume_envelope @ 0xDC
.macro volume_envelope volume:req, fade_wave:req
	.byte _volume_envelope
	.if \fade_wave < 0
		.byte (\volume << 4) | (\fade_wave * -1) | 0b1000  @ volume envelope
	.else
		.byte (\volume << 4) | (\fade_wave) @ volume envelope
	.endif
.endm

	enum _pitch_sweep @ 0xDD
.macro pitch_sweep length:req, pitch_change:req
	.byte _pitch_sweep
	.if \pitch_change < 0
		.byte (\length << 4) | (\pitch_change * -1) | 0b1000 @ pitch sweep
	.else
		.byte (\length << 4) | (\pitch_change) @ pitch sweep
	.endif
.endm

	enum _duty_cycle_pattern @ 0xDE
.macro duty_cycle_pattern a:req, b:req, c:req, d:req
	.byte _duty_cycle_pattern
	.byte (\a << 6) | (\b << 4) | (\c << 2) | (\d << 0) @ duty cycle pattern
.endm

	enum _toggle_sfx @ 0xDF
.macro toggle_sfx
	.byte _toggle_sfx
.endm

	enum _pitch_slide @ 0xE0
.macro pitch_slide duration:req, octave:req, pitch:req
	.byte _pitch_slide
	.byte \duration - 1
	.byte ((8 - \octave) << 4) | (\pitch % 12)
.endm

	enum _vibrato @ 0xE1
.macro vibrato delay:req, extent:req, rate:req
	.byte _vibrato
	.byte \delay
    .byte (\extent << 4) | \rate
.endm

	enum _unknownmusic0xe2 @ 0xE2
.macro unknownmusic0xe2 unknown:req
	.byte _unknownmusic0xe2
	.byte \unknown
.endm

	enum _toggle_noise @ 0xE3
.macro toggle_noise id
	.byte _toggle_noise
	.ifnb \id
		.byte \id
	.endif
.endm

	enum _force_stereo_panning @ 0xE4
.macro force_stereo_panning left_enable:req, right_enable:req
	.byte _force_stereo_panning
	.byte (0b1111 * (1 && \left_enable) << 4) | (0b1111 * (1 && \right_enable))
.endm

	enum _volume @ 0xE5
.macro volume left_volume:req, right_volume:req
	.byte _volume
	.byte (\left_volume << 4) | (\right_volume)
.endm

	enum _pitch_offset @ 0xE6
.macro pitch_offset offset:req
	.byte _pitch_offset
	.2byte \offset @ TODO: big endian
.endm

	enum _unknownmusic0xe7 @ 0xE7
.macro unknownmusic0xe7 unknown:req
	.byte _unknownmusic0xe7
	.byte \unknown @ unknown
.endm

	enum _unknownmusic0xe8 @ 0xE8
.macro unknownmusic0xe8 unknown:req
	.byte _unknownmusic0xe8
	.byte \unknown @ unknown
.endm

	enum _tempo_relative @ 0xE9
.macro tempo_relative adjustment:req
	.byte _tempo_relative
	.2byte \adjustment @ TODO: big endian
.endm

	enum _restart_channel @ 0xEA
.macro restart_channel address:req
	.byte _restart_channel
	.4byte \address
.endm

	enum _new_song @ 0xEB
.macro new_song id:req
	.byte _new_song
	.2byte \id @ TODO: big endian
.endm

	enum _sfx_priority_on @ 0xEC
.macro sfx_priority_on
	.byte _sfx_priority_on
.endm

	enum _sfx_priority_off @ 0xED
.macro sfx_priority_off
	.byte _sfx_priority_off
.endm

	enum _unknownmusic0xee @ 0xEE
.macro unknownmusic0xee address:req
	.byte _unknownmusic0xee
	.4byte \address
.endm

	enum _stereo_panning @ 0xEF
.macro stereo_panning left_enable:req, right_enable:req
	.byte _stereo_panning
	.byte (0b1111 * (1 && \left_enable) << 4) | (0b1111 * (1 && \right_enable))
.endm

	enum _sfx_toggle_noise @ 0xF0
.macro sfx_toggle_noise id
	.byte _sfx_toggle_noise
	.ifnb \id
		.byte \id
	.endif
.endm

	enum _music0xf1 @ 0xF1
.macro music0xf1
	.byte _music0xf1
.endm

	enum _music0xf2 @ 0xF2
.macro music0xf2
	.byte _music0xf2
.endm

	enum _music0xf3 @ 0xF3
.macro music0xf3
	.byte _music0xf3
.endm

	enum _music0xf4 @ 0xF4
.macro music0xf4
	.byte _music0xf4
.endm

	enum _music0xf5 @ 0xF5
.macro music0xf5
	.byte _music0xf5
.endm

	enum _music0xf6 @ 0xF6
.macro music0xf6
	.byte _music0xf6
.endm

	enum _music0xf7 @ 0xF7
.macro music0xf7
	.byte _music0xf7
.endm

	enum _music0xf8 @ 0xF8
.macro music0xf8
	.byte _music0xf8
.endm

	enum _unknownmusic0xf9 @ 0xF9
.macro unknownmusic0xf9
	.byte _unknownmusic0xf9
.endm

	enum _set_condition @ 0xFA
.macro set_condition condition:req
	.byte _set_condition
	.byte \condition
.endm

	enum _sound_jump_if @ 0xFB
.macro sound_jump_if condition:req, address:req
	.byte _sound_jump_if
	.byte \condition
	.4byte \address
.endm

	enum _sound_jump @ 0xFC
.macro sound_jump address:req
	.byte _sound_jump
	.4byte \address
.endm

	enum _sound_loop @ 0xFD
.macro sound_loop count:req, address:req
	.byte _sound_loop
	.byte \count
	.4byte \address
.endm

	enum _sound_call @ 0xFE
.macro sound_call address:req
	.byte _sound_call
	.4byte \address
.endm

	enum _sound_ret @ 0xFF
.macro sound_ret
	.byte _sound_ret
.endm
