# Instructions
Install instructions for each supported operating system can be found in their respective directories under `docs/install/`.
Lines to those can be found under each heading.
This file only contains a short introduction to each supported system.
If you run into trouble, ask for help on Discord (see [README.md](README.md)).

After completing the install instructions for your OS, proceed to [Building pokeemerald-expansion](#building-pokeemerald-expansion).

## Windows
**Windows needs one of the systems to build the project**

**A note of caution**: As Windows 7 and Windows 8 are officially unsupported by Microsoft, some maintainers are unwilling to maintain the Windows 7/8 instructions. Thus, these instructions may break in the future with fixes taking longer than fixes to the Windows 10/11 instructions.

On Windows, the project can be built using the following systems:
- WSL2, fastest
- WSL1, 7 times slower than WSL2
- Msys2, 20 times slower than WSL2 (**NOTE**: Currently broken on pret upstream)
- Cygwin, 30 timer slower than WSL2 (**NOTE**: Currently broken on pret upstream)

**NOTE**: Only WSL systems are recommended.

[WSL Install instructions](docs/install/windows/WSL.md)

[Msys2 Install instructions](docs/install/windows/MSYS2.md)

[Cygwin Install instructions](docs/install/windows/CYGWIN.md)

## Linux
The project can be built on any Linux distribution.
Distributions with instructions:
- [Ubuntu](docs/install/linux/UBUNTU.md)
- [Debian](docs/install/linux/DEBIAN.md)
- [Arch Linux](docs/install/linux/ARCH_LINUX.md)
- [NixOS](docs/install/linux/NIXOS.md)

Other distributions have to infer what to do from [general instructions](docs/install/linux/OTHERS.md).

## Mac
Some extra considerations exist to get the testing system working.

[Mac instructions](docs/install/mac/MAC_OS.md)

## ChromeOS
Only tested on x86_64 based systems.

[Chrome OS instructions](docs/install/chromeos/CHROME_OS.md)

# Building pokeemerald-expansion
Follow these steps to build `pokeemerald-expansion`.
1. Navigate to the directory you want to keep the project in, be aware of any system specific limitations.
2. Download `pokeemerald-expansion` with `git`

    ```console
    git clone https://github.com/rh-hideout/pokeemerald-expansion
    ```
3. Navigate to the newly downloaded project.

    ```console
    cd pokeemerald-expansion
    ```
4. Build the project.

    ```console
    make
    ```
5. If everything worked correctly, something very similar to this should be seen.

    ```console
    arm-none-eabi-ld: warning: ../../pokeemerald.elf has a LOAD segment with RWX permissions
    Memory region         Used Size  Region Size  %age Used
               EWRAM:      243354 B       256 KB     92.83%
               IWRAM:       30492 B        32 KB     93.05%
                 ROM:    26072244 B        32 MB     77.70%
    cd build/modern && arm-none-eabi-ld  -T ../../ld_script_modern.ld --print-memory-usage -o ../../pokeemerald.elf <objs> <libs> | cat
    tools/gbafix/gbafix pokeemerald.elf -t"POKEMON EMER" -cBPEE -m01 -r0 --silent
    arm-none-eabi-objcopy -O binary pokeemerald.elf pokeemerald.gba
    tools/gbafix/gbafix pokeemerald.gba -p --silent
    ```
    And the build ROM will be in the directory as `pokeemerald.gba`.

# Building guidance

## Parallel builds

See [the GNU docs](https://www.gnu.org/software/make/manual/html_node/Parallel.html) and [this Stack Exchange thread](https://unix.stackexchange.com/questions/208568) for more information.

To speed up building, first get the value of `nproc` by running the following command:
```bash
nproc
```
Builds can then be sped up by running the following command:
```bash
make -j<output of nproc>
```
Replace `<output of nproc>` with the number that the `nproc` command returned.

`nproc` is not available on macOS. The alternative is `sysctl -n hw.ncpu` ([relevant Stack Overflow thread](https://stackoverflow.com/questions/1715580)).

### Other toolchains

To build using a toolchain other than devkitARM, override the `TOOLCHAIN` environment variable with the path to your toolchain, which must contain the subdirectory `bin`.
```bash
make TOOLCHAIN="/path/to/toolchain/here"
```
The following is an example:
```bash
make TOOLCHAIN="/usr/local/arm-none-eabi"
```
To compile the `modern` target with this toolchain, the subdirectories `lib`, `include`, and `arm-none-eabi` must also be present.

### Building with debug info

To build **pokeemerald.elf** with debug symbols and debug-compatible optimization under a modern toolchain:
```bash
make debug
```

# Useful additional tools

* [porymap](https://github.com/huderlem/porymap) for viewing and editing maps
* [poryscript](https://github.com/huderlem/poryscript) for scripting ([VS Code extension](https://marketplace.visualstudio.com/items?itemName=karathan.poryscript))
* [Tilemap Studio](https://github.com/Rangi42/tilemap-studio) for viewing and editing tilemaps
