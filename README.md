# Firmwares for ATmega32u4-based keyboard controllers

Custom firmwares to replace stock Costar controllers allowing you to program your keyboard.

Firmwares include:
* The HID Liberation Device (for Filco Majestouch full size)

For more information, please see WIKI http://deskthority.net/wiki/HID_Liberation_Device_-_Instructions

## Intentions

This firmware is to be serve as simple firmware for further customizations.


## Other keyboard firmwares

If you happen to seek more advanced firmwares, you could look into other projects:

Some other noteworhty keyboard firmware projects are

* https://github.com/tmk/tmk_keyboard

## Compiling firmwares

In order to compile firmwares, avr-gcc is required. Please ensure you have it installed before moving to next step.

You need to select the correct MODEL and LAYOUT variables in the Makefile

```
BOARD = hib_liber
LAYOUT = ansi_iso_jis
MCU = atmega32u4
F_CPU = 16000000
B_LOADER = \"jmp\ 0x7000\"
```

Then run the `make` command in a terminal. Always run a `make clean` first.

```
make clean; make
```

If the process is successful, you would find binary firmware with extension .hex inside the binaries folder

## Flashing the controller

Make sure you install dfu-programmer first.

```
dfu-programmer atmega32u4 erase
dfu-programmer atmega32u4 flash avr_keyboard.hex
dfu-programmer atmega32u4 start
```
