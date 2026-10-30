# j67g

67 keys Japanese style keyboard designed by Salicylic_Acid.
The firmware source is not published upstream, so this definition was written from the PCB data.

* Keyboard Maintainer: [r-okm](https://github.com/r-okm)
* Hardware Supported: j67g PCB (ATmega32U4 on board)
* Hardware Availability: [PCB Data](https://github.com/Salicylic-acid3/PCB_Data/tree/main/J67G), [VIA JSON](https://github.com/Salicylic-acid3/via-json/blob/main/j67g.json)

This directory is not part of qmk_firmware.
Run `bin/install_keyboards.sh` from the userspace root before building to copy it into qmk_firmware; CI runs the same script.
Rerun it after editing the definition, since qmk_firmware builds its own copy.

Make example for this keyboard (after setting up your build environment):

    qmk compile -kb salicylic_acid3/j67g -km r_okm

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
