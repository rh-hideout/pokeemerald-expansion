# Pokémon Emerald
### Tutorial: Name Box

This feature branch implements a name box in the style of the one in @tustin2121's [Trick-or-Treat House](https://www.pokecommunity.com/showthread.php?p=10566982) hack.

Features: 
- Implementation of a name plate attached to the dialog box.
- New command `speakername [textPoionter]` to set the name of the speaker to display in the box.
	- Examples in `examples/nameboxes`
	- Setting the speaker name to `NULL` hides the name plate.
	- Speaker name is automatically set to `NULL` in the `closemessage` command.
- Assign a flag to `OW_FLAG_SUPPRESS_SPEAKER_NAME` to dynamically disable/enable the nameplates
	- ie: ```c
			#define OW_FLAG_SUPPRESS_SPEAKER_NAME FLAG_UNUSED_0x881
		  ```
- All trainers capable of trainer sight battles automatically have their trainer name as the speaker name when talking to them or being seen by them.


![](nameboxes/nameboxes-1.png)
![](nameboxes/nameboxes-2.png)
![](nameboxes/nameboxes-3.png)

> [!NOTE]
> feature created by @tustin2121, and ported by @surskitty and @khbsd