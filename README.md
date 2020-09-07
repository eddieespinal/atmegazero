# ATMegaZero
===================

**Installing in Arduino IDE**
1. In the Arduino IDE, Navigate to File->Preferences and paste
   https://github.com/eddieespinal/atmegazero/raw/master/package_atmegazero_index.json
   into "Additional Board Manager URLs".
2. Open Tools->Board->Board Manager and Search "ATMegaZero".
3. Install the ATMegaZero board.


# Bootloader for ATMegaZero Board
================

**Requirements**
* LUFA: 111009
* WinAVR
* avrdude
* gcc-avr

**How to build the ATMegaZero bootloader (PC Recommended)**
* Download this repository
* Navigate to Caterina-ATMegaZero folder inside the Bootloader folder
* Open the build-atmegazero.bat file on a PC to create a new .hex bootloader file.