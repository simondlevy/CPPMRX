/*
   Test program for CPPM class library

   Copyright (C) 2017 Simon D. Levy

   This file is part of CPPM.

   CPPM is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   CPPM is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with CPPM.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "CPPM.h"

// For usable pins on Arduino boards see https://www.arduino.cc/en/Reference/AttachInterrupt.
// Other boards (Teensy, Ladybug) support interrupts on all digital pins.
static const uint8_t RXPIN = 0;

static const uint8_t NCHAN  = 5;

static CPPM rx(RXPIN, NCHAN);

void setup(void)
{
    Serial.begin(115200);

    rx.begin();
}

void loop(void)
{
    uint16_t rcData[NCHAN];

    rx.computeRC(rcData);

    for (uint8_t k=0; k<NCHAN; ++k) {
        Serial.print(rcData[k]);
        Serial.print(" ");
    }
    Serial.println();
}
