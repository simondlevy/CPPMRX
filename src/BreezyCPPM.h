/*
   Class header for Arduino BreezyCPPM class library

   Copyright (C) 2017 Greg Tomasch and Simon D. Levy

   This file is part of BreezyCPPM.

   BreezyCPPM is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   BreezyCPPM is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with BreezyCPPM.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define PPM_MINPULSE  700
#define PPM_MAXPULSE  2250
#define PPM_SYNCPULSE 7500                                                                                                                       
class BreezyCPPM
{
    public:

        BreezyCPPM(uint8_t pin, uint8_t nchan);

        void begin();

        void computeRC(uint16_t rcData[]);

    private:

        uint8_t _pin;
        uint8_t _nchan;

        static void  isr();
};
