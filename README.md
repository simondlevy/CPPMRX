This repository contains a little Arduino library for reading the so-called
CPPM (Combined Pulse-Pulse Modulation) signal from an R/C receiver like the
FrSky Micro RX.  Although other such libraries exist, I wanted one that was (1)
absolutely minimal (no assumptions about channel identities like pitch, roll;
no hardware-specific optimizations) and (2) would work with all Arduino-compatible hardware
(e.g., Arduino Uno; Teensy; and STM32L4-based boards from Tlera Corp.) Thanks
to the generosity of Greg Tomasch, I am able to share this library, based on
Greg's code.  I have tested it with an Arduino Uno, Teensy 3.2, and Ladybug
STM32L432 boards, using the FrSky MicoRX.  
